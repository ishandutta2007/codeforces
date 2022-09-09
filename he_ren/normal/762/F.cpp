#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 12 + 5;
const int ALL = (1<<11) + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

namespace Solver
{
	int n,m;
	vector<int> g[MAXN], h[MAXM];
	vector<int> eid[MAXM], revid[MAXM];
	int etot = 0;
	
	int f[MAXN][MAXM * 2];
	int res = 0;
	void dfs_f(int u,int fa)
	{
		for(int v: g[u]) if(v != fa) dfs_f(v, u);
		
		for(int pt=1; pt<=m; ++pt)
		{
			int d = (int)h[pt].size();
			int all = (1<<d) - 1;
			
			vector<int> dp(all+1);
			dp[0] = 1;
			for(int v: g[u]) if(v != fa)
				for(int mask=all; mask>=0; --mask) if(dp[mask])
				{
					for(int i=0; i<d; ++i) if(!bdig(mask, i))
						add_mod(dp[mask | bbit(i)], (ll)dp[mask] * f[v][ revid[pt][i] ] %mod);
				}
			
			add_mod(res, dp[all]);
			for(int i=0; i<(int)h[pt].size(); ++i)
				f[u][eid[pt][i]] = dp[all ^ bbit(i)];
			
//			for(int i=0; i<(int)h[pt].size(); ++i)
//				printf("f[%d][(%d, %d)] = %d\n",u,pt,h[pt][i],f[u][eid[pt][i]]);
		}
	}
	
	inline int solve(const vector<pii> &eg,const vector<pii> &eh)
	{
		n = (int)eg.size() + 1; m = (int)eh.size() + 1;
		for(int i=1; i<=n; ++i) g[i].clear();
		for(int i=1; i<=m; ++i) h[i].clear(), eid[i].clear(), revid[i].clear();
		
		for(pii x: eg)
		{
			int u = x.first, v = x.second;
			g[u].push_back(v); g[v].push_back(u);
		}
		
		etot = 0;
		for(pii x: eh)
		{
			int u = x.first, v = x.second;
			h[u].push_back(v); h[v].push_back(u);
			eid[u].push_back(++etot); revid[v].push_back(etot);
			eid[v].push_back(++etot); revid[u].push_back(etot);
		}
		
		res = 0;
		dfs_f(1,0);
//		printf("res = %d\n",res);
		return res;
	}
}

int main(void)
{
	int n,m;
	scanf("%d",&n);
	vector<pii> g(n-1);
	for(pii &x: g) scanf("%d%d",&x.first,&x.second);
	scanf("%d",&m);
	vector<pii> h(m-1);
	for(pii &x: h) scanf("%d%d",&x.first,&x.second);
	
	int ans = (ll)Solver::solve(g,h) * pw(Solver::solve(h,h), mod - 2) %mod;
	printf("%d",ans);
	return 0;
}