#include <iostream>
using namespace std;
int main ()
{
int a,i,n;
string b[1000];
cin>>a;
for(i=1; i<=a; i++)
{
cin>>b[i];
}
for(i=1; i<=a; i++)
{
n=b[i].size();
if(n>10){cout<<b[i][0]<<n-2<<b[i][n-1]<<endl;}
else {cout<<b[i]<<endl;}
}
return 0;
}