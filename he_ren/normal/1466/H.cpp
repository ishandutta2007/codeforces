#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 40 + 5;
const int MAXP = 1.5e3 + 5;
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

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int n, mxl;
int p[MAXN], bak[MAXN];

int val[MAXN];

int pcnt = 0;
int pt[MAXP][MAXN], sum[MAXP];
vector<pii> sub[MAXP];
int dp[MAXP];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<=i; ++j)
			val[i] = (val[i] + fac[j] * fac[n-j-1] %mod * C(i, j)) %mod;
	}
	
	static bool vis[MAXN];
	for(int i=1; i<=n; ++i) if(!vis[i])
	{
		int u = i, len = 0;
		while(!vis[u]) ++len, vis[u] = 1, u = p[u];
		mxl = max(mxl, len);
		++bak[len];
	}
	
	pcnt = 1;
	for(int i=1; i<=mxl; ++i)
		pcnt *= bak[i] + 1;
	for(int i=0; i<pcnt; ++i)
	{
		int mask = i;
		for(int j=1; j<=mxl; ++j)
		{
			pt[i][j] = mask % (bak[j] + 1);
			sum[i] += pt[i][j] * j;
			mask /= bak[j] + 1;
		}
	}
	for(int u=0; u<pcnt; ++u)
	{
		function<void(int,int,int)> dfs_sub = [&] (int dep,int v,int k)
		{
			if(dep == 0)
			{
				sub[u].emplace_back(v,k);
				return;
			}
			for(int i=0; i<=pt[u][dep]; ++i)
				dfs_sub(dep-1, v * (bak[dep]+1) + i, (ll)k * C(pt[u][dep], i) %mod);
		};
		dfs_sub(mxl, 0, 1);
	}
	
	dp[0] = 1;
	for(int u=1; u<pcnt; ++u)
	{
		static int f[MAXP];
		auto revsub = sub[u];
		reverse(revsub.begin(), revsub.end());
		for(auto it: revsub) f[it.first] = 0;
		for(auto it: revsub)
		{
			int v = it.first;
			if(v == 0) continue;
			
			int cur  = (ll)dp[u-v] * it.second %mod * pw(val[sum[u-v]], sum[v]) %mod;
			add_mod(f[v], cur);
			add_mod(dp[u], f[v]);
			
			for(auto jt: sub[v])
			{
				int w = jt.first, kw = jt.second;
				if(w == 0 || w == v) continue;
				add_mod(f[w], mod - (ll)f[v] * kw %mod);
			}
		}
	}
	
	printf("%d",dp[pcnt-1]);
	return 0;
}