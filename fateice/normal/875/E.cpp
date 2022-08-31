#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,x[100010],w[100010],f[100010][25],g[100010][25],u[100010],l,r;
inline int minn(int l,int r)
{
	int k=u[r-l+1];
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
inline int maxx(int l,int r)
{
	int k=u[r-l+1];
	return max(g[l][k],g[r-(1<<k)+1][k]);
}
inline bool check(int p)
{
	int i,k,l,r,m,a,b;
	for(i=1;i<=n;i++)
	  {
	   for(l=i,r=n;l<r;)
	     {
		  m=(l+r+1>>1);
		  a=minn(i,m);
		  b=maxx(i,m);
		  if(a>=x[i]-p && b<=x[i]+p)
		    l=m;
		  else
		    r=m-1;
		 }
	   w[i]=l;
	  }
	for(i=3,k=max(w[1],w[2]);i<=k;i++)
	  k=max(k,w[i]);
	return i>n;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	n+=2;
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=n;i>0;i--)
	  {
	   f[i][0]=g[i][0]=x[i];
	   for(j=1;j<=20;j++)
	     {
		  f[i][j]=min(f[i][j-1],f[min(i+(1<<j-1),n)][j-1]);
		  g[i][j]=max(g[i][j-1],g[min(i+(1<<j-1),n)][j-1]);
		 }
	  }
	for(i=2;i<=n;i++)
	  u[i]=u[i>>1]+1;
	for(l=abs(x[1]-x[2]),r=1000000000;l<r;)
	  if(check(l+r>>1))
	    r=(l+r>>1);
	  else
	    l=(l+r>>1)+1;
	printf("%d\n",l);
	return 0;
}