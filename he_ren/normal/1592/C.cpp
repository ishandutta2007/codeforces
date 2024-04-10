#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
int a[MAXN];

int f[MAXN];
void dfs_f(int u,int fa)
{
	f[u] = a[u];
	for(int v: g[u]) if(v != fa)
	{
		dfs_f(v, u);
		f[u] ^= f[v];
	}
}

bool has_f1 = 0;
bool dfs_res(int u,int fa,bool has0)
{
	if(u != 1)
	{
		if(f[u] == 0) has0 = 1;
		if(f[u] == f[1] && (has0 || has_f1)) return 1;
	}
	for(int v: g[u]) if(v != fa)
	{
		bool res = dfs_res(v, u, has0);
		if(res) return 1;
	}
	if(u != 1 && f[u] == f[1])
		has_f1 = 1;
	return 0;
}

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) g[i].clear();
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	dfs_f(1,0);
	
	if(f[1] == 0)
	{
		printf("YES\n");
		return;
	}
	if(d == 2)
	{
		printf("NO\n");
		return;
	}
	
	has_f1 = 0;
	if(dfs_res(1,0,0)) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}