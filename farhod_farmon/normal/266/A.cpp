#include <iostream>
using namespace std;
int main ()
{
int a,i,c=0;
string b;
cin>>a>>b;
for(i=0; i<b.size(); i++)
{
if(b[i]==b[i+1]){c++;}
}
cout<<c;
return 0;
}