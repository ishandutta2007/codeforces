#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e5 + 5;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector< vector<int> > g(n+2);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	
	for(int i=1; i<=n; ++i)
		g[0].push_back(i), g[i].push_back(n+1);
	
	vector<int> hasnxt(n+2);
	for(int i=0; i<=n; ++i)
		hasnxt[i] = find(g[i].begin(), g[i].end(), i+1) != g[i].end();
	
	vector<int> mxr(n+2);
	for(int i=n+1; i>=0; --i)
		mxr[i] = hasnxt[i]? mxr[i+1]: i;
	
	if(mxr[1] >= n)
	{
		printf("%lld\n",(ll)n * (n-1) / 2);
		return;
	}
	
	vector<int> canlef(n+2), canrig(n+2);
	vector< vector<int> > h(n+2), rh(n+2);
	for(int i=1; i<=n+1; ++i)
	{
		if(mxr[0] >= i-1) canlef[i] = 1;
		if(mxr[i] >= n+1) canrig[i] = 1;
		for(int j: g[i-1])
			if(j>=i+1 && j-1<=mxr[i])
				h[i].push_back(j),
				rh[j].push_back(i);
	}
	
	auto dfs_vis = [&] (auto self,int u,int cur,auto &_vis,const auto &_h) -> void
	{
		if(_vis[u][cur]) return;
		_vis[u][cur] = 1;
		for(int v: _h[u]) self(self, v, cur^1, _vis, _h);
	};
	
	vector< array<int,2> > vis1(n+2), vis2(n+2);
	int beg = -1;
	for(int i=0; i<=n; ++i)
		if(!hasnxt[i]){ beg = i+1; break;}
	assert(beg != -1);
	
	dfs_vis(dfs_vis, beg, 0, vis1, rh);
	dfs_vis(dfs_vis, beg, 0, vis2, h);
	
	vector<int> cnt1(4), cnt2(4);
	for(int i=0; i<=n+1; ++i)
	{
		if(canlef[i]) ++cnt1[vis1[i][0]<<1 | vis1[i][1]];
		if(canrig[i]) ++cnt2[vis2[i][0]<<1 | vis2[i][1]];
	}
	
	ll ans = 0;
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j) if(i&j)
			ans += (ll)cnt1[i] * cnt2[j];
	
	for(int u=0; u<=n+1; ++u)
		if(canlef[u] && canrig[u])
			--ans;
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}