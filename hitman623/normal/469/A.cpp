#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
   int i,n,p,q,a[3][100];
   cin>>n;
   cin>>p;
   for(i=0;i<n;++i)
   {a[2][i]=0;
   }
   for(i=0;i<p;++i)
   {
   cin>>a[0][i];
   a[2][a[0][i]-1]=1;
   }
   cin>>q;
   for(i=0;i<q;++i)
   {
   cin>>a[1][i];
   a[2][a[1][i]-1]=1;
   }
   for(i=0;i<n;++i)
  {if(a[2][i]==0) {cout<<"Oh, my keyboard!";
  goto end ; }}
 cout<<"I become the guy.";
 end :
  return 0;
}