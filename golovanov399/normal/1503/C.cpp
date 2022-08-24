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
	vector<pair<int, int>> a(n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = nxt();
		ans += a[i].second;
	}
	sort(all(a));
	int right = a[0].first;
	for (const auto& [x, c] : a) {
		if (x > right) {
			ans += x - right;
		}
		right = max(right, x + c);
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}