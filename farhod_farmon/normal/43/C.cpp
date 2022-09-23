#include <iostream>
using namespace std;
int main()
{
    int a,b,c=0,d=0,f=0,i;
    cin>>a;
    for( i=1; i<=a; i++ ){
         cin>>b;
         if( b%3==1 )c++;
         else if( b%3==2 )d++;
         else f++;     
    }
    cout<<min( c, d )+f/2;
    return 0;
}