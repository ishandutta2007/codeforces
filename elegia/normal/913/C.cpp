#include <cstdio>

#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

ll c[31];

int main() {
	int n, lit;
	ll l = 0, r = 1LL << 60, mid, slit, rem;
	scanf("%d%d", &n, &lit);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &c[i]);
	for (int i = 1; i < n; ++i)
		if (c[i] > c[i - 1] * 2)
			c[i] = c[i - 1] * 2;
	for (int i = n - 2; i >= 0; --i)
		c[i] = min(c[i], c[i + 1]);
	while (l < r) {
		mid = (l + r) / 2;
		rem = mid;
		slit = 0;
		bool flag = false;
		for (int i = n - 1; i >= 0; --i) {
			ll times = rem / c[i];
			slit += times << i;
			if (slit < 0 || (times >> (32 - i)))
				flag = true;
			rem %= c[i];
		}
		if (slit >= lit || flag)
			r = mid;
		else
			l = mid + 1;
	}
	printf("%lld\n", l);
	return 0;
}