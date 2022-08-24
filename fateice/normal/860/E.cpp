#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define L long long
using namespace std;
int n,x[500010],w[500010],g[500010],h[500010],p;
L f[500010],ans[500010];
vector<int> a[500010];
vector<L> b[500010];
inline void dfs(int i,int j)
{
	int k;
	for(k=0;k<a[i].size();k++)
	  if(a[i][k]!=j)
	    {
		 g[a[i][k]]=g[i]+1;
	     dfs(a[i][k],i);
	     h[i]=max(h[i],h[a[i][k]]+1);
		}
}
inline void dfs2(int i,int j)
{
	int k,l,u,v=0;
	x[i]=++p;
	b[i].push_back(0);
	for(k=0;k<a[i].size();k++)
	  if(a[i][k]!=j && h[a[i][k]]==h[i]-1)
	    {
	     dfs2(a[i][k],i);
	     break;
		}
	for(l=0;l<a[i].size();l++)
	  if(a[i][l]!=j && k!=l)
	    {
	     dfs2(a[i][l],i);
	     v=max(v,h[a[i][l]]);
		}
	for(l=0;l<a[i].size();l++)
	  if(a[i][l]!=j)
	    {
	     int e=a[i][l];
	     for(u=0;u<=h[e] && u<=v;u++)
	       {
	   	    if(b[i].size()<=u+1)
	   	      b[i].push_back((L)w[x[e]+u]*(g[i]+1));
	   	    else
	   	      b[i][u+1]+=(L)w[x[e]+u]*(g[i]+1);
	   	    if(b[e].size()<=u)
	   	      b[e].push_back(-(L)w[x[e]+u]*(g[i]+1));
	   	    else
	   	      b[e][u]-=(L)w[x[e]+u]*(g[i]+1);
		   }
		}
	for(l=0;l<a[i].size();l++)
	  if(a[i][l]!=j && k!=l)
	    {
	     int e=a[i][l];
	     for(u=0;u<=h[e];u++)
	       w[x[i]+u+1]+=w[x[e]+u];
		}
	w[x[i]]=1;
	b[i][0]+=g[i];
}
inline void add(int i,L k)
{
	for(;i<=n;i+=i&-i)
	  f[i]+=k;
}
inline L sum(int i)
{
	L k=0;
	for(;i>0;i^=i&-i)
	  k+=f[i];
	return k;
}
inline void dfs3(int i,int j)
{
	int k;
	for(k=0;k<b[i].size();k++)
	  add(g[i]+1+k,b[i][k]);
	ans[i]=sum(g[i]+1);
	for(k=0;k<a[i].size();k++)
	  if(a[i][k]!=j)
	    dfs3(a[i][k],i);
	for(k=0;k<b[i].size();k++)
	  add(g[i]+1+k,-b[i][k]);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&j);
	   a[j].push_back(i);
	  }
	dfs(a[0][0],0);
	dfs2(a[0][0],0);
	dfs3(a[0][0],0);
	for(i=1;i<=n;i++)
	  printf("%I64d ",ans[i]);
	return 0;
}