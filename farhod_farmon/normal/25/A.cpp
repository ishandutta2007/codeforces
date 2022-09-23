#include <iostream>
using namespace std;
int main ()
{
long long int a,b[1000],k,l,k1,l1,i;
cin>>a;
for(i=1; i<=a; i++)
{
cin>>b[i];
}
for(i=1; i<=a; i++)
{
if(b[i]%2==0){k++; k1=i;}
else {l++; l1=i;}
}
if(k==1){cout<<k1<<endl;}
if(l==1){cout<<l1<<endl;}

return 0;
}