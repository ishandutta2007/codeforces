#include <iostream>
using namespace std;
int main()
{
long long int a,b;
cin>>a>>b;
if(a%2!=0){
   a++;
 }
if(a+2<=b){
   cout<<a<<" "<<a+1<<" "<<a+2;
 }
else{
   cout<<-1;
 }
return 0;
}