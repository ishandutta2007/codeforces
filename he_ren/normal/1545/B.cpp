#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
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
inline ll c(int n,int m){ return n<0||m<0||n<0? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int x = 0, y = 1;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[i] == s[j]) ++j;
		if(s[i] == '0'){ y += j - i; continue;}
		x += (j - i) / 2;
	}
	
	printf("%lld\n",c(x + y - 1, y - 1));
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod - 2);
	for(int i=MAXF-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}