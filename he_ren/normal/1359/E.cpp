#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int MAXN = 5e5 + 5;

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

ll fac[MAXN], inv[MAXN];
inline ll c(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n] * inv[m] %mod * inv[n-m] %mod;
}

int main(void)
{
	fac[0]=1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1]*i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1]*(i+1) %mod;
	
	int n,d;
	scanf("%d%d",&n,&d);
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int x = n/i;
		if(x<d) continue;
		add_mod(ans, c(x-1,d-1));
	}
	printf("%d",ans);
	return 0;
}