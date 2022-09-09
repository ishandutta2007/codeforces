#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
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

int f[MAXN];
void dfs_f(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		
		dfs_f(v,u);
		f[u] += f[v] + !(i&1);
	}
}

int g[MAXN];
void dfs_g(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		
		if(i&1) g[v] = g[u] + 1;
		else g[v] = g[u] - 1;
		dfs_g(v,u);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_f(1,0);
	
	g[1] = f[1];
	dfs_g(1,0);
	
	int mn = inf;
	for(int i=1; i<=n; ++i)
		mn = min(mn, g[i]);
	
	printf("%d\n",mn);
	for(int i=1; i<=n; ++i)
		if(g[i] == mn) printf("%d ",i);
	return 0;
}