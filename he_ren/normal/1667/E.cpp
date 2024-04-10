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

const int MAXF = MAXN * 2;
ll fac[MAXF], inv[MAXF], ninv[MAXF];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod-2);
	for(int i=MAXF-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	ninv[1] = 1;
	for(int i=2; i<MAXF; ++i)
		ninv[i] = (mod - mod / i) * ninv[mod % i] %mod;
	
	int n;
	scanf("%d",&n);
	
	static int f[MAXN], res[MAXN];
	int sum = 0;
	for(int i=n; i>=1; --i)
	{
		f[i] = i == 1? 1: C(n-n/2-1, i-1) * fac[n-i] %mod * fac[i-1] %mod * inv[n-1] %mod;
		add_mod(res[i] = f[i], mod - sum);
		if(i > 1) sum = (sum + f[i] * ninv[i-1]) %mod;
	}
	for(int i=1; i<=n; ++i)
		printf("%lld ",res[i] * fac[n-1] %mod);
	return 0;
}