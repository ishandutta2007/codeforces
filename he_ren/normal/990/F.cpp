#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

struct DSU
{
	int fa[MAXN];
	inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
	int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
	inline void connect(int u,int v){ fa[find(u)] = find(v);}
}dsu;

struct Edge
{
	int next,to, id;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int id)
{
	e[++etot] = (Edge){ head[u],v,id};
	head[u] = etot;
}

struct Edge_uv
{
	int u,v;
};

int a[MAXN];
Edge_uv ee[MAXM];

ll f[MAXM], sum[MAXN];
void dfs_sum(int u,int fa)
{
	sum[u] = a[u];
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_sum(v,u);
		
		if(i&1) f[e[i].id] = sum[v];
		else f[e[i].id] = -sum[v];
		
		sum[u] += sum[v];
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) scanf("%d%d",&ee[i].u,&ee[i].v);
	
	dsu.init(n);
	for(int i=1; i<=m; ++i)
	{
		int u = ee[i].u, v = ee[i].v;
		if(dsu.find(u) == dsu.find(v)) continue;
		
		add(u,v,i); add(v,u,i);
		dsu.connect(u,v);
	}
	
	for(int i=1; i<=n; ++i) if(dsu.find(i) == i)
	{
		dfs_sum(i,0);
		if(sum[i]) return printf("Impossible"), 0;
	}
	
	printf("Possible\n");
	for(int i=1; i<=m; ++i)
		printf("%lld\n",f[i]);
	return 0;
}