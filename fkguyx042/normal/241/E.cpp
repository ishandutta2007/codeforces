#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 10005
using namespace std;
int i,j,m,n,p,k,go[N],Go[N];
int dis[N];
struct Node{int u,v;}b[N];
void dfs1(int x)
{
	 int i;
	 if (go[x]) return; go[x]=1;
	 for (i=1;i<=m;++i) if (b[i].u==x) dfs1(b[i].v);
}
void dfs2(int x)
{
	 int i;
	 if (Go[x]) return; Go[x]=1;
	 for (i=1;i<=m;++i) if (b[i].v==x) dfs2(b[i].u);
}
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=m;++i) scanf("%d%d",&b[i].u,&b[i].v);
	 dfs1(1); dfs2(n);
	 for (i=1;i<=10000;++i)
	     for (j=1;j<=m;++j)
	       if (go[b[j].u]&&Go[b[j].v])
	        dis[b[j].v]=min(dis[b[j].u]+2,dis[b[j].v]),
	        dis[b[j].u]=min(dis[b[j].v]-1,dis[b[j].u]);
	for (i=1;i<=m;++i)
	  if (go[b[i].u]&&Go[b[i].v]&&(dis[b[i].u]>dis[b[i].v]-1||dis[b[i].v]>dis[b[i].u]+2)) 
	  {
	  	 puts("No");
	  	 return 0;
	  }
	printf("Yes\n");
	for (i=1;i<=m;++i)
	 printf("%d\n",max(1,min(2,dis[b[i].v]-dis[b[i].u]))); 
}