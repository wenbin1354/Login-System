#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn() {
	string username, password, un, pw;

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	ifstream read("c:\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);
	if (un == username && pw == password) {
		return true;
	}
	else
		return false;
}

int main() {
	int choice;
	cout << "1: Register \n2: Login\nYour choice: ";
	cin >> choice;
	if (choice == 1) {
		string username, password;
		cout << "Create a username: ";
		cin >> username;
		cout << "Create a password: ";
		cin >> password;

		ofstream file;
		file.open("c:\\" + username + ".txt");
		file << username << endl << password;
		file.close();
		main();
	}

	else if (choice == 2) {
		bool status = IsLoggedIn();
		if (!status) {
			cout << "Incorrect password or username\n";
			system("PAUSE");
			return 0;
		}
		else {
			cout << "Successfully logged in\n";
			system("PAUSE");
			return 0;
		}
	}

	else {
		cout << "Please enter a valid choice\n";
		main();
	}
		
	

}