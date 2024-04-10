#include <bits/stdc++.h>
typedef long long ll;
ll mod = 1e9 + 7;
ll pow(ll x,ll n)
{
	ll ans = 1LL, tmp = x;
	while (n)
	{
		if (n&1) ans = ans*tmp%mod;
		tmp = tmp*tmp%mod;
		n >>= 1;
	}
	return ans;
}
ll m,n,k;
int main()
{
	std::scanf("%I64d %I64d %I64d",&m,&n,&k);
	if (k == 1)
	{
		std::printf("%I64d\n",pow(pow(2,n-1),m-1));
	}
	else
	{
		if ((n+m)&1) std::printf("0\n");
		else std::printf("%I64d\n",pow(pow(2,n-1),m-1));
	}
}