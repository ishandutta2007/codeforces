#include <iostream>
using namespace std;
int main ()
{
int a,b1,b2,c,d,f,sum=0;
cin>>a>>b1>>c>>b2;
d=min(c*b1,b2);
f=a/b1;
sum+=f*d;
sum+=min((a%b1)*c,b2);
cout<<sum;
return 0;
}