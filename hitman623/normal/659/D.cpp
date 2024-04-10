#include <iostream>
using namespace std;
int main()
{
  int n,x[1000],y[1000],i,c=0,dx,dy;
  cin>>n;
  for(i=0;i<=n;++i)
    cin>>x[i]>>y[i];
  for(i=0;i<=n-2;++i)
  {
     dx=x[i+1]-x[i];
     dy=y[i+1]-y[i];
     if(dx<0)
     {
         if(y[i+2]-y[i+1]<0) c++;
     }
     else if(dx>0)
     {
         if(y[i+2]-y[i+1]>0) c++;
     }
     if(dy<0)
     {
         if(x[i+2]-x[i+1]>0) c++;
     }
     else if(dy>0)
     {
         if(x[i+2]-x[i+1]<0) c++;
     }
  }
  cout<<c;
  return 0;
}