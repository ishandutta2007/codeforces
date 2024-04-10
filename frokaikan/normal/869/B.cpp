#include <bits/stdc++.h>
#define constant const constexpr
typedef long long ll;
ll ans = 1LL;
int main()
{
	ll a,b;
	std::scanf("%I64d %I64d",&a,&b);
	for (ll i=a+1;i<=b;++i)
	{
		ans = ans*i%10;
		if (ans == 0) break;
	}
	std::printf("%I64d",ans);
}