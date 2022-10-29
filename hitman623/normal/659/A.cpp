#include <iostream>
#include<math.h>
using namespace std;

int main()
{
   int n,a,b;
   cin>>n>>a>>b;
   int m=fabs(a+b);
   m%=n;
   if(a+b<0) cout<<n-m;
   else cout<<m+n*(!m);
    return 0;
}