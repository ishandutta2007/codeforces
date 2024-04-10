#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 1e6 + 5;
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

ll fac[MAXD], inv[MAXD];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXD; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXD-1] = pw(fac[MAXD-1], mod - 2);
	for(int i=MAXD-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int d,w;
	scanf("%d%d",&d,&w);
	
	auto calc = [&] (int L,int R)
	{
		if(L > d || R > d) return 0ll;
		if(R < w)
			return C(d, L) * fac[L] %mod * L %mod * C(d, R) %mod * fac[R] %mod * pw(d, w - R - 1) %mod;
		else
			return C(d, L) * fac[L] %mod * (L+w-R) %mod * C(d-(R-w+1), w-1) %mod * fac[w-1] %mod;
	};
	
	ll ans = 0;
	for(int i=1; i<=d; ++i)
		ans = (ans + calc(i,i) + calc(i,i+1)) %mod;
	printf("%lld",ans);
	return 0;
}