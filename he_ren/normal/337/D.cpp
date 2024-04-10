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

bool is[MAXN];

int f[MAXN], g[MAXN];
void upd(int u,int x)
{
	if(x >= f[u]) g[u] = f[u], f[u] = x;
	else if(x > g[u]) g[u] = x;
}

void dfs_up(int u,int fa)
{
	f[u] = g[u] = -inf;
	if(is[u]) f[u] = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		
		dfs_up(v,u);
		if(f[v] != -inf)
			upd(u, f[v] + 1);
	}
}

void dfs_down(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		
		if(f[v] + 1 == f[u]) upd(v, g[u] + 1);
		else upd(v, f[u] + 1);
		
		dfs_down(v,u);
	}
}

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i)
	{
		int u;
		scanf("%d",&u);
		is[u] = 1;
	}
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_up(1,0);
	dfs_down(1,0);
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		if(f[i] <= d) ++ans;
	
	printf("%d",ans);
	return 0;
}