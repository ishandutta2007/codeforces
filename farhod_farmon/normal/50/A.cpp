#include <iostream>
using namespace std;
int main ()
{
int n,m,a=0,b=0,i;
cin>>n>>m;
a=n*m;
for(i=2; i<=a;)
{
a=a-2;
b++;
}
cout<<b;
return 0;
}