#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
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

char s[10];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		ll ans = 0;
		if(n-i>=2) ans = 10ll * ((ll)(n-i-1)*9ll*9ll*pw(10,n-i-2) %mod + 2ll*9ll*pw(10,n-i-1) %mod) %mod;
		if(n-i==1) ans = 10ll * 9ll * 2ll;
		if(n-i==0) ans = 10ll;
		printf("%lld ",ans);
	}
	return 0;
}