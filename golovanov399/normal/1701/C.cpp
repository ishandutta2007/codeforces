#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> cnt(n);
	for (int i = 0; i < m; ++i) {
		cnt[nxt() - 1] += 1;
	}
	auto can = [&](int t) {
		long long need = 0;
		long long extra = 0;
		for (auto x : cnt) {
			if (x < t) {
				extra += (t - x) / 2;
			} else {
				need += x - t;
			}
		}
		return extra >= need;
	};
	int l = 0, r = 2 * m;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		(can(mid) ? r : l) = mid;
	}
	cout << r << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}