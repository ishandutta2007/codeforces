#include <bits/stdc++.h>
using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	long long g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		long long x, y; scanf("%lld%lld", &x, &y);
		if (y < x) {
			printf("%lld\n", x + y);
			continue;
		}
		long long n = (x + y) / 2;
		if (n < x + x) {
			printf("%lld\n", n);
			continue;
		}
		long long b1 = y % x, b2 = 0;
		printf("%lld\n", y - b1 / 2);
		n = y - b1 / 2;
		assert(n % x == y % n);
	}
	return 0;
}