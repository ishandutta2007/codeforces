// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 105;

int n, K, p[N];

bool inline check(LL x) {
	x += p[0];
	for (int i = 1; i < n; i++) {
		if (100ll * p[i] > x * K) return false;
		x += p[i];
	}
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &K);
		for (int i = 0; i < n; i++) scanf("%d", p + i);
		LL l = 0, r = 1e16;
		while (l < r) {
			LL mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%lld\n", r);
	}
	return 0;
}