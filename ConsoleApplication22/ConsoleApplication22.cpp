#include <iostream>
#include <string>
using namespace std;

class Passport {
public:
    Passport() : firstName_(""), lastName_(""), birthDate_(""), passportNumber_("") {}
    Passport(string firstName, string lastName, string birthDate, string passportNumber) {
        setFirstName(firstName);
        setLastName(lastName);
        setBirthDate(birthDate);
        setPassportNumber(passportNumber);
    }

    string getFirstName() const {
        return firstName_;
    }

    string getLastName() const {
        return lastName_;
    }

    string getBirthDate() const {
        return birthDate_;
    }

    string getPassportNumber() const {
        return passportNumber_;
    }

    void setFirstName(string firstName) {
        firstName_ = firstName;
    }

    void setLastName(string lastName) {
        lastName_ = lastName;
    }

    void setBirthDate(string birthDate) {
        birthDate_ = birthDate;
    }

    void setPassportNumber(string passportNumber) {
        passportNumber_ = passportNumber;
    }

private:
    string firstName_;
    string lastName_;
    string birthDate_;
    string passportNumber_;
};

class ForeignPassport : public Passport {
public:
    ForeignPassport(string firstName, string lastName, string birthDate, string passportNumber, string* visas, int numVisas) {
        setFirstName(firstName);
        setLastName(lastName);
        setBirthDate(birthDate);
        setPassportNumber(passportNumber);
        setVisas(visas, numVisas);
    }

    string* getVisas() const {
        return visas_;
    }

    int getNumVisas() const {
        return numVisas_;
    }

    void setVisas(string* visas, int numVisas) {
        visas_ = new string[numVisas];
        for (int i = 0; i < numVisas; i++) {
            visas_[i] = visas[i];
        }
        numVisas_ = numVisas;
    }

private:
    string* visas_;
    int numVisas_;
};

int main() {
    setlocale(LC_ALL, "russian");
    Passport p("Иван", "Иванов", "12.12.1990", "AB123456");
    string visas[] = { "USA", "Canada", "Germany" };
    ForeignPassport fp("Петр", "Петров", "01.01.1980", "CD654321", visas, 3);

    cout << "Паспорт гражданина Украины: " << endl;
    cout << "Имя: " << p.getFirstName() << endl;
    cout << "Фамилия: " << p.getLastName() << endl;
    cout << "Дата рождения: " << p.getBirthDate() << endl;
    cout << "Номер паспорта: " << p.getPassportNumber() << endl;

    cout << "Загранпаспорт гражданина Украины: " << endl;
    cout << "Имя: " << fp.getFirstName() << endl;
    cout << "Фамилия: " << fp.getLastName() << endl;
    cout << "Дата рождения: " << fp.getBirthDate() << endl;
    cout << "Номер паспорта: " << fp.getPassportNumber() << endl;
    cout << "Визы: " << endl;
    for (int i = 0; i < fp.getNumVisas(); i++) {
        cout << " - " << fp.getVisas()[i] << endl;
    }

    return 0;
}