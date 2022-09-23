#include <iostream>
using namespace std;
int main ()
{
string a;
int b=0,c=0,i;
cin>>a;
for(i=0; i<a.size(); i++)
{
if(a[i]!='A' && a[i]!='O' && a[i]!='Y' && a[i]!='E' && a[i]!='U' && a[i]!='I' && a[i]!='a' && a[i]!='o' && a[i]!='y' && a[i]!='e' && a[i]!='u' && a[i]!='i')
{
if(a[i]>=97){b=int(a[i]); cout<<"."<<char(b);}
else {b=int(a[i])+32; cout<<"."<<char(b);}
}
}
cout<<endl;
return 0;
}