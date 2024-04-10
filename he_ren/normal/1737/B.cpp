#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll l, r;
	scanf("%lld%lld",&l,&r);
	
	auto calc = [&] (ll k)
	{
		ll tl = k * k, tr = (k+1) * (k+1) - 1, res = 0;
		while(tl <= tr)
		{
			if(l <= tl && tl <= r) res += 1;
			tl += k;
		}
		return res;
	};
	
	ll x = sqrtl(l) + 5, y = sqrtl(r) + 5;
	while(x * x > l) --x;
	while(y * y > r) --y;
	
	if(x == y)
	{
		printf("%lld\n",calc(x));
	}
	else
	{
		printf("%lld\n",(y - x - 1) * 3 + calc(x) + calc(y));
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}