#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int MAXD = 50 + 5;
const int mod = 998244353;

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

const int MAXF = MAXN * 2;
ll fac[MAXF], inv[MAXF];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int b[MAXN];

int dp[2][MAXD * 2][MAXN];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod-2);
	for(int i=MAXF-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	b[0] = 0;
	dp[0][0+MAXD][0] = 1;
	int now = 0;
	for(int i=1; i<=n; ++i)
	{
		now ^= 1;
		memset(dp[now], 0, sizeof(dp[now]));
		
		for(int x=b[i-1]-d; x<=b[i-1]+d; ++x) if(0<=x && x<=n)
		{
			int y = max(x+1, b[i]-d);
			if(y > b[i]+d) continue;
			int t = y-x-1;
			
			int *ldp = dp[now^1][x-b[i-1]+MAXD];
			int *cdp = dp[now][y-b[i]+MAXD];
			
			for(int j=t; j<=i-1; ++j) if(ldp[j])
				cdp[j-t] = (cdp[j-t] + (ll)ldp[j] * fac[j] %mod * inv[j-t]) %mod;
		}
		
		for(int y=b[i]-d; y+1<=b[i]+d; ++y) if(0<=y && y<=n)
		{
			int *cdp1 = dp[now][y-b[i]+MAXD];
			int *cdp2 = dp[now][y+1-b[i]+MAXD];
			for(int j=1; j<=i; ++j) if(cdp1[j])
				cdp2[j-1] = (cdp2[j-1] + (ll)cdp1[j] * j) %mod;
		}
		
		for(int x=b[i-1]-d; x<=b[i-1]+d; ++x) if(0<=x && x<=n)
		{
			if(abs(x-b[i]) > d) continue;
			int *ldp = dp[now^1][x-b[i-1]+MAXD];
			int *cdp = dp[now][x-b[i]+MAXD];
			
			for(int j=0; j<=i-1; ++j) if(ldp[j])
			{
				add_mod(cdp[j], (ll)ldp[j] * (j + x) %mod);
				add_mod(cdp[j+1], ldp[j]);
			}
		}
	}
	
	int ans = 0;
	for(int x=b[n]-d; x<=b[n]+d; ++x) if(0<=x && x<=n)
	{
		int *cdp = dp[now][x-b[n]+MAXD];
		for(int i=0; i<=n; ++i) if(cdp[i])
			add_mod(ans, (ll)cdp[i] * C(n-x, i) %mod * fac[i] %mod);
	}
	printf("%d",ans);
	return 0;
}