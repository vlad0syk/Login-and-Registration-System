#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User {
public:
    string Username, Password;
    
    User (string username, string password) : Username (username), Password (password) {}

    static bool userExists(const string& username, const string& password) {
        fstream file;
        file.open("Users.txt", ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line))
            {
                if (line == username + " " + password)
                    return true;
            }
            file.close();
        }

        return false;
    }

    void signUp() {
        if (!userExists(Username, Password)) {
            fstream file;
            file.open("Users.txt", ios::app);
            if (file.is_open()) {
                file << Username << " " << Password << endl;
                cout << "Registration successful!" << endl;
                file.close();
            }
            else
                cout << "Unable to open  file to writing." << endl;   
        }
        else 
            cout << "User already exists." << endl;
    }
};

int main()
{
    int choice;

    cout << "Do you wanna to log in (1) or to sing up (2)? ";
    cin >> choice;

    if (choice == 1) {
        string username, password; 

        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        
        if (User::userExists(username, password))
            cout << "Login successful!" << endl;
        else
            cout << "Login failed. User does not exist or invalid credentials." << endl;
    }
    if (choice == 2) {
        string username, password;

        cout << "Create your own username: ";
        cin >> username;
        cout << "Create your own password: ";
        cin >> password;
        
        User newUser(username, password);
        newUser.signUp();
    }
    
    return 0;
}