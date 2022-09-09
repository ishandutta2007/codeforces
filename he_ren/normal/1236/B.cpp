#include<cstdio>
typedef long long ll;
const int mod = 1e9 + 7;

inline ll pw(ll a,ll b)
{
	a = (a%mod+mod)%mod;
	
	ll res=1;
	while(b)
	{
		if(b&1ll) res = res*a %mod;
		a = a*a%mod;
		b>>=1ll;
	}
	return res;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",(int)pw( pw(2,m)-1 , n));
	return 0;
}