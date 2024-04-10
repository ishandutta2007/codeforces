#include <iostream>
using namespace std;
int main ()
{
int a,b,d[100],d1[100],i,f=100,g=0;
cin>>a>>b;
for(i=1; i<=a; i++)
{
cin>>d[i]>>d1[i];
}
for(i=1; i<=a; i++)
{
if((d[i]*100)+d1[i]<=b*100){
  if(d[i]<b){if(d1[i]<f && d1[i]!=0){f=d1[i];}}
  }
 else{g++;}
}
if(g==a){cout<<-1;}
else{cout<<100-f;}
return 0;
}