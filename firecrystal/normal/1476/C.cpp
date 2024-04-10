// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

LL ans;

int n, c[N], a[N], b[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n); ans = 0;
		for (int i = 1; i <= n; i++) scanf("%d", c + i);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) scanf("%d", b + i);
		LL s = -9e18;
		for (int i = 2; i <= n; i++) {
			s = max(abs(a[i] - b[i]) + 2ll, s + min(a[i], b[i]) - 1 + c[i - 1] - max(a[i], b[i]) + 2);
			ans = max(ans, s + c[i] - 1);
			if (a[i + 1] == b[i + 1]) s = -1e18;
		}
		printf("%lld\n", ans);
	}
	return 0;
}