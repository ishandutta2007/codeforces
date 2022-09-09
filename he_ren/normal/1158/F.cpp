#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e3 + 5;
const int mod = 998244353;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
inline void chk_mod(int &a){ if(a<0) a+=mod;}

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

ll pw2[MAXN], icoef[MAXN];


int n,c;
int a[MAXN];

namespace Subtask1
{
	int sum[MAXN][MAXN], f[MAXN][MAXN], g[MAXN][MAXN];
	
	void solve(void)
	{	
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=c; ++j) sum[i][j] = sum[i-1][j];
			++sum[i][a[i]];
		}
		
		for(int i=1; i<=n; ++i)
		{
			if(c == 1){ f[i][i+1] = 1; continue;}
			
			static int t[MAXN];
			for(int j=1; j<=c; ++j) t[j] = 0;
			
			int cnt = 0, cur = 1;
			for(int j=i; j<=n; ++j)
			{
				int ct = ++t[a[j]];
				if(ct == 1)
				{
					++cnt;
					if(cnt == c)
					{
						for(int k=1; k<=c; ++k)
							if(k != a[i]) cur = cur * (pw2[t[k]] - 1) %mod;
						chk_mod(cur);
					}
				}
				else if(cnt == c && a[j] != a[i])
					chk_mod(cur = cur * icoef[ct - 1] %mod * (pw2[ct] - 1) %mod);
				
				if(cnt == c && a[j] != a[i])
					f[i][j+1] = cur * icoef[ct] %mod * pw2[t[a[i]] - 1] %mod;
			}
		}
		
		g[n+1][0] = 1;
		static int mxp[MAXN];
		for(int i=n; i>=1; --i)
		{
			for(int j=i+1; j<=n+1; ++j) if(f[i][j])
			{
				mxp[i] = max(mxp[i], mxp[j] + 1);
				for(int k=0; k<=mxp[j]; ++k)
					g[i][k+1] = (g[i][k+1] + (ll)g[j][k] * f[i][j]) %mod;
			}
			
			g[i][0] = pw2[n-i];
			for(int j=1; j<=mxp[i]; ++j)
				add_mod(g[i][0], mod - g[i][j]);
			
			for(int j=0; j<=mxp[i]; ++j)
				add_mod(g[i][j], g[i+1][j]);
		}
		
		add_mod(g[1][0], mod - 1);
		for(int i=0; i<=n; ++i)
			printf("%d ",g[1][i]);
		exit(0);
	}
}

namespace Subtask2
{
	const int ALL = (1<<11) + 5;
	
	ll g[MAXN][ALL];
	
	void solve(void)
	{
		int all = (1<<c) - 1;
		
		g[0][0] = 1;
		for(int k=n; k>=1; --k)
		{
			int mxp = (n-k+1) / c;
			
			int cura = bbit(a[k]-1);
			for(int i=mxp; i>=0; --i)
				for(int mask=all-1; mask>=0; --mask) if(g[i][mask])
				{
					if((mask|cura) == all) g[i+1][0] += g[i][mask];
					else g[i][mask | cura] += g[i][mask];
				}
			
			if(k%20 == 0)
			{
				for(int i=0; i<=mxp; ++i)
					for(int mask=0; mask<=all; ++mask)
						g[i][mask] %= mod;
			}
		}
		
		g[0][0] += mod - 1;
		
		int mxp = n / c;
		for(int i=0; i<=n; ++i)
		{
			if(i > mxp){ printf("0 "); continue;}
			int res = 0;
			for(int mask=0; mask<all; ++mask) add_mod(res, g[i][mask] %mod);
			printf("%d ",res);
		}
		exit(0);
	}
}

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXN; ++i) pw2[i] = pw2[i-1] * 2 %mod;
	for(int i=0; i<MAXN; ++i) icoef[i] = pw((pw2[i] - 1 + mod) %mod, mod - 2);
	
	scanf("%d%d",&n,&c);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	if(c > 11 || n <= (1<<c)) Subtask1::solve();
	else Subtask2::solve();
	return 0;
}