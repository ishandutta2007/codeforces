#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll n,x;
	scanf("%lld%lld",&n,&x);
	
	auto calc = [&] (ll l,ll r)
	{
		if(l>r) return 0ll;
		return (l + r) * (r - l + 1) / 2;
	};
	
	auto get = [&] (ll k)
	{
		if(k >= n)
			return calc(1,n) + calc(n-(k-n), n-1);
		else
			return calc(1,k);
	};
	
	ll l = 1, r = 2 * n - 1;
	while(l<r)
	{
		ll mid = (l+r)>>1;
		if(get(mid) >= x) r = mid;
		else l = mid + 1;
	}
	
	printf("%lld\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}