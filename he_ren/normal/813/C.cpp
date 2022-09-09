#include<cstdio>
const int MAXN = 2e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Edge
{
	int next,to;
}e[MAXN*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int fa[MAXN],dep[MAXN];
inline void dfs(int u)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		fa[v]=u; dep[v]=dep[u]+1;
		dfs(v);
	}
}

int ans=0;
inline void dfs2(int u)
{
	chk_max(ans,dep[u]);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		dfs2(v);
	}
}

int main(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs(1);
	int u=x;
	while(dep[x]-dep[fa[u]] < dep[fa[u]]) u=fa[u];
	dfs2(u);
	
	printf("%d",ans*2);
	return 0;
}