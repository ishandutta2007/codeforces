#include <bits/stdc++.h>

#include <vector>

using std::vector;

template <typename V = int>
struct Fenwick {
	int n;
	vector<V> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, const V& x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	V get(int pos) const {
		V res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	V get(int l, int r) const {
		return get(r - 1) - get(l - 1);
	}

	int get_min_atleast(V x) const {
		int res = 0;
		for (int i = 1 << (31 - __builtin_clz(n)); i; i >>= 1) {
			if (res + i > n) {
				continue;
			}
			if (a[res + i - 1] < x) {
				res += i;
				x -= a[res - 1];
			}
		}
		return res;
	}

	int get_max_atmost(V x) const {
		int res = 0;
		for (int i = 1 << (31 - __builtin_clz(n)); i; i >>= 1) {
			if (res + i > n) {
				continue;
			}
			if (a[res + i - 1] <= x) {
				res += i;
				x -= a[res - 1];
			}
		}
		return res - 1;
	}
};

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	map<int, vector<pair<int, int>>> by_col;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			by_col[nxt()].push_back({i, j});
		}
	}
	long long ans = 0;
	for (const auto& p : by_col) {
		const auto& v = p.second;
		vector<int> ys;
		for (auto pr : v) {
			ys.push_back(pr.second);
		}
		make_unique(ys);
		const int sz = ys.size();
		Fenwick<long long> fy(sz);
		Fenwick<int> f(sz);
		long long sx = 0;
		long long sy = 0;
		int cnt = 0;
		for (auto [x, yy] : v) {
			auto y = lower_bound(all(ys), yy) - ys.begin();
			ans += 1ll * cnt * x - sx + 1ll * (2 * f.get(y) - cnt) * yy - 2 * fy.get(y) + sy;
			sx += x;
			sy += yy;
			cnt += 1;
			fy.add(y, yy);
			f.add(y, 1);
		}
	}
	cout << ans << "\n";
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