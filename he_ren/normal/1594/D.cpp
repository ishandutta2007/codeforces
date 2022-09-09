#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

vector<int> g[MAXN], gw[MAXN];

int clr[MAXN], cnt[2];
bool fail;
void dfs_clr(int u)
{
	++cnt[clr[u]];
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i], w = gw[u][i];
		if(clr[v] == -1)
		{
			clr[v] = clr[u] ^ w;
			dfs_clr(v);
		}
		else
		{
			if(clr[v] != (clr[u] ^ w))
				fail = 1;
		}
		if(fail) return;
	}
}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		g[i].clear(), gw[i].clear();
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		static char c[100];
		scanf("%d%d%s",&u,&v,c+1);
		int w = c[1] == 'i';
		g[u].push_back(v); gw[u].push_back(w);
		g[v].push_back(u); gw[v].push_back(w);
	}
	
	int ans = 0;
	memset(clr,-1,(n+1)<<2);
	fail = 0;
	for(int u=1; u<=n; ++u) if(clr[u] == -1)
	{
		clr[u] = 0;
		cnt[0] = cnt[1] = 0;
		dfs_clr(u);
		if(fail)
		{
			printf("-1\n");
			return;
		}
		ans += max(cnt[0], cnt[1]);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}