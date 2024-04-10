#include <iostream>
using namespace std;
int main ()
{
string b;
int a, i,x=0;
cin>>a;
for(i=1; i<=a; i++)
{
cin>>b;
if(b[1]=='-'){x--;}
else {x++;}
}
cout<<x;
return 0;
}