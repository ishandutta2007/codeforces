#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,x[300010],g[300010],h[300010],w[300010],p;
L f[300010];
inline void orz(int i)
{
    int k=min(x[i],x[i+1]);
    if(k)
      {
       w[++p]=i;
       x[i]-=k;
       x[i+1]-=k;
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	f[1]=2*x[1];
	g[1]=1;
	f[2]=2*x[2];
	g[2]=1;
	for(i=3;i<=n;i++)
	  if(f[i-2]+2*x[i]<f[i-3]+2*max(x[i],x[i-1]))
	    {
         f[i]=f[i-2]+2*x[i];
         g[i]=1;
        }
      else
	    {
         f[i]=f[i-3]+2*max(x[i],x[i-1]);
         g[i]=2;
        }
    for(i=(f[n]<f[n-1]?n:(n-1));i>0;i-=g[i]+1)
      h[i]=h[i-g[i]+1]=1;
    for(i=1;i<=n;i++)
      if(h[i]==1 && h[i+1]==1)
        orz(i);
    for(i=1;i<=n;i++)
      if(h[i]==1)
        orz(i-1),orz(i);
    printf("%d\n",p);
    for(i=1;i<=p;i++)
      printf("%d\n",w[i]);
	return 0;
}