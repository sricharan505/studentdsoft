/* this is a software for storing student details such as
* name,id,age,class,marks,performane description.
* here we use nodes to store the details.
*/

#include <iostream>
#include <string>
using namespace std;
class node
{
public:
	string name;     
	int id{};        //"{}"this is added to remove node::name uninitialized type error
	int age{};
	int sclass{};
	int marks{};
	string des;
	node* next{};
	node* pre{};
	node(){};       //this is added to remove node::name uninitialized type error

};
class studentlist
{
private:
	node* first=NULL;
	node* last=NULL;
public:
	void studentdetails();

	void addstudent();
	void addmulstudents();
	void displaylist();
};

void studentlist::studentdetails()
{
	first = nullptr;
	last = first;
	while (1)
	{
		int in;
		cout << "press 1 to add a student to the list" << endl;
		cout << "press 2 to add more than one student to the list" << endl;
		cout << "press 3 to display the entrire studentlist" << endl;
		cout<< "press 0 to quit" << endl;
		cin >> in;
		if (in == 0)
			break;
		switch (in)
		{
			case 1:addstudent(); break;
			case 2:addmulstudents(); break;
			case 3:displaylist(); break;
			default:break;
		}

	}
}
void studentlist:: addstudent()
{
	node* temp = new node;
	//char* temps{};
	//temp = NULL;
	cout << "enter the student id " << endl;
	cin >> temp->id;
	cout << "enter the student name "<<endl;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
	getline(cin.ignore(), temp->name);          //added ".ignore" to ignore the \n from the pervious code line,if not done it will take
	//cin >> temp->name;								old'\n' as input and finish getline function before taking new input				
	cout << "enter the student age "<<endl;
	cin >> temp->age;
	cout << "enter the class the student is studying in "<<endl;
	cin >> temp->sclass;
	cout << "enter the marks or percentage obtained by the student "<<endl;
	cin >> temp->marks;
	cout << "enter the other details about the student "<<endl;
	//cin >> temp->des;
	getline(cin.ignore(), temp->des);  //https://stackoverflow.com/questions/21567291/why-does-stdgetline-skip-input-after-a-formatted-extraction
	


	if (first == 0)
	{
		first = temp;
		first->pre = nullptr;
		first->next = nullptr;
		last = first;
		last->pre = first;

	}
	else
	{
		last->next = temp;
		temp->pre = last;
		last = temp;
		last->next = nullptr;
	}

}
void studentlist::addmulstudents()
{
	int n,i;
	cout << "enter the number of student details you want to enter" << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		addstudent();
	}
}
void studentlist::displaylist()
{
	node *temp = new node;
	temp = first;
	if (temp == 0)
	{
		cout << "no records to display,please enter the details first" << endl<<endl<<endl;
		return;
	}
	while (1)
	{
		cout << "ID:--------------" << temp->id << endl;
		cout << "NAME:------------" << temp->name << endl;
		cout << "AGE:-------------" << temp->age << endl;
		cout<< "CURRENT CLASS:----" << temp->sclass << endl;
		cout << "MARKS OBTAINED:--" << temp->marks << endl;
		cout<< "OTHER DETAILS:----" << temp->des << endl<<endl;
		if (temp->next == 0)
			break;
		temp = temp->next;
		
	}


}
int main()
{
   cout << "welcome to studentsoft\n";
   studentlist s;
   s.studentdetails();
}


