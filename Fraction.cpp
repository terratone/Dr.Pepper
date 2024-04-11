#include <iostream>

using namespace std;

/*
Создайте класс Дробь (или используйте уже ранее созданный вами). Используя перегрузку операторов реализуйте
для него арифметические операции для работы с дробями
(операции +, -, *, /).
*/

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw invalid_argument("The numerator can't be zero");
        }
    }

    Fraction operator+(const Fraction& other) {
        int new_denominator = denominator * other.denominator;
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-(const Fraction& other) {
        int new_denominator = denominator * other.denominator;
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator*(const Fraction& other) {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    void print() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {

    setlocale(LC_ALL, "RU");

    Fraction fraction1(3, 4);
    Fraction fraction2(1, 5);

    Fraction sum = fraction1 + fraction2;
    cout << "Sum: ";
    sum.print();

    Fraction difference = fraction1 - fraction2;
    cout << "Difference: ";
    difference.print();

    Fraction multiplication = fraction1 * fraction2;
    cout << "Multiplication: ";
    multiplication.print();

    Fraction division = fraction1 / fraction2;
    cout << "Division: ";
    division.print();

    return 0;
}