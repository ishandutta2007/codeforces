#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
int a,b,c,d,e,f,h,g,p;
cin>>a>>b>>c>>d>>e>>f>>h>>g;
b=b*c;
b=b/h;
d=d*e;
f=f/g;
p=min(b,min(d,f));
cout<<p/a;
return 0;
}