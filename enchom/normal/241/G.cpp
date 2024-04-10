#include <iostream>
using namespace std;
typedef long long Int;

int main()
{
    Int i;
    Int currradii=300;
    Int lastradii=0;
    Int lastplace=455000;
    
    cout<<302<<endl;
    
    cout<<"0 500302"<<endl;
    for (i=1;i<=300;i++)
    {
        cout<<lastplace+lastradii*2-1<<" "<<currradii<<endl;
        lastplace+=lastradii*2-1;
        lastradii=currradii;
        currradii--;
    }
    cout<<"1000000 1000000"<<endl;
    return 0;
}