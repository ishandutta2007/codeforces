#include <bits/stdc++.h>

using ll = long long;
int n,k;
ll p[105];

int check(ll x) {
	ll s = p[1] + x;
	for (int i = 2; i <= n; ++ i) {
		if (p[i] * 100  > k * s) return 0;
		s += p[i];
	} return 1;
}

void solve() {
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; ++ i) scanf("%lld",&p[i]);
	ll l = 0, r = 1e14, ans;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) { ans = mid; r = mid - 1; }
		else l = mid + 1;
	} printf("%lld\n",ans);
	return ;
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}