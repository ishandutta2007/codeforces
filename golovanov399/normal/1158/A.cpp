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
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int i = 0; i < m; ++i) {
		b[i] = nxt();
	}
	sort(all(a));
	sort(all(b));
	if (b[0] < a.back()) {
		cout << "-1\n";
		return 0;
	}

	long long ans = accumulate(all(a), 0ll) * m;
	for (int x : b) {
		ans += x - a.back();
	}
	if (a.back() != b[0]) {
		ans += a[n - 1] - a[n - 2];
	}

	cout << ans << "\n";

	return 0;
}