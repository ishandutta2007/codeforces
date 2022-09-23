#include <iostream>
using namespace std;
int main ()
{
int i,k,l,m,n,d,f;
cin>>k>>l>>m>>n>>d;
f=d;
for(i=1; i<=d; i++)
{
if(i%k!=0 && i%n!=0 && i%m!=0 && i%l!=0){f--;}
}
cout<<f;
return 0;
}