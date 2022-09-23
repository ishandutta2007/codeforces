#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
int a[7],i,c=1,b=1,f,d=1,g=1;
for(i=1; i<=6; i++ ){
   cin>>a[i];
 }
sort(a+1,a+7);
for( i=1; i<=6; i++ ){if(a[i]==a[i+1]){b++;}else{b=1;}if(b>=4){f=a[i];g=b;}}
for( i=1; i<=6; i++ ){if(a[i]==a[i+1] && a[i]!=f){c++;}else{c=1;}if(c>=2){d=c;}}
if(g==6 || g==4 && d==2){cout<<"Elephant";}
else if(g==5 || g==4 && d==1 ){cout<<"Bear";}
else {cout<<"Alien";}
return 0;
}