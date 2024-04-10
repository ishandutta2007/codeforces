#include <bits/stdc++.h>

using ll = long long;

void solve() {
	ll n;
	scanf("%lld",&n);
	for (ll i = 0; i * 2020 <= n; ++ i) {
		ll d = n - i * 2020;
		if (d < 0) break;
		if (d % 2021 == 0) {
			puts("Yes");
			return ;
		} 
	} puts("No");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}