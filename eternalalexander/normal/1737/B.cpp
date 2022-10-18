#include <bits/stdc++.h>
using ll = long long;
ll check(ll x) {
	ll sum = 0;
	ll l = 0, r = 1e9, ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (mid * mid <= x) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	} sum += ans;
	l = 0, r = 1e9, ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (mid * (1 + mid) <= x) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	} sum += ans;
	l = 0, r = 1e9, ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (mid * (2 + mid) <= x) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	} sum += ans;
	return sum;
}

void solve() {
	ll l,r;
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",check(r) - check(l - 1));
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}