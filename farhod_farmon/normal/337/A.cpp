#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
int a,b,c[10000],i,d=10000,f,j;
cin>>a>>b;
for( i=1; i<=b; i++ ){
   cin>>c[i];
 }

 sort(1+c,c+b+1);

 for(i=1; i<=b; i++){
    for(j=1; j<=b; j++){
       if(c[i]-c[j]<=d && i!=j && i+(a-1)==j && c[i]-c[j]>=0 || c[i]-c[j]<=d && i!=j && i-(a-1)==j && c[i]-c[j]>=0){
          d=c[i]-c[j];
          f=i;
        }
     }
  }



cout<<c[f]-c[f-(a-1)];

return 0;
}