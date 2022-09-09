#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];
vector<int> g[MAXN];

int sum[MAXN];
set<int> f[MAXN];
int ans = 0;
void dfs_ans(int u,int fa)
{
	sum[u] ^= a[u];
	for(int v: g[u]) if(v != fa)
		sum[v] = sum[u], dfs_ans(v,u);
	
	bool invalid = 0;
	f[u].emplace(sum[u]);
	for(int v: g[u]) if(v != fa)
	{
		if(f[u].size() < f[v].size())
			f[u].swap(f[v]);
		for(auto t: f[v])
			if(f[u].count(t ^ a[u]))
			{
				invalid = 1;
				break;
			}
		if(invalid) break;
		
		auto it = f[u].begin();
		for(int t: f[v])
			it = f[u].emplace_hint(it, t);
	}
	if(invalid)
		++ans, f[u].clear();
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v); g[v].emplace_back(u);
	}
	
	dfs_ans(1,0);
	
	printf("%d",ans);
	return 0;
}