#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

ll fac[MAXN],inv[MAXN];
ll c(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n]*inv[m] %mod * inv[n-m] %mod;
}

int main(void)
{
	fac[0]=1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1]*i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	int n;
	ll d;
	scanf("%d%lld",&n,&d);
	if(!d){ printf("%lld",fac[n]); return 0;}
	
	ll m = n-d;
	if(m<=0){ printf("0"); return 0;}
	
	int ans = 0;
	for(int i=0; i<=m; ++i)
	{
		int f = (i&1)? mod-1: 1;
		add_mod(ans, c(m,i) * pw(m-i,n) %mod * f %mod);
	}
	printf("%lld",ans * c(n,m) %mod * 2 %mod);
	return 0;
}