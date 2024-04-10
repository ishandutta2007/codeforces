#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
const int inf=1000000010;
int n,m,q,u[1000010],v[1000010],w[1000010],f[500010][25],g[500010][25],h[500010],fa[500010],t;
vi a[500010];
L p;
inline int ff(int i)
{
    return fa[i]==i?i:fa[i]=ff(fa[i]);
}
inline void unit(int i,int j)
{
    fa[ff(i)]=ff(j);
    a[i].pb(j);
    a[j].pb(i);
}
inline void dfs(int i)
{
    int j;
    g[i][0]=inf;
    for(j=1;j<=20;j++)
      f[i][j]=f[f[i][j-1]][j-1],g[i][j]=inf;
    for(auto j:a[i])
      if(j!=f[i][0])
        {
         f[j][0]=i;
         h[j]=h[i]+1;
         dfs(j);
        }
}
inline void dfs2(int i)
{
    int j;
    for(auto j:a[i])
      if(j!=f[i][0])
        dfs2(j);
    for(j=20;j>0;j--)
      {
       g[i][j-1]=min(g[i][j-1],g[i][j]);
       g[f[i][j-1]][j-1]=min(g[f[i][j-1]][j-1],g[i][j]);
      }
    if(i>1)
    if(g[i][0]==inf)
      t=1;
    else
      p+=g[i][0];
}
inline void lca(int i,int j,int w)
{
    int k;
    if(h[i]<h[j])
      swap(i,j);
    for(k=20;k>=0;k--)
      if(h[i]-(1<<k)>=h[j])
        {
         g[i][k]=min(g[i][k],w);
         i=f[i][k];
        }
    if(i==j)
      return;
    for(k=20;k>=0;k--)
      if(f[i][k]!=f[j][k])
        {
         g[i][k]=min(g[i][k],w);
         g[j][k]=min(g[j][k],w);
         i=f[i][k];
         j=f[j][k];
        }
    g[i][0]=min(g[i][0],w);
    g[j][0]=min(g[j][0],w);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;i++)
	  scanf("%d%d",&u[i],&v[i]);
	for(;i<=m+q;i++)
	  scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for(i=1;i<=n;i++)
	  fa[i]=i;
	for(i=1;i<=m;i++)
	  unit(u[i],v[i]);
	for(;i<=m+q;i++)
	  if(ff(u[i])!=ff(v[i]))
	    {
         unit(u[i],v[i]);
         p-=w[i];
        }
    dfs(1);
    for(i=m+1;i<=m+q;i++)
      lca(u[i],v[i],w[i]);
    dfs2(1);
    if(t)
      cout<<-1;
    else
      cout<<p;
	return 0;
}