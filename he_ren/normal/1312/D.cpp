#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
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
inline ll c(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n]*inv[m]%mod * inv[n-m] %mod;
}

int main(void)
{
	fac[0]=1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1]*i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1],mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	int ans=0, inv2=pw(2,mod-2);
	for(int i=n-1; i<=m; ++i)
		add_mod(ans, c(i-1,n-2)*pw(2,n-2)%mod * (n-2) %mod * inv2 %mod);
	printf("%d",ans);
	return 0;
}