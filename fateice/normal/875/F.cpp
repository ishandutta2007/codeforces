#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,f[200010],g[200010],p;
struct orz
{
	int u,v,w;
}x[200010];
inline bool cmp(orz a,orz b)
{
	return a.w>b.w;
}
inline int fa(int i)
{
	return f[i]==i?i:f[i]=fa(f[i]);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  scanf("%d%d%d",&x[i].u,&x[i].v,&x[i].w);
	sort(x+1,x+m+1,cmp);
	for(i=1;i<=n;i++)
	  f[i]=i;
	for(i=1;i<=m;i++)
	  {
	   j=fa(x[i].u);
	   k=fa(x[i].v);
	   if(j==k)
	     {
	      if(g[j]==0)
	        {
			 g[j]++;
			 p+=x[i].w;
			}
		 }
	   else
	     if(g[j]+g[k]<=1)
	       {
			f[k]=j;
			g[j]+=g[k];
			p+=x[i].w;
		   }
	  }
	printf("%d\n",p);
	return 0;
}