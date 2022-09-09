#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

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
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

char s[MAXN];

int cnta[MAXN], cntb[MAXN], cntc[MAXN], cnts[MAXN];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n;
	scanf("%d%s",&n,s+1);
	
	int m = 0;
	for(int i=1; i<=n; ++i)
		if(s[i] == '?') ++m;
	
	for(int i=1; i<=n; ++i)
	{
		cnta[i] = cnta[i-1] + (s[i] == 'a');
		cntb[i] = cntb[i-1] + (s[i] == 'b');
		cntc[i] = cntc[i-1] + (s[i] == 'c');
		cnts[i] = cnts[i-1] + (s[i] == '?');
	}
	
	ll ans = m < 3? 0: c(m,3) * pw(3, m-3) %mod;
	
	for(int i=1; i<=n; ++i) if(s[i] == 'b')
	{
		ans = (ans + pw(3,m) * cnta[i] %mod * (cntc[n] - cntc[i])) %mod;
		
		if(m >= 1)
		{
			ans = (ans + pw(3,m-1) * cnts[i] %mod * (cntc[n] - cntc[i])) %mod;
			ans = (ans + pw(3,m-1) * cnta[i] %mod * (cnts[n] - cnts[i])) %mod;
		}
		if(m >= 2)
			ans = (ans + pw(3,m-2) * cnts[i] %mod * (cnts[n] - cnts[i])) %mod;
	}
	
	if(m >= 2)
	{
		for(int i=1; i<=n; ++i) if(s[i] == 'a')
			ans = (ans + pw(3,m-2) * c(cnts[n]-cnts[i], 2)) %mod;
		for(int i=1; i<=n; ++i) if(s[i] == 'c')
			ans = (ans + pw(3,m-2) * c(cnts[i], 2)) %mod;
	}
	
	if(m >= 1)
	{
		for(int i=1; i<=n; ++i) if(s[i] == '?')
			ans = (ans + pw(3,m-1) * cnta[i] %mod * (cntc[n] - cntc[i])) %mod;
	}
	
	printf("%lld",ans);
	return 0;
}