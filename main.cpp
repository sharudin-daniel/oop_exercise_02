#include <iostream>
#include <math.h>

class Budget {		//Описание класса Budget
public:
	double cash, loan;

	void show() {		//Метод отображения объекта
		std::cout << cash << "   " << loan;
	}

	void init(double E, double e) { //Метод инициализации объекта
		cash = E;
		loan = e;
	}

	

};



Budget operator+ (Budget A, Budget B) { // Перегрузка оператора сложения
	Budget res;
	res.cash = A.cash + B.cash;
	res.loan = A.loan + B.loan;

	return (res);
}

Budget operator- (Budget A, Budget B) { // Перегрузка оператора вычитания
	Budget res;
	res.cash = A.cash - B.cash;
	res.loan = A.loan - B.loan;

	return (res);
}

Budget operator* (Budget A, Budget B) { // Перегрузка оператора умножения
	Budget res;
	res.cash = A.cash * B.cash;
	res.loan = A.loan * B.loan;

	return (res);
}

Budget operator/ (Budget A, Budget B) { // Перегрузка оператора деления
	Budget res;
	res.cash = A.cash / B.cash;
	res.loan = A.loan / B.loan;
	res.cash = floor(res.cash * 100) / 100;	//Для округления до двух знаков после запятой
	res.loan = floor(res.loan * 100) / 100;

	return (res);
}

bool operator< (Budget A, Budget B) {	// Перегрузка оператора сравнения
	
	return((A.cash + A.loan) < (B.cash + B.loan));

}

bool operator== (Budget A, Budget B) {	// Перегрузка оператора сравнения

	return((A.cash == B.cash) && (A.loan == B.loan));
}

bool operator> (Budget A, Budget B) {	// Перегрузка оператора сравнения
	
		return((A.cash + A.loan) > (B.cash + B.loan));

}


int main() { // Выводим информацию о программе
	std::cout << "_____________________________________________________" << std::endl; // Краткое описанние программы
	std::cout << "| This programm is created for working with Budgets |" << std::endl;
	std::cout << "| aka (c,l), where c is cash and l is loan.         |" << std::endl;
	std::cout << "|___________________________________________________|" << std::endl;
	std::cout << "|    Enter your sentence, example: 210 45 + 33 50   |\n" << std::endl;
	Budget A, B;
	double E, e;
	char operation;
	std::cin >>  E >> e; // Считываем числовые значения первого объекта
	E = floor(E * 100) / 100;	//Для округления до двух знаков после запятой
	e = floor(e * 100) / 100;
	A.init(E, e);

	std::cin >> operation;
	std::cin >> E >> e;	// Считываем числовые значения второго объекта
	E = floor(E * 100) / 100;	//Для округления до двух знаков после запятой
	e = floor(e * 100) / 100;
	B.init(E, e);
	if (operation == '+') 	std::cout << "\nCash=" << (A + B).cash << "\nLoan=" << (A + B).loan<<"\n";
	else if (operation == '-') 	std::cout << "\nCash=" << (A - B).cash << "\nLoan=" << (A - B).loan << "\n";
	else if (operation == '/') 	std::cout << "\nCash=" << (A / B).cash << "\nLoan=" << (A / B).loan << "\n";
	else if (operation == '*') 	std::cout << "\nCash=" << (A * B).cash << "\nLoan=" << (A * B).loan << "\n";
	else if (operation == '<') {
		if (A < B) std::cout << "\nTrue\n";
		else std::cout << "\nFalse\n";
	}
	else if (operation == '>') {
		if (A > B) std::cout << "\nTrue\n";
		else std::cout << "\nFalse\n";
	}
	else if (operation == '=') {
		if (A == B) std::cout << "\nTrue\n";
		else std::cout << "\nFalse\n";
	}
	else std::cout << "\nInvalid input!\nPlease, try again.";
	
}