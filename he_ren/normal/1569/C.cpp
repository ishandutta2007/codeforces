#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
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

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	
	if(a[n] == a[n-1])
	{
		printf("%lld\n",fac[n]);
		return;
	}
	if(a[n] >= a[n-1] + 2)
	{
		printf("0\n");
		return;
	}
	
	int cnt = count(a+1,a+n+1,a[n-1]);
	
	ll ans = fac[cnt+1] - fac[cnt];
	ans = ans * C(n, cnt + 1) %mod * fac[n - cnt - 1] %mod;
	ans = (ans + mod) %mod;
	
	printf("%lld\n",ans);
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod - 2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}