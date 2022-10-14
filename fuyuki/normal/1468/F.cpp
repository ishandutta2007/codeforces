#include <bits/stdc++.h>
using ll = long long;
int main() {
	ll x,y,u,v;
	int t;scanf("%d",&t);
	while(t-->0) {
		int n;ll ans = 0; std::map<ll,std::map<ll,ll> > S;
		scanf("%d",&n);
		while (n--) {
			scanf("%lld%lld%lld%lld",&x,&y,&u,&v);
			ll dx = u - x, dy = v - y;
			ll g = std::__gcd(std::abs(dx),std::abs(dy));
			dx /= g; dy /= g;
		//	printf("(%lld %lld)\n",dx,dy);
			ans += S[-dx][-dy];
			S[dx][dy] ++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}