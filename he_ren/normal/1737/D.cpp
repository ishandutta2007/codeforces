#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 500 + 5;
const int MAXM = 2.5e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

bool g[MAXN][MAXN];
array<int,3> es[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			g[i][j] = 0;
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		es[i] = {u,v,w};
		g[u][v] = g[v][u] = 1;
	}
	
	static int dep[MAXN][MAXN];
	static pii pre[MAXN][MAXN];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			dep[i][j] = -1;
	
	queue<pii> q;
	dep[1][n] = 0; q.emplace(1, n);
	while(q.size())
	{
		int u,v; tie(u,v) = q.front(); q.pop();
		for(int i=1; i<=n; ++i)
		{
			if((g[u][i] || u == v) && dep[i][v] == -1)
				dep[i][v] = dep[u][v] + 1, q.emplace(i, v), pre[i][v] = {u,v};
			
			if((g[v][i] || u == v) && dep[u][i] == -1)
				dep[u][i] = dep[u][v] + 1, q.emplace(u, i), pre[u][i] = {u,v};
		}
	}
	
	ll ans = linf;
	for(int i=1; i<=m; ++i)
	{
		int u = es[i][0], v = es[i][1], w = es[i][2];
		ans = min(ans, (ll)w * (min({dep[u][v], dep[v][u], dep[u][u]+1, dep[v][v]+1}) + 1));
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}