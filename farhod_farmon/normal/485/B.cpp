#include <bits/stdc++.h>
using namespace std;
int main()
{
long long int a,b[100001],c[100001],i,d,v=0;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i]>>c[i];
 }
sort(b+1,b+a+1);
sort(c+1,c+a+1);
cout<<max(b[a]-b[1],c[a]-c[1])*max(b[a]-b[1],c[a]-c[1]);
return 0;
}