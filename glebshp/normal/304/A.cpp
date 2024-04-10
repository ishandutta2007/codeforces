#include <iostream>
#include<math.h>
using namespace std;

double xx[10001];
int main()
{
    double x;
    int x2,c=0,n;
cin>>n;
for(int i=3;i<=n;i++) {
xx[i]=i*i;
for(int j=3;j<=n&&j<=i;j++){
    x=xx[i]+xx[j];
    x=sqrt(x);
        if (static_cast<int>(x) == x){
          //if(x==int(x))  {
        if(n>=x)
        c++;
        else break;
        //,cout<<"---------------\n"
   //cout<<i<<"  "<<j<<"  "<<x<<"\n";
   }}
  }
//cout<<c<<"  "<<c/2<<"\n";
cout<<c;
return 0;
}