#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

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

ll fac[MAXN];

int p[MAXN];

int main(void)
{
	fac[0]=1;
	for(int i=1; i<MAXN; ++i) fac[i]=fac[i-1]*i%mod;
	
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	ll ans=0;
	for(int i=n-k+1; i<=n; ++i) ans += i;
	printf("%lld ",ans);
	
	ans=1;
	for(int i=1; i<=n;)
	{
		while(i<=n && p[i]<=n-k) ++i;
		if(i>n) break;
		
		int j=i+1;
		while(j<=n && p[j]<=n-k) ++j;
		if(j>n) break;
		
		ans = ans * (j-i) %mod;
		i=j;
	}
	printf("%lld",ans);
	return 0;
}