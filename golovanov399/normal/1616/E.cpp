#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

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

void solve() {
	int n = nxt();
	string s, t;
	cin >> s >> t;

	vector<vector<int>> where(26);
	for (int i = 0; i < n; ++i) {
		where[s[i] - 'a'].push_back(i);
	}
	for (auto& v : where) {
		reverse(all(v));
	}

	long long ans = 1e18;
	long long cur = 0;
	Fenwick f(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < t[i] - 'a'; ++j) {
			if (!where[j].empty()) {
				ans = min(ans, cur + where[j].back() - f.get(where[j].back()));
			}
		}
		if (where[t[i] - 'a'].empty()) {
			break;
		}
		cur += where[t[i] - 'a'].back() - f.get(where[t[i] - 'a'].back());
		f.add(where[t[i] - 'a'].back(), 1);
		where[t[i] - 'a'].pop_back();
	}
	if (ans > 1e17) {
		ans = -1;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}