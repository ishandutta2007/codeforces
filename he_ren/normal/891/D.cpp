#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int inf = 0x3f3f3f3f;

inline pii merge(const pii &p,const pii &q)
{
	if(p.first > q.first) return p;
	else if(p.first < q.first) return q;
	else return make_pair(p.first, p.second + q.second);
}

inline pii shift(const pii &p,int k)
{
	if(k&1) return merge(make_pair(p.first + 1, p.second), make_pair(0, 1));
	else return make_pair(p.first - 1, p.second);
}

int n;
vector<int> g[MAXN];

int anc[MAXN], siz[MAXN], cntev[MAXN];
pii dp[MAXN];
void dfs_up(int u,int fa)
{
	anc[u] = fa; siz[u] = 1;
	if(fa) g[u].erase(find(g[u].begin(), g[u].end(), fa));
	
	dp[u] = make_pair(-inf, 0);
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		dfs_up(v, u);
		siz[u] += siz[v];
		cntev[u] += cntev[v];
		dp[u] = merge(dp[u], dp[v]);
	}
	dp[u] = shift(dp[u], siz[u]);
	if(siz[u] % 2 == 0) ++cntev[u];
}

int val[MAXN];
pii rdp[MAXN];
void dfs_down(int u,pii cur)
{
	static pii suf[MAXN];
	suf[(int)g[u].size()] = make_pair(-inf, 0);
	for(int i=(int)g[u].size()-1; i>=0; --i)
	{
		int v = g[u][i];
		suf[i] = merge(suf[i+1], dp[v]);
	}
	
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		rdp[v] = merge(cur, suf[i+1]);
		cur = merge(cur, dp[v]);
		
		val[v] = val[u];
		if((siz[u]) % 2 != (n - siz[v]) % 2)
		{
			if(siz[u] % 2) ++val[v];
			else --val[v];
		}
		
		rdp[v] = shift(rdp[v], n - siz[v]);
	}
	
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		dfs_down(v, rdp[v]);
	}
}

inline int calc(const pii &p,int has,int need)
{
	assert(has + p.first <= need / 2);
	return has + p.first == need / 2? p.second: 0;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	if(n % 2) return printf("0"), 0;
	
	dfs_up(1,0); dfs_down(1, make_pair(-inf, 0));
	
	ll ans = 0;
	if(cntev[1] == n / 2)
	{
		for(int i=2; i<=n; ++i)
			if(siz[i] % 2 == 0)
				ans += (ll)siz[i] * (n - siz[i]);
	}
	
	for(int i=2; i<=n; ++i) if(siz[i] % 2)
		ans += (ll)calc(dp[i], cntev[i], siz[i]) * calc(rdp[i], cntev[1] - cntev[i] + val[i], n - siz[i]);
	
	printf("%lld",ans);
	return 0;
}