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
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	function<int(int, int)> f = [&](int l, int r) {
		if (l + 1 == r) {
			return 0;
		}
		int m = (l + r) / 2;
		int ans = f(l, m);
		if (ans == -1) {
			return -1;
		}
		if (auto x = f(m, r); x == -1) {
			return -1;
		} else {
			ans += x;
		}
		if (a[m - 1] < a[m]) {
			return ans;
		} else if (a[r - 1] < a[l]) {
			rotate(a.begin() + l, a.begin() + m, a.begin() + r);
			return ans + 1;
		} else {
			return -1;
		}
	};
	cout << f(0, n) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}