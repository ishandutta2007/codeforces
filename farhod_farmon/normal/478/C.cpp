#include <iostream>
using namespace std;
int main()
{
long long int a,b,c,d=0;
 cin>>a>>b>>c;
a=min(a,(b+c)*2);
b=min(b,(a+c)*2);
c=min(c,(a+b)*2);
cout<<(a+b+c)/3;
 return 0;
}