#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n,m;
vector<pii> g[MAXN];

ll dep[MAXN], mndep, mxdep;
int clr[MAXN];
bool vis[MAXN], valid;
void dfs_dep(int u,ll k,int curc)
{
	if(!valid) return;
	if(vis[u])
	{
		if(k != dep[u]) valid = 0;
		return;
	}
	mndep = min(mndep, k); mxdep = max(mxdep, k);
	vis[u] = 1; dep[u] = k; clr[u] = curc;
	for(pii it: g[u])
	{
		dfs_dep(it.first, k + it.second, curc);
		if(!valid) return;
	}
}

array<int,3> es[MAXM];

bool chk(int lim)
{
	valid = 1;
	for(int i=1; i<=n; ++i)
	{
		vis[i] = 0;
		g[i].clear();
	}
	for(int i=1; i<=lim; ++i)
	{
		int u = es[i][0], v = es[i][1], w = es[i][2];
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, -w);
	}
	
	int ccnt = 0;
	mndep = mxdep = 0;
	dfs_dep(1, 0, ++ccnt);
	if(!valid) return 0;
	
	ll need = vis[n]? dep[n]: linf;
	for(int i=1; i<=n; ++i) if(!vis[i])
	{
		mndep = mxdep = 0;
		dfs_dep(i, 0, ++ccnt);
		if(!valid) return 0;
		if(mxdep - mndep >= need) return 0;
	}
	
	for(int i=1; i<=n; ++i)
	{
		if(i != 1 && clr[i] == clr[1] && dep[i] <= dep[1])
			return 0;
		if(i != n && clr[i] == clr[n] && dep[i] >= dep[n])
			return 0;
	}
	return 1;
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w1,w2;
		scanf("%d%d%d%d",&u,&v,&w1,&w2);
		es[i] = {u,v,w1*w2};
	}
	
	if(chk(m))
	{
		if(clr[1] == clr[n])
			printf("%lld",dep[n]);
		else
			printf("UNKNOWN");
		return 0;
	}
	
	int l = 0, r = m-1;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("BAD %d",l+1);
	return 0;
}