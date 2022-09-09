#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 12 + 5;
const int ALL = (1<<12) + 5;
const int ALLP = (1<<6) + 5;
const int inf = 0x3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

int num1[ALL];

int n,m,d;
bool hase[MAXN][MAXN];

int pcnt;
pii p[MAXN];

unordered_set<ll> hsh[MAXN];

int clr[MAXN], ccnt = 0;
void dfs_clr(int dep)
{
	if(dep > pcnt)
	{
		ll h = 0;
		for(int i=1; i<=n; ++i)
			h = h * 7 + clr[i];
		hsh[ccnt].insert(h);
		return;
	}
	
	int u = p[dep].first, v = p[dep].second;
	for(int i=1; i<=ccnt; ++i)
	{
		clr[u] = clr[v] = i;
		dfs_clr(dep + 1);
	}
	if(ccnt < d)
	{
		clr[u] = clr[v] = ++ccnt;
		dfs_clr(dep + 1);
		--ccnt;
	}
}

int dp[ALLP][MAXN];
bool cango[MAXN][MAXN];

inline void upd_hsh(void)
{
	for(int i=1; i<=pcnt; ++i)
		for(int j=1; j<i; ++j)
			cango[i][j] = cango[j][i] =
				(hase[p[i].first][p[j].first] && hase[p[i].second][p[j].second])
				|| (hase[p[i].first][p[j].second] && hase[p[i].second][p[j].first]);
	
	int all = (1<<pcnt) - 1;
	for(int mask=0; mask<=all; ++mask)
		memset(dp[mask], 0, (pcnt+1)<<2);
	
	for(int i=1; i<=pcnt; ++i)
		if(hase[p[i].first][p[i].second])
			dp[bbit(i-1)][i] = 1;
	
	for(int mask=1; mask<=all; ++mask)
		for(int i=1; i<=pcnt; ++i) if(dp[mask][i])
			for(int j=1; j<=pcnt; ++j)
				if(!bdig(mask,j-1) && cango[i][j])
					dp[mask | bbit(j-1)][j] = 1;
	
	if(*max_element(dp[all]+1, dp[all]+pcnt+1) == 0) return;
	
	dfs_clr(1);
}

int main(void)
{
	for(int i=1; i<ALL; ++i) num1[i] = num1[i^lowbit(i)] + 1;
	
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		hase[u][v] = hase[v][u] = 1;
	}
	
	int all = (1<<n) - 1;
	pcnt = n / 2;
	for(int mask=0; mask<=all; ++mask) if(num1[mask] == n / 2)
	{
		vector<int> a,b;
		for(int i=1; i<=n; ++i)
		{
			if(bdig(mask, i-1)) a.push_back(i);
			else b.push_back(i);
		}
		do
		{
			bool ok = 1;
			for(int i=0; i<(int)a.size(); ++i)
				if(a[i] > b[i])
				{
					ok = 0;
					break;
				}
			if(!ok) continue;
			
			for(int i=1; i<=pcnt; ++i)
				p[i] = make_pair(a[i-1], b[i-1]);
			upd_hsh();
		}while(next_permutation(b.begin(), b.end()));
	}
	
	ll ans = 0;
	for(int i=1; i<=d; ++i) if(hsh[i].size())
	{
		ll cur = 1;
		for(int j=d-i+1; j<=d; ++j) cur *= j;
		ans += cur * (int)hsh[i].size();
	}
	
	printf("%lld",ans);
	return 0;
}