#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u]=etot;
}

ll p[MAXN], h[MAXN];

ll a[MAXN];
void dfs(int u,int fa)
{
	ll x = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		p[u] += p[v];
		x += a[v];
	}
	if(h[u] > p[u] || h[u] < -p[u]) throw 114514;
	if((h[u] + p[u])%2) throw 114514;
	a[u] = (h[u] + p[u])/2;
	if(a[u]<0 || a[u]>p[u] || a[u]<x) throw 114514;
}


void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%lld",&p[i]);
	for(int i=1; i<=n; ++i) scanf("%lld",&h[i]);
	
	etot=0;
	for(int i=1; i<=n; ++i) head[i] = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	try
	{
		dfs(1,0);
		printf("YES\n");
	}
	catch(...)
	{
		printf("NO\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}