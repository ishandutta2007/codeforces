#include <iostream>
using namespace std;
int main ()
{
 int i,b=0,a,d=0,f;
 cin>>a;
 f=a;

 while(a>0){
   if(a%10 == 4 || a%10 == 7){b++;}
   a=a/10;
   d++;
   }
   if(b == d || f%4==0 || f%7==0 || f%47==0 || f%74==0){
     cout<<"YES";
     }
     else{
       cout<<"NO";
       }
 return 0;
}