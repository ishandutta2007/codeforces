#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ll n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);
	k += 2;
	if (n + m < k) {
		puts("-1");
		return 0;
	}
	ll ans = 0, x;
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		x = k - r;
		if (x <= 0 || x > m)
			continue;
		ans = max(ans, (n / r) * (m / x));
	}
	swap(n, m);
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		x = k - r;
		if (x <= 0 || x > m)
			continue;
		ans = max(ans, (n / r) * (m / x));
	}
	printf("%lld\n", ans);
	return 0;
}