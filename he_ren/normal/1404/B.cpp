#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int n,a,b,da,db;

bool dfs_dis(int u,int fa, int dis)
{
	if(u == b) return dis <= da;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		if(dfs_dis(v,u, dis+1)) return 1;
	}
	return 0;
}

int f[MAXN], g[MAXN];

inline void upd(int u,int x)
{
	if(x >= f[u]) g[u] = f[u], f[u] = x;
	else if(x > g[u]) g[u] = x;
}

void dfs_down(int u,int fa)
{
	f[u] = 0; g[u] = -inf;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_down(v,u);
		upd(u, f[v]+1);
	}
}

void dfs_all(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		
		if(f[v]+1 == f[u]) upd(v, g[u]+1);
		else upd(v, f[u]+1);
		
		dfs_all(v,u);
	}
}

void solve(void)
{
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	for(int i=1; i<=n; ++i) head[i] = 0;
	etot = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	if(db <= da){ printf("Alice\n"); return;}
	if(dfs_dis(a,0,0)){ printf("Alice\n"); return;}
	if(db <= 2 * da){ printf("Alice\n"); return;}
	
	dfs_down(1,0);
	dfs_all(1,0);
	
	for(int i=1; i<=n; ++i)
		if(f[i] <= da)
		{
			printf("Alice\n");
			return;
		}
	printf("Bob\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}