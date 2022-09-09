#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 50 + 5;
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

const int MAXF = 1e5 + 5;
ll fac[MAXF], inv[MAXF];

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

namespace P1
{
	vector<int> solve(int A,int B,vector< array<int,3> > es)
	{
		vector< vector<pii> > g(A+1);
		for(auto &t: es)
			g[t[0]].emplace_back(t[1], t[2]);
		
		int all = (1<<B)-1;
		vector<int> dp(all+1);
		dp[0] = 1;
		for(int u=1; u<=A; ++u)
			for(int mask=all; mask>=0; --mask)
				for(auto it: g[u]) if(!bdig(mask, it.first-1))
				{
					int nxt = mask | bbit(it.first-1);
					dp[nxt] = (dp[nxt] + (ll)dp[mask] * it.second) %mod;
				}
		
		vector<int> res(B+1);
		for(int mask=0; mask<=all; ++mask)
			add_mod(res[__builtin_popcount(mask)], dp[mask]);
		return res;
	}
}

namespace P2
{
	vector<pii> g[MAXD];
	
	bool chs[MAXD];
	int siz[MAXD], dp[MAXD][MAXD][2];
	void dfs_dp(int u,int fa)
	{
		siz[u] = 1;
		memset(dp[u], 0, sizeof(int) * 2 * 2);
		dp[u][0][chs[u]] = 1;
		
		for(auto it: g[u]) if(it.first != fa)
		{
			int v = it.first, w = it.second;
			dfs_dp(v, u);
			
			static int ndp[MAXD][2];
			memset(ndp, 0, sizeof(int) * (siz[u] + siz[v] + 2) * 2);
			for(int x=0; x<=siz[u]; ++x)
				for(int y=0; y<=siz[v]; ++y)
				{
					int *A = dp[u][x], *B = dp[v][y];
					ndp[x+y][0] = (ndp[x+y][0] + (ll)A[0] * (B[0] + B[1])) %mod;
					ndp[x+y][1] = (ndp[x+y][1] + (ll)A[1] * (B[0] + B[1])) %mod;
					ndp[x+y+1][1] = (ndp[x+y+1][1] + (ll)A[0] * B[0] %mod * w) %mod;
				}
			memcpy(dp[u], ndp, sizeof(int) * (siz[u] + siz[v] + 2) * 2);
			siz[u] += siz[v];
		}
	}
	
	int fa[MAXD];
	int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
	
	vector<int> solve(int n,vector< array<int,3> > es)
	{
		for(int i=1; i<=n; ++i) g[i].clear();
		iota(fa+1, fa+n+1, 1);
		
		vector< array<int,3> > vec;
		for(auto &t: es)
		{
			int u = t[0], v = t[1];
			if(find(u) == find(v))
				vec.emplace_back(t);
			else
			{
				g[u].emplace_back(v, t[2]);
				g[v].emplace_back(u, t[2]);
				fa[find(u)] = find(v);
			}
		}
		
		vector<int> res(n+1);
		for(int mask=0; mask<(1<<(int)vec.size()); ++mask)
		{
			memset(chs, 0, n+1);
			int cur = 1;
			for(int i=0; i<(int)vec.size(); ++i) if(bdig(mask, i))
			{
				int u = vec[i][0], v = vec[i][1], w = vec[i][2];
				if(chs[u] || chs[v])
				{
					cur = 0;
					break;
				}
				chs[u] = chs[v] = 1;
				cur = (ll)cur * w %mod;
			}
			if(cur == 0) continue;
			
			dfs_dp(1,0);
			
			int has = __builtin_popcount(mask);
			for(int i=0; i<=n; ++i) if(dp[1][i][0] || dp[1][i][1])
				res[i+has] = (res[i+has] + (ll)cur * (dp[1][i][0] + dp[1][i][1])) %mod;
		}
		return res;
	}
}

array<int,3> p[MAXD];

int fa[MAXD];
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod-2);
	for(int i=MAXF-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=d; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		z = ((z - 1) %mod + mod) %mod;
		p[i] = {x,y,z};
	}
	
	iota(fa+1, fa+d+1, 1);
	for(int i=1; i<=d; ++i)
		for(int j=1; j<i; ++j)
			if(p[i][0] == p[j][0] || p[i][1] == p[j][1])
				fa[find(i)] = find(j);
	
	static vector<int> nodes[MAXD];
	for(int i=1; i<=d; ++i)
		nodes[find(i)].emplace_back(i);
	
	vector<int> ans = {1};
	
	for(int rt=1; rt<=d; ++rt) if(find(rt) == rt)
	{
		vector< array<int,3> > vec;
		for(int i: nodes[rt])
			vec.emplace_back(p[i]);
		
		int A,B;
		for(int k=0; k<=1; ++k)
		{
			static int dsc[MAXD];
			int dcnt = 0;
			for(auto &t: vec)
				dsc[++dcnt] = t[k];
			sort(dsc+1,dsc+dcnt+1);
			dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
			for(auto &t: vec)
				t[k] = lower_bound(dsc+1,dsc+dcnt+1,t[k]) - dsc;
			(k == 0? A: B) = dcnt;
		}
		
		if(A < B)
		{
			swap(A, B);
			for(auto &t: vec)
				swap(t[0], t[1]);
		}
		
		vector<int> cur;
		if(B <= 17)
		{
			cur = P1::solve(A, B, vec);
		}
		else
		{
			for(auto &t: vec)
				t[1] += A;
			cur = P2::solve(A+B, vec);
		}
		
		vector<int> nxt((int)ans.size() + (int)cur.size() - 1);
		for(int i=0; i<(int)ans.size(); ++i)
			for(int j=0; j<(int)cur.size(); ++j)
				nxt[i+j] = (nxt[i+j] + (ll)ans[i] * cur[j]) %mod;
		ans.swap(nxt);
	}
	
	ll sum = 0;
	for(int i=0; i<(int)ans.size() && i<=n; ++i)
		sum = (sum + (ll)ans[i] * fac[n-i]) %mod;
	printf("%lld",sum);
	return 0;
}