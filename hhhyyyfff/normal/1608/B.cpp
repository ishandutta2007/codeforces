#include <bits/stdc++.h>

using namespace std;

int t, n, a, b, ans[100001], ind, l, r;

void inc() {
	ans[ind++] = ++r;
}

void dec() {
	ans[ind++] = --l;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &a, &b);
		if (a + b > n - 2 || abs(a - b) > 1) {
			puts("-1");
			continue;
		}
		ans[1] = l = r = 0;
		ind = 2;
		if (a == b) {
			while (a--) {
				inc();
				dec();
			}
			inc();
			while (ind <= n) inc();
		} else if (a == b + 1) {
			while (a--) {
				inc();
				dec();
			}
			while (ind <= n) dec();
		} else {
			while (b--) {
				dec();
				inc();
			}
			while (ind <= n) inc();
		}
		for (int i = 1; i < n; ++i) printf("%d ", ans[i] - l + 1);
		printf("%d\n", ans[n] - l + 1);
	}
	return 0;
}