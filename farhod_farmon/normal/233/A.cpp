#include <iostream>
using namespace std;
int main ()
{
int a,i,b=1;
cin>>a;
if(a%2==0){
 for( i=1; i<=a; i++ ){
   if(b==1){
      cout<<i+1<<" ";
      b=0;
    }
   else if(b==0){
      cout<<i-1<<" ";
      b=1;
    }
 }
 return 0;
 }
cout<<-1;
return 0;
}