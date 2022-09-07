
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm> //headers i used i this programme..                                        around 5 TEST CASES
using namespace std;

class event   //class name                                            //Test Cases : //when user input the values of intger he may enter a character
	//: in calculation the number of waiters //: in calculat the cost of each waiter
	//: if user enter a -ve intger value or a float ,the programme will catch him
{
private:
	char EventName[100];
	char CustomerName[100];

	int GuestCount;
	float EventDuration;
	int NumberOfWaiters;

	float CostForWaiter;
	float FoodCost;
	float TotalCost;
	float DepositAmount;

public:
	//initialization Values of private members
	event(){
		EventName[100] = '/0';
		CustomerName[100] = '/0';
		GuestCount = 0;
		EventDuration = 0.0;
		NumberOfWaiters = 0;
		CostForWaiter = 0;
		FoodCost = 54.5;
		TotalCost = 0;
		DepositAmount = 0;
	}

	//start set & get EventName
	void setEventName(char name[100]){
		strcpy(EventName, name);
	}
	char* getEventName(){  // * to return  all characers in the array...
		return EventName;
	}
	//end set & get EventName

	//start set & get CustomerName
	void setCustomerName(char name[100]){
		strcpy(CustomerName, name);
	}
	char* getCustomerName(){     // * to return  all characers in the array...
		return CustomerName;
	}
	//end set & getCustomerName

	//start set & get Guest Count
	void setGuestCount(int n){   // we forced the user to enter +ve number in main fun..

		if (n < 0)
			n = 0;
		GuestCount = n;
	}

	int getGuestCount(){
		return GuestCount;
	}


	//start set & get EventDuration
	void setEventDuration(float n){       //float
		EventDuration = n;
	}
	float getEventDuration(){
		return EventDuration;
	}
	//end set & get EventDuration

	int getNumberOfWaiters(){
		return NumberOfWaiters;
	}

	//get CostForWaiter
	float getCostForWaiter(){
		return CostForWaiter;
	}

	float getTotalCost(){
		return TotalCost;
	}

	float getFoodCost(){
		return FoodCost;
	}
	void setDepositAmount(){
		DepositAmount = (0.25) * TotalCost;
	}
	float getDepositAmount(){
		return DepositAmount;
	}
	//start get NumberOfWaiters
	void calcNumberOfWaiters(){
		NumberOfWaiters = 0;
		if (getGuestCount() <= 0){
			NumberOfWaiters = 0;
		}
		else{
			NumberOfWaiters = ceil((float)getGuestCount() / 20); //we use float casting to manage GuestCount test case that less than 20 or greater it
		}
	}

	void calcCostPerWaiter(){//169
		CostForWaiter = 0;
		int hr = getEventDuration() / 60;  // 2
		int min = (int)getEventDuration() % 60;  // casting float duration to intger for %

		if (min <= 46){
			CostForWaiter = hr * 46.5 + min * 1; //142 //   make first hr for 46.5 and the min for 1 ....
		}
		else{
			CostForWaiter = hr * 46.5 + 46.5;
		}

	}
	void calcCostFood(){
		FoodCost = 0;
		if (getGuestCount() <= 0)
			FoodCost = 0;
		else{
			FoodCost = getGuestCount() * 54.5;
		}

	}

	void calcTotalCost(){
		TotalCost = getFoodCost() + getCostForWaiter() * getNumberOfWaiters();
		setDepositAmount();
	}

	void printinfo()
	{

		cout << "---------------------------------------------" << endl;
		cout << getEventName() << "  " << "Event" << endl;
		cout << "Event estimate for " << getCustomerName() << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Number Of Waiters : " << getNumberOfWaiters() << endl;
		cout << "The Cost Pre Waiter : " << getCostForWaiter() << endl;
		cout << "The Cost For Food is : " << getFoodCost() << endl;
		cout << "Total Cost is  : " << getTotalCost() << endl;
		cout << "Please Provide a 25% deposit to reserve the event\n";
		cout << "The deposite nedded is : " << getDepositAmount() << endl;


	}

};

void enterNames(event &e, string type){
	if (type == "event"){
		char eventName[100];
		cout << "Enter Event Name : ";
		cin.getline(eventName, 100);
		e.setEventName(eventName);
	}
	else{
		char customerName[100];
		cout << "Enter customer Name : ";
		cin.getline(customerName, 100);
		e.setCustomerName(customerName);
	}

}

void enterGuest(event &e){
	cout << "\nEnter guest Count : ";
	float guestCount = 0;
	cin >> guestCount;
	while (cin.fail()){
		cout << "Error, Enter Intger number : \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> guestCount;
	}
	for (int i = 0; i < 1; i--) //to make the user enter intger value....
	{


		if (guestCount >(int)guestCount)  // if passed is  float thenthe codition will hold user until  he enter integer number....
		{
			cout << "please , enter an intger value : \n";
			cin >> guestCount;
		}
		else if (guestCount <= 0)
		{
			cout << "please, enter a + ve intger number : \n";
			cin >> guestCount;
		}


		else //

			break;

	}

	e.setGuestCount(guestCount);
}

void enterDurationCount(event &e){
	cout << "\nEnter Duration Count : ";
	float durcount = 0;
	cin >> durcount;
	while (cin.fail()){                                  //    to make user enter a intger value ....
		cout << "Error, Enter Intger number : \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> durcount;
	}
	for (int i = 0; i < 1; i--) //to make the user enter intger value....
	{


		if (durcount>(int)durcount)
		{
			durcount = ceil(durcount);   // if passed is  float thenthe codition will  programme will round it to next integer value....

			break;

			//cin >> durcount;
		}
		else if (durcount <= 0)
		{
			cout << "please, enter a + ve intger number : \n";
			cin >> durcount;
		}


		else //

			break;

	}

	e.setEventDuration(durcount);
}

void doOperations(event &e){  // function to calculate the members....
	e.calcNumberOfWaiters();
	e.calcCostPerWaiter();
	e.calcCostFood();
	e.calcTotalCost();
}

int main()
{
	event e;
	enterNames(e, "event");
	enterNames(e, "customer");

	enterGuest(e);
	enterDurationCount(e);

	doOperations(e);

	e.printinfo();

}
