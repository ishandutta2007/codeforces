#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a;
    b=a/10;
    c=(a/100)*10+a%10;
    cout<<max(a,max(b,c));
    return 0;
}