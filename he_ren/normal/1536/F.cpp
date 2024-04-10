#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e6 + 5;
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
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

inline ll calc(int n,int m)
{
	if(n<m) return 0;
	return c(n - 1, m - 1);
}

inline ll get_res(int n,int m)
{
	if(n%2 || n<m) return 0;
	return (calc(n, m+1) + 2 * calc(n, m)) %mod * fac[n] %mod;
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n;
	scanf("%d",&n);
	
	int ans = n%2? 0: fac[n];
	for(int i=1; i<=n; ++i)
		ans = (ans + get_res(n-i, i)) %mod;
	printf("%d",ans * 2 %mod);
	return 0;
}