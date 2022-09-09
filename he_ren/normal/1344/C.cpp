#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Edge
{
	int next,from,to;
}e[MAXM];
int head[MAXN],etot=0,deg[MAXN];
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],u,v};
	head[u]=etot;
	++deg[v];
}

int n;

bool vis[MAXN],ins[MAXN];
void dfs_cir(int u)
{
	vis[u]=ins[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(ins[v]) printf("-1"), exit(0);
		if(!vis[v]) dfs_cir(v);
	}
	ins[u]=0;
}

int f[MAXN],g[MAXN];

void bfs_f(void)
{
	static queue<int> q;
	
	for(int i=1; i<=n; ++i) f[i] = i;
	for(int i=1; i<=n; ++i)
		if(!deg[i]) q.push(i);
	
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			chk_min(f[v], f[u]);
			--deg[v];
			if(!deg[v]) q.push(v);
		}
	}
}

void dfs_g(int u)
{
	g[u] = u;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(!g[v]) dfs_g(v);
		chk_min(g[u], g[v]);
	}
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	
	for(int i=1; i<=n; ++i)
		if(!vis[i]) dfs_cir(i);
	
	bfs_f();
	for(int i=1; i<=n; ++i)
		if(!g[i]) dfs_g(i);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(i==f[i] && i==g[i]) ++ans;
	
	printf("%d\n",ans);
	for(int i=1; i<=n; ++i)
	{
		if(i==f[i] && i==g[i]) putchar('A');
		else putchar('E');
	}
	return 0;
}