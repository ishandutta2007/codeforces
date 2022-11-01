// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

const int N = 2e5 + 5;

int n;
LL K, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &K);
		LL d = 0;
		for (int i = 1; i <= n; i++) {
			LL x; scanf("%lld", &x);
			a[i] = x;
		}
		bool ok = false;
		sort(a + 1, a + 1 + n);
		for (int i = 1; i < n; i++)
			d = gcd(d, a[i + 1] - a[i]);
		for (int i = 1; i <= n; i++) {
			if ((K - a[i]) % d == 0) {
				ok = true;
				puts("YES");
				break;
			}
		}
		if (!ok) puts("NO");
	}
	return 0;
}