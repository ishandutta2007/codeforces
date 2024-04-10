#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,p;
L x[10000],y[10000],ax,ay,bx,by,sx,sy,t;
inline int orz(int i,L t)
{
    L tt=t;
    int p=0;
    int j,k=1;
    for(j=i;j<n;j++)
      if(x[j+1]-x[j]+y[j+1]-y[j]<=t)
        t-=x[j+1]-x[j]+y[j+1]-y[j],k++;
      else
        break;
    p=max(p,k);
    k=1;
    t=tt;
    for(j=i-1;j>=0;j--)
      if(x[j+1]-x[j]+y[j+1]-y[j]<=t)
        t-=x[j+1]-x[j]+y[j+1]-y[j],k++;
      else
        break;
    if(j==-1)
    {
    for(j=i-1;j>=0;j--)
      t-=x[i+1]-x[i]+y[i+1]-y[i];
    for(j=i;j<n;j++)
      if(x[j+1]-x[j]+y[j+1]-y[j]<=t)
        t-=x[j+1]-x[j]+y[j+1]-y[j],k++;
      else
        break;
    }
    p=max(p,k);
    return p;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	cin>>x[0]>>y[0]>>ax>>ay>>bx>>by;
	cin>>sx>>sy>>t;
	for(n=1;x[n-1]<=1e18/ax && y[n-1]<=1e18/ay;n++)
	  {
       x[n]=x[n-1]*ax+bx;
       y[n]=y[n-1]*ay+by;
      }
    n--;
    for(i=0;i<=n;i++)
      if(abs(sx-x[i])+abs(sy-y[i])<=t)
        p=max(p,orz(i,t-abs(sx-x[i])-abs(sy-y[i])));
    cout<<p;
	return 0;
}