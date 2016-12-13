#include <iostream>
#include <conio.h>

using namespace std;

class Linked_List_Queue {
    private: struct node {
        int data;
        node *next;
    };
    node *rear;
    node *entry;
    node *print;
    node *front;

    public: Linked_List_Queue();

    void Delete();
    void Insert();
    void print_list();
    void show_working();
};

Linked_List_Queue::Linked_List_Queue() {
    rear = NULL;
    front = NULL;
}

void Linked_List_Queue::Insert() {
    int num;
    cout << "\n\n\n\n\n\n Masukkan angka dalam Queue : ";cin>>num;

    entry = new node;

    if(rear == NULL) {
        entry->data = num;
        entry->next = NULL;
        rear=entry;
        front=rear;
    } else {
        entry->data = num;
        entry->next = NULL;
        rear->next=entry;
        rear = entry;
    }

    cout << "\n\n\t *** " << num << " Sudah Masuk Queue." << endl;
    cout << "Press any key to return to Menu";
    getch();
}

void Linked_List_Queue::Delete() {
    if(front==NULL) {
        cout << "Error! : Queue is Empty\n"<<endl;
    } else {
        int deleted_element = front->data;
        node *tmp;
        tmp = front;
        front=front->next;

        delete tmp;
        cout << "\n\n\t *** " << deleted_element << " dihapus dari Queue" << endl;
    }
    cout << "Press any key to return to Menu";
    getch();
}

void Linked_List_Queue::print_list() {
    print = front;
    if (print!=NULL) {
        cout << "Angka-angka dalam Queue adalah : \n"<<endl;
    } else {
        cout << "\n\n\n\n\n\n\t *** Tidak ada data yang ditampilkan. "<<endl;
    }

    while(print != NULL) {
        cout << "\t " << print->data << endl;
        print = print->next;
    }

    cout << "Press any key to return to Menu";
    getch();
}

void Linked_List_Queue::show_working() {
    char Key = NULL;
    do {
        cout << "********** QUEUE **********\n"<<endl;
        cout << "Pilih salah satu menu : "<<endl;
        cout << "\t - Press \'I\' to Masukkan data dalam Queue"<<endl;
        cout << "\t - Press \'D\' to Hapus data dalam Queue"<<endl;
        cout << "\t - Press \'P\' to Tampilkan data dalam Queue"<<endl;
        cout << "\t - Press \'E\' to Exit"<<endl;

        Input:
            cout<<"\n\n Masukkan Pilihan"<<endl;

            Key=getche();

            if(int(Key)== 27 || Key == 'e' || Key == 'E') {
                break;
            } else if(Key == 'i' || Key == 'I') {
                Insert();
            } else if(Key == 'd' || Key == 'D') {
                Delete();
            } else if(Key == 'p' || Key == 'P') {
                print_list();
            } else {
                goto Input;
            }
    } while(1);
}

int main()
{
    Linked_List_Queue obj;
    obj.show_working();

    return 0;
}
