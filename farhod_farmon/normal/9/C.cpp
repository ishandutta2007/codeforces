#include <iostream>
using namespace std;
int a,b=0;

void rec( int s )
{
    if( s>a )return;
    b++;
    rec(s*10);
    rec(s*10+1);    
}

int main()
{
    cin>>a;
    rec(1);
    cout<<b;
    return 0;
}