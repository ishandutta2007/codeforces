#include <iostream>
using namespace std;
int main()
{
long long a;
cin>>a;
if(a%2==0){
   a=a/2;
 }
else{
   a=a/2+1;
   a=a*(-1);
 }
cout<<a;
return 0;
}