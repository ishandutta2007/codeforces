#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;
const int MAXM = 10 + 5;
const int MAXC = MAXN + MAXM*2;
const int mod = 1e9 + 7;

ll pw(ll a,int b)
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

ll fac[MAXC],inv[MAXC];

ll c(int n,int m)
{
	if(n<0 || m<0 || n-m<0) return 0;
	return fac[n]*inv[m]%mod *inv[n-m] %mod;
}

int main(void)
{
	fac[0]=1;
	for(int i=1; i<MAXC; ++i) fac[i] = fac[i-1]*i %mod;
	inv[MAXC-1]=pw(fac[MAXC-1],mod-2);
	for(int i=MAXC-2; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",(int)c(n+2*m-1,n-1));
	return 0;
}