#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

vector<int> g[MAXN];
int deg[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) g[i].clear();
	for(int i=1; i<=n; ++i)
	{
		int k;
		scanf("%d",&k);
		deg[i] = k;
		while(k--)
		{
			int u;
			scanf("%d",&u);
			g[u].push_back(i);
		}
	}
	
	vector<int> q;
	static int f[MAXN];
	for(int i=1; i<=n; ++i)
	{
		f[i] = 1;
		if(!deg[i]) q.push_back(i);
	}
	
	int ans = 0;
	for(int it=0; it<(int)q.size(); ++it)
	{
		int u = q[it]; ans = max(ans, f[u]);
		for(int v: g[u])
		{
			f[v] = max(f[v], f[u] + (v < u));
			if(--deg[v] == 0) q.push_back(v);
		}
	}
	
	if((int)q.size() != n) printf("-1\n");
	else printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}