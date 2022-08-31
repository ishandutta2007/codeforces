#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void remax(int& x, int y) {
	x = (x < y) ? y : x;
}

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void remax(int pos, int x) {
		while (pos < n) {
			::remax(a[pos], x);
			pos |= pos + 1;
		}
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			::remax(res, a[pos]);
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

void solve() {
	int n = nxt(), v = nxt();
	vector<pair<long long, long long>> a(n + 1);
	vector<int> t(n + 1), pos(n + 1);
	for (int i = 1; i <= n; ++i) {
		t[i] = nxt();
	}
	for (int i = 1; i <= n; ++i) {
		pos[i] = nxt();
	}
	vector<long long> xs;
	for (int i = 0; i <= n; ++i) {
		long long x = t[i];
		long long y = pos[i];
		a[i] = {x * v - y, x * v + y};
		a[i].first *= -1;
		a[i].second *= -1;
		xs.push_back(a[i].second);
	}
	sort(all(a));
	make_unique(xs);
	const int sz = xs.size();
	Fenwick f(sz);
	for (auto [x, y] : a) {
		int idx = lower_bound(all(xs), y) - xs.begin();
		if (x == 0 && y == 0) {
			cout << f.get(idx) << "\n";
			return;
		}
		f.remax(idx, f.get(idx) + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}