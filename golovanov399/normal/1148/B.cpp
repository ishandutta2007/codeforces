#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	long long ta = nxt(), tb = nxt();
	int k = nxt();
	vector<long long> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int j = 0; j < m; ++j) {
		b[j] = nxt();
	}

	long long ans = 0;
	for (int i = 0; i <= k && i <= n; ++i) {
		if (i == n) {
			cout << "-1\n";
			return 0;
		}
		long long mn = a[i] + ta;
		int l = lower_bound(all(b), mn) - b.begin();
		int r = l + k - i;
		r = min(r, m);
		if (r == m) {
			cout << "-1\n";
			return 0;
		}
		ans = max(ans, b[r] + tb);
	}
	cout << ans << "\n";

	return 0;
}