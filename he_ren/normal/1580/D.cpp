#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 4e3 + 5;

int m;
int a[MAXN];
vector<int> g[MAXN];

int siz[MAXN];
ll f[MAXN][MAXN];
void dfs_f(int u,int fa)
{
	siz[u] = 1;
	f[u][0] = 0; f[u][1] = (ll)(m - 1) * a[u];
	for(int v: g[u]) if(v != fa)
	{
		dfs_f(v, u);
		
		static ll nf[MAXN];
		memset(nf, 0xc0, (siz[u] + siz[v] + 1) << 3);
		for(int i=0; i<=siz[u]; ++i)
			for(int j=0; j<=siz[v]; ++j)
				nf[i+j] = max(nf[i+j], f[u][i] + f[v][j] - 2ll * i * j * a[u]);
		
		siz[u] += siz[v];
		memcpy(f[u], nf, (siz[u] + 1) << 3);
	}
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) g[i].resize(2);
	
	stack<int> sta;
	int rt = 0;
	for(int i=1; i<=n; ++i)
	{
		while(sta.size() && a[sta.top()] > a[i])
			g[i][0] = sta.top(), sta.pop();
		if(sta.size()) g[sta.top()][1] = i;
		else rt = i;
		sta.push(i);
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=0; j<(int)g[i].size(); ++j)
			if(!g[i][j])
			{
				g[i].erase(g[i].begin() + j);
				--j;
			}
	
	dfs_f(rt, 0);
	
	printf("%lld",f[rt][m]);
	return 0;
}