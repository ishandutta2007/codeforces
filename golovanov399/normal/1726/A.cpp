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

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	int ans = a[n - 1] - a[0];
	for (int i = 1; i < n; ++i) {
		ans = max(ans, a[i] - a[0]);
	}
	for (int i = 0; i < n - 1; ++i) {
		ans = max(ans, a[n - 1] - a[i]);
	}
	for (int i = 0; i < n; ++i) {
		ans = max(ans, a[i] - a[(i + 1) % n]);
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}