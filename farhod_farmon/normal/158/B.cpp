#include <iostream>
using namespace std;
int main ()
{
int a,b,n=0,k1=0,k2=0,k3=0,k4=0,i;
cin>>a;
for(i=1; i<=a; i++)
{
cin>>b;
if(b==4){k4++;}
else if(b==3){k3++;}
else if(b==2){k2++;}
else{k1++;}
}
while(k1!=0 && k3!=0)
{
k3--;
k1--;
n++;
}
n=n+k2/2;
if(k2%2>0){k1=k1+2;}
n=n+k1/4;
if(k1%4>0){n=n+1;}
cout<<k4+n+k3<<endl;
}