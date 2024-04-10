#include <iostream>
using namespace std;
int main()
{
 int a,b,c,d,e;
 cin>>a>>b>>c>>d>>e;
 if((a+c+b+d+e)%5==0 && (a+b+c+d+e)>0){cout<<(a+b+c+d+e)/5<<endl;}
 else {cout<<-1<<endl;}
 return 0;
}