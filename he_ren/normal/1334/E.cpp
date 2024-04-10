#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int MAXN = 1e3 + 5;

ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}

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

ll fac[MAXN],inv[MAXN];
inline ll c(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n]*inv[m] %mod * inv[n-m] %mod;
}

ll N;


struct Node
{
	ll num;
	int cnt;
}p[MAXN];
int tot=0;

ll path(ll x)
{
	int sum=0;
	ll res=1;
	for(int i=1; i<=tot; ++i)
	{
		ll num = p[i].num;
		int cnt=0;
		while(x%num==0) ++cnt, x/=num;
		
		sum += cnt;
		res = res * c(sum,cnt) %mod;
	}
	return res;
}

void solve(void)
{
	ll u,v;
	scanf("%lld%lld",&u,&v);
	ll div = gcd(u,v);
	printf("%lld\n",path(u/div) * path(v/div) %mod);
}

int main(void)
{
	fac[0]=1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1]*i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	scanf("%lld",&N);
	
	ll tmp = N, sn = sqrt(N);
	tot=0;
	for(int i=2; i<=sn && tmp>1; ++i)
		if(tmp%i==0)
		{
			p[++tot] = (Node){i,0};
			while(tmp%i==0) ++p[tot].cnt, tmp/=i;
		}
	if(tmp>1) p[++tot] = (Node){tmp,1};
	
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}