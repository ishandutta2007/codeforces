#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		b[i] = nxt();
	}
	sort(all(b));
	vector<pair<int, int>> segs;
	for (int x : b) {
		if (segs.empty() || segs.back().second < x - 1) {
			segs.push_back({x - 1, x});
		} else {
			segs.back().second = x;
		}
	}
	for (auto [l, r] : segs) {
		sort(a.begin() + l, a.begin() + r + 1);
	}
	puts(is_sorted(all(a)) ? "YES" : "NO");
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}