#include <iostream>
using namespace std;
int main ()
{
    int a, b, c,d=0,d1=0,i;
   cin>>a>>b;
    for(i=1; i<=a; i++)
    {
        cin>>c;
        d=d+c;
        }
         if(d==0){d1=0;}
else if(d>0){for(i=d; i>0; i=i-b){  d1=d1+1; } }   
         else if(d<0){for(i=d; i<0; i=i+b){  d1++; } }  




  
        cout<<d1;
    return 0;
    }