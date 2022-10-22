#include <bits/stdc++.h>
typedef long long ll;
int main()
{
	ll N,M;
	std::scanf("%lld %lld",&N,&M);
	ll ans = 0, tmp = 0, x;
	while (N--)
	{
		std::scanf("%lld",&x);
		tmp += x;
		ans = tmp/M;
		tmp %= M;
		std::printf("%lld%c",ans,N?' ':'\n');
	}
}