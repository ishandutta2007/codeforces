#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	vector<pair<int, int>> a(n);
	long long total = 0;
	for (int i = 0; i < n; ++i) {
		int s = nxt(), g = nxt();
		a[i] = {s, s + g};
		total += s;
	}

	for (int i = 1; i < n; ++i) {
		int l = a[i - 1].first - 1, r = a[i - 1].second + 1;
		a[i].first = max(a[i].first, l);
		a[i].second = min(a[i].second, r);
		if (a[i].first > a[i].second) {
			puts("-1");
			return 0;
		}
	}

	vector<int> ans(n);
	ans[n - 1] = a[n - 1].second;
	for (int i = n - 2; i >= 0; --i) {
		ans[i] = ans[i + 1] + 1;
		while (ans[i] > a[i].second) {
			--ans[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		total -= ans[i];
	}

	printf("%lld\n", -total);
	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}