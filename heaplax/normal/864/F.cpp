#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 3001
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
char ch;void re(int& x)
{
	while(ch=getchar(),ch<33);x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
}
using namespace std;
int n,m,q,p[13];
short cnt,head[N],nxt[N],to[N];
bool vis[N],go[N][N];
struct tree
{
	short dep[N],fa[N][12];
	bool cir[N];
	void dfs(int u)	
	{
		vis[u]=1;
		for(int i=1;p[i]<dep[u];++i)
			fa[u][i]=fa[fa[u][i-1]][i-1];
		for(int i=head[u],v;i;i=nxt[i])
			if(!vis[v=to[i]])
			{
				fa[v][0]=u;
				dep[v]=dep[u]+1;
				dfs(v);
			}
	}
	void dfs2(int u,bool fuck)
	{
		vis[u]=1;
		cir[u]=fuck;
		int mn=N;
		for(int i=head[u],v;i;i=nxt[i])
			if(go[v=to[i]][u])
				mn=min(mn,v);
		for(int i=head[u],v;i;i=nxt[i])
			if(!vis[v=to[i]])
				dfs2(v,fuck||v>mn);
	}
	int ask(int u,int k)
	{
		if(dep[u]<k || cir[u])return -1;
		k=dep[u]-k;
		for(int i=0;p[i]<=k;++i)
			if(k&p[i])	
				u=fa[u][i];
		if(k&(p[11]<<1))
			u=fa[fa[u][11]][11];
		return u;
	}
}w[N];
struct edge
{
	int u,v;
	bool operator < (const edge& a)const
	{
		return v>a.v;
	}
}e[N];
int main()
{
	p[12]=N*N;
	re(n),re(m),re(q);
	for(int i=1,u,v;i<=m;++i)
		re(e[i].u),re(e[i].v);
	sort(e+1,e+m+1);
	for(int i=1;i<=m;++i)
		add_edge(e[i].u,e[i].v);
	for(int i=0;i<12;++i)p[i]=1<<i;
	for(int i=1;i<=n;++i)
	{
		w[i].dep[i]=1;
		memset(vis,0,sizeof vis);
		w[i].dfs(i);
		memcpy(go[i],vis,sizeof vis);
	}
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof vis);
		w[i].dfs2(i,0);
	}
	for(int s,t,k;q--;)
	{
		re(s),re(t),re(k);
		printf("%d\n",w[s].ask(t,k));
	}
}