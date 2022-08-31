#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), d = nxt();
	vector<int> min_depth(n + 1);
	vector<int> max_depth(n + 1);
	vector<int> depth(n);
	for (int i = 1; i < n; ++i) {
		depth[i] = depth[(i - 1) / 2] + 1;
	}
	for (int i = 1; i <= n; ++i) {
		min_depth[i] = min_depth[i - 1] + depth[i - 1];
	}
	for (int i = 0; i <= n; ++i) {
		max_depth[i] = i * (i - 1) / 2;
	}
	if (max_depth[n] < d || d < min_depth[n]) {
		cout << "NO\n";
		return;
	}
	vector<int> pars(n);
	function<void(int, int, int, int)> build = [&](int v, int l, int r, int d) {
		int n = (r - l);
		if (n < 0) {
			return;
		}
		// cerr << v << " " << l << " " << r << " " << d << "\n";
		if (n == 0) {
			assert(d == 0);
			// pars[l] = v;
			return;
		}
		d -= n;
		int left = 0;
		while (left < n && (d < min_depth[left] + min_depth[n - left] || max_depth[left] + max_depth[n - left] < d)) {
			++left;
		}
		assert(left < n);
		if (left == 0) {
			pars[l] = v;
			build(l, l + 1, r, d);
			return;
		}
		// cerr << "left = " << left << "\n";
		pars[l] = pars[l + left] = v;
		int left_d = -1;
		for (int x : {min_depth[left], max_depth[left], d - min_depth[n - left], d - max_depth[n - left]}) {
			if (x >= 0 && x <= d && x >= min_depth[left] && x <= max_depth[left] && d - x >= min_depth[n - left] && d - x <= max_depth[n - left]) {
				left_d = x;
			}
		}
		build(l, l + 1, l + left, left_d);
		build(l + left, l + left + 1, r, d - left_d);
	};
	build(0, 1, n, d);
	cout << "YES\n";
	for (int i = 1; i < n; ++i) {
		cout << pars[i] + 1 << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}