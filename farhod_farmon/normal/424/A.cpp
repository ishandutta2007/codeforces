#include <iostream>
using namespace std;
int main()
{
int a,i,x=0,X=0;
char d[1000];
cin>>a;
for(i=1; i<=a; i++)
{
cin>>d[i];
}
for(i=1; i<=a; i++)
{
if(d[i]=='x'){x++;}
else {X++;}
}
if(x>X){
x=x-X;
x=x/2;
cout<<x<<endl;
  for(i=1; i<=a; i++)
    {
    if(x!=0 && d[i]=='x'){cout<<'X'; x--;}
    else {cout<<d[i];}

    }
  }
  else{
X=X-x;
X=X/2;
cout<<X<<endl;
  for(i=1; i<=a; i++)
    {
    if(X!=0 && d[i]=='X'){cout<<'x'; X--;}
    else {cout<<d[i];}

    }
  }

}