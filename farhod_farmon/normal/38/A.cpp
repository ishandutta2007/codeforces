#include <iostream>
using namespace std;
int main()
{
int n,f[10000],a,b,i,j,g=0;
cin>>n;
for( i=1; i<n; i++ ){
   cin>>f[i];
 }
cin>>a>>b;

for( i=a; i<b; i++ ){
   g+=f[i];
 }

cout<<g;

return 0;
}