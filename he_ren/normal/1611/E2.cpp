#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

vector<int> g[MAXN];
bool has[MAXN];

int dep[MAXN], mndis[MAXN], dp[MAXN];
void dfs_tree(int u,int fa)
{
	mndis[u] = inf;
	dp[u] = u != 1 && g[u].size() == 1? inf: 0;
	for(int v: g[u]) if(v != fa)
	{
		dep[v] = dep[u] + 1;
		dfs_tree(v, u);
		mndis[u] = min(mndis[u], mndis[v] + 1);
		dp[u] = min(inf, dp[u] + dp[v]);
	}
	if(has[u]) mndis[u] = 0;
	if(mndis[u] <= dep[u]) dp[u] = 1;
}

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
	{
		has[i] = 0;
		g[i].clear();
	}
	for(int i=1; i<=d; ++i)
	{
		int x;
		scanf("%d",&x);
		has[x] = 1;
	}
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	dep[1] = 0; dfs_tree(1,0);
	
	if(dp[1] < inf) printf("%d\n",dp[1]);
	else printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}