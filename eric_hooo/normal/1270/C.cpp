#include <bits/stdc++.h>
using namespace std;

int st[1000], top;

void print(long long x) {
	for (int i = 52; i >= 0; i--) {
		printf("%lld", x >> i & 1);
	}
	printf("\n");
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		long long a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			a += x, b ^= x;
		}
		vector <long long> ans;
		ans.push_back(b), a += ans.back(), b ^= ans.back();
		long long delta = a - 2 * b;
		long long x = 0;
		for (int i = 0; i < 50; i++) {
			if (delta >> i & 1) {
				long long last = a + x - 2 * (b ^ x);
				x ^= 1ll << i;
				long long now = a + x - 2 * (b ^ x);
			}
		}
		ans.push_back(x), a += x, b ^= x;
		assert(a == 2 * b);
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%lld ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}