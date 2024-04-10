#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e9 + 6;
const int MAXM = 2e5 + 5;
const int MAXD = 1e9 + 5;
const int mod = 998244353;

inline ll pw(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res = res*a %mod;
		a = a*a %mod;
		b>>=1;
	}
	return res;
}

int b[MAXM];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	ll inv2 = pw(2,mod-2);
	ll ans = pw(d,n-b[m]*2);
	for(int i=1; i<=m; ++i)
	{
		int t = b[i]-b[i-1];
		ans = ans * (pw(d,t<<1)+pw(d,t)) %mod * inv2 %mod;
	}
	printf("%lld",ans);
	return 0;
}