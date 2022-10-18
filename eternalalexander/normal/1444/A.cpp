#include <bits/stdc++.h>
#define ll long long
ll p,q;

ll redu(ll x,ll d,int cnt) {
	int c1 = 0;
	ll y = x;
	while (x%d==0) { x /= d; c1 ++; }
	while (c1 >= cnt) { y /= d; c1 --; }
	return y;
}
	

void solve() {
	scanf("%lld%lld",&p,&q);
	ll ans = 0;
	for (ll i = 2; i*i <= q; ++ i) {
		if (q%i) continue;
		int cnt = 0;
		while (q % i == 0) {
			cnt ++;
			q /= i;
		}
		ans = std::max(ans,redu(p,i,cnt));
	} if (q != 1) ans = std::max(ans,redu(p,q,1));
	printf("%lld\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}