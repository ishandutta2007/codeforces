#include <cstdio>

using ll = long long;

const int MOD = 1e9+7;

ll N;

ll pow(ll b, ll p)
{
	ll r=1;
	for(;p;p>>=1,b=b*b%MOD)
		if(p&1) r=r*b%MOD;
	return r;
}

int main()
{
	scanf("%lld", &N);
	ll x=pow(2ll, N);
	printf("%lld\n", x*(x+1)/2%MOD);
	return 0;
}