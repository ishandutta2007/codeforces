#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;
const int MAXM = 5e3 + 5;
const int MAXFAC = MAXN+MAXM;
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

ll fac[MAXFAC],inv[MAXFAC];

ll c(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n]*inv[m]%mod * inv[n-m] %mod;
}

ll f(int n,int m,int lim)
{
	if(!n) return !m;
	int res=0;
	for(int i=0; i<=n && (ll)i*lim <= m; ++i)
	{
		int tmp = c(n,i) * c(m-i*lim+n-1,n-1) %mod;
		if(i&1)
		{
			res-=tmp;
			if(res<0) res+=mod;
		}
		else
		{
			res+=tmp;
			if(res>=mod) res-=mod;
		}
	}
	return res;
}

int main(void)
{
	fac[0]=1;
	for(int i=1; i<MAXFAC; ++i) fac[i] = fac[i-1]*i %mod;
	inv[MAXFAC-1]=pw(fac[MAXFAC-1],mod-2);
	for(int i=MAXFAC-2; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	int n,m,r;
	scanf("%d%d%d",&n,&m,&r);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		ll tmp = c(n-1,i-1)*pw(i,mod-2) %mod;
		for(int j=r; j<=m && (ll)i*j<=m; ++j)
			add_mod(ans, tmp * f(n-i,m-i*j,j) %mod);
	}
	
	ans = pw(c(m-r+n-1, n-1),mod-2) * ans %mod;
	printf("%d",ans);
	return 0;
}