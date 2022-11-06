#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int nxt[N<<3],to[N<<3],head[N],cnt=1;
int vis[N<<3],deg[N];
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
	nxt[++cnt]=head[v];
	to[cnt]=u;
	head[v]=cnt;
	deg[u]++,deg[v]++;
}
void dfs(int u,int &p)
{
	for(int &i=head[u];i;i=nxt[i])
	if(!vis[i])
	{
		int v=to[i];
		vis[i]=vis[i^1]=true;
		dfs(v,p);
		p^=1;
		if(p) printf("%d %d\n",u,v);
		else printf("%d %d\n",v,u);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	int pre=0,p=m;
	for(int i=1;i<=n;i++)
	if(deg[i]&1){if(pre) add(pre,i),++p,pre=0;else pre=i;}
	if(p&1) add(1,1),++p;
	printf("%d\n",p);
	dfs(1,p=0);
	return 0;
}