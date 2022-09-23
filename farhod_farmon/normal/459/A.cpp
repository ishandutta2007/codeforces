#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
long long int a1,a2,a3,a4,b1,b2,b3,b4;
cin>>a1>>b1>>a2>>b2;
if(a1==a2){
   a3=b2-b1+a2;
   a4=b2-b1+a2;
   b3=b1;
   b4=b2;
 }
else if(b1==b2){
   b3=a2-a1+b2;
   b4=a2-a1+b2;
   a3=a1;
   a4=a2;
 }
else if(abs(a2-a1)==abs(b2-b1)){
   cout<<a1<<" "<<b2<<" "<<a2<<" "<<b1;
   return 0;
 }
else{
   cout<<-1;
   return 0;
 }
cout<<a4<<" "<<b4<<" "<<a3<<" "<<b3;
return 0;
}