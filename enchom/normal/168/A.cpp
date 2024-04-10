#include <iostream>
using namespace std;
int main()
{
    int n,x,y;
    int people;
    cin>>n>>x>>y;
    people=n*y;
    if (people%100==0)
    {
        people=people/100;
    }
    else
    {
        people=people/100+1;
    }
    people=people-x;
    if (people>=0)
    cout<<people<<endl;
    else
    cout<<0<<endl;
    return 0;
}