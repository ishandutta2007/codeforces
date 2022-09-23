#include <iostream>
using namespace std;
int main ()
{
string a;
int i,x=0,x1=0,y=0,y1=0,f;
cin>>a;
f=a.size();
for(i=0; i<f; i++)
{
if(a[i]=='0'){x++; x1=0;}
if(a[i]=='1'){x1++; x=0;}
if(x>y){y=x;}
if(x1>y1){y1=x1;}
}
if(y>=7 || y1>=7){cout<<"YES";}
else {cout<<"NO";}
return 0;
}