#include <iostream>
using namespace std;
int main ()
{
int a[1000],b,c,d=0,d0=0;
cin>>b>>c;
for(int i=1; i<=b; i++)
{
cin>>a[i];
}
    for(int i=1; i<=b; i++)
    {
    if(a[i]==0){d0=d0+1;}
    if(a[c]==0)
    {
    if(a[c]<a[i]){d++;}
    }
    else if(a[c]<=a[i]){d++;}
    }
    if(d0==b){cout<<"0";}
    else {cout<<d;}
return 0;
}