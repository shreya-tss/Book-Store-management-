#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author, title, publisher;
    float price;
    int stock;

public:
    Book() {
        price = 0.0;
        stock = 0;
    }

    void feedData();
    void editData();
    void showData() const;
    bool search(const string& titleSearch, const string& authorSearch) const;
    void buyBook();
};

void Book::feedData() {
    cin.ignore();
    cout << "\nEnter Author Name: ";
    getline(cin, author);
    cout << "Enter Title Name: ";
    getline(cin, title);
    cout << "Enter Publisher Name: ";
    getline(cin, publisher);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Stock Position: ";
    cin >> stock;
}

void Book::editData() {
    cin.ignore();
    cout << "\nEnter New Author Name: ";
    getline(cin, author);
    cout << "Enter New Title Name: ";
    getline(cin, title);
    cout << "Enter New Publisher Name: ";
    getline(cin, publisher);
    cout << "Enter New Price: ";
    cin >> price;
    cout << "Enter New Stock Position: ";
    cin >> stock;
}

void Book::showData() const {
    cout << "\nAuthor Name: " << author;
    cout << "\nTitle Name: " << title;
    cout << "\nPublisher Name: " << publisher;
    cout << "\nPrice: Rs. " << price;
    cout << "\nStock Position: " << stock << endl;
}

bool Book::search(const string& titleSearch, const string& authorSearch) const {
    return (title == titleSearch && author == authorSearch);
}

void Book::buyBook() {
    int count;
    cout << "\nEnter Number Of Books to buy: ";
    cin >> count;
    if (count <= stock) {
        stock -= count;
        cout << "\nBooks Bought Successfully";
        cout << "\nAmount: Rs. " << price * count << endl;
    } else {
        cout << "\nRequired Copies not in Stock\n";
    }
}

int main() {
    Book* books[20];
    int bookCount = 0;
    int choice;
    string titleSearch, authorSearch;

    while (true) {
        cout << "\n\n\t\tMENU"
             << "\n1. Entry of New Book"
             << "\n2. Buy Book"
             << "\n3. Search For Book"
             << "\n4. Edit Details Of Book"
             << "\n5. Exit"
             << "\n\nEnter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (bookCount < 20) {
                    books[bookCount] = new Book();
                    books[bookCount]->feedData();
                    bookCount++;
                } else {
                    cout << "\nBook storage is full!";
                }
                break;

            case 2:
                cin.ignore();
                cout << "\nEnter Title Of Book: ";
                getline(cin, titleSearch);
                cout << "Enter Author Of Book: ";
                getline(cin, authorSearch);
                {
                    bool found = false;
                    for (int i = 0; i < bookCount; i++) {
                        if (books[i]->search(titleSearch, authorSearch)) {
                            books[i]->buyBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "\nThis Book is Not in Stock";
                }
                break;

            case 3:
                cin.ignore();
                cout << "\nEnter Title Of Book: ";
                getline(cin, titleSearch);
                cout << "Enter Author Of Book: ";
                getline(cin, authorSearch);
                {
                    bool found = false;
                    for (int i = 0; i < bookCount; i++) {
                        if (books[i]->search(titleSearch, authorSearch)) {
                            cout << "\nBook Found Successfully";
                            books[i]->showData();
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "\nThis Book is Not in Stock";
                }
                break;

            case 4:
                cin.ignore();
                cout << "\nEnter Title Of Book: ";
                getline(cin, titleSearch);
                cout << "Enter Author Of Book: ";
                getline(cin, authorSearch);
                {
                    bool found = false;
                    for (int i = 0; i < bookCount; i++) {
                        if (books[i]->search(titleSearch, authorSearch)) {
                            cout << "\nBook Found Successfully";
                            books[i]->editData();
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "\nThis Book is Not in Stock";
                }
                break;

            case 5:
                // Free allocated memory
                for (int i = 0; i < bookCount; i++) {
                    delete books[i];
                }
                return 0;

            default:
                cout << "\nInvalid Choice Entered\n";
        }
    }

    return 0;
}
