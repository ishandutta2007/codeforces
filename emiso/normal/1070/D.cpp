#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	ll bag = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (bag) {
			a[i] -= min(a[i], m - bag);
			++ans;
		}
		ans += a[i] / m;
		bag = a[i] % m;
	}
	if (bag)
		++ans;
	printf("%lld\n", ans);
	return 0;
}