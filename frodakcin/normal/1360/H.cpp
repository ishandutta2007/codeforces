#include <cstdio>
#include <algorithm>

using ll = long long;
int N, M;
ll a[200];
char s[200];

void solve()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
	{
		scanf(" %s", s);
		ll x=0;
		for(int i=0;i<M;++i)
			if(s[i]=='1')
				x|=1ll<<M-i-1;
		a[i]=x;
	}
	std::sort(a, a+N);
	ll tot = (1ll<<M)-N;
	tot = tot-1>>1;
	auto ok = [&](ll x)->bool
	{
		ll lt = x - (std::upper_bound(a, a+N, x)-a);
		return lt < tot;
	};
	ll l=-1, h=(1ll<<M)-1;
	for(;h-l>1;)
	{
		ll m=l+(h-l)/2;
		//printf("%lld: %lld\n", m, m-(std::lower_bound(a, a+N, m)-a));
		if(ok(m)) l=m;
		else h=m;
	}
	for(int i=0;i<M;++i) printf("%d", h>>M-i-1&1); printf("\n");
}

int T;
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}