#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

vector<int> g[MAXN];

int sum = 0, cnt = 0;
int dfs_res(int u,int fa)
{
	int res = 0;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(v == fa) continue;
		res += (dfs_res(v, u) == 0);
	}
	
	if(res) ++cnt, sum += res;
	return res;
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) g[i].clear();
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	sum = cnt = 0;
	dfs_res(1,0);
	
	printf("%d\n",sum - (cnt - 1));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}