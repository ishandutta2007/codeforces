#include<cstdio>
#include<algorithm>
#define mod 998244353
using namespace std;
long long n,m,fac[200005],inv[200005];
long long qpow(long long x,long long y)
{
	long long res=1;
	while(y)
	{
		if(y%2) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
long long C(long long x,long long y)
{
	if(x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	if(n==2)
	{
		printf("0\n");
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=max(n,m);i++)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=qpow(fac[i],mod-2);
//		printf("fac=%d inv=%d\n",fac[i],inv[i]);
	}
	printf("%lld\n",C(m,n-1)*(n-2)%mod*qpow(2,n-3)%mod);
}