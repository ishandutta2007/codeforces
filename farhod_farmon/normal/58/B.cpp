#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a,b=2,i;
    cin>>a;
    cout<<a<<" ";
    while( b<=a ){
           if( a%b==0 ){
               cout<<a/b<<" ";
               a/=b;
               b=2;    
           }       
           else b++;
    }
    return 0;
}