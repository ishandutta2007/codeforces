#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool check(const vector<int>& a, const vector<int>& b) {
	int l = 0, r = 0;
	while (l < (int)a.size() && r < (int)b.size()) {
		if (a[l] < b[r]) {
			++l;
		} else if (a[l] > b[r]) {
			++r;
		} else {
			return false;
		}
	}
	return true;
}

void solve() {
	int n = nxt(), m = nxt();
	const int N = 1 << n;
	vector<vector<int>> a(m, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[j][i] = nxt();
		}
	}
	vector<int> tmp(N);
	vector<int> repr(N);
	vector<char> used(N);
	for (int mask = 0; mask < N; ++mask) {
		if (used[mask]) {
			continue;
		}
		int x = mask;
		do {
			repr[x] = mask;
			used[x] = 1;
			x = (x >> 1) | ((x & 1) << (n - 1));
		} while (x != mask);
	}
	vector<int> S;
	for (int i = 0; i < N; ++i) {
		S.push_back(repr[i]);
	}
	make_unique(S);
	int sz = S.size();
	vector<set<pair<int, int>>> submasks(sz);
	for (int i = 0; i < sz; ++i) {
		for (int x = S[i]; x > 0; x = (x - 1) & S[i]) {
			if (x == S[i]) {
				continue;
			}
			int u = repr[x];
			int v = repr[S[i] ^ x];
			u = lower_bound(all(S), u) - S.begin();
			v = lower_bound(all(S), v) - S.begin();
			submasks[i].insert({u, v});
		}
	}
	// int cn = 0;
	// for (auto s : submasks) {
	// 	cn += S.size();
	// }
	// cout << cn << "\n";
	// return;
	vector<int> ans(sz, 0);
	for (int i = 0; i < m; ++i) {
		for (int mask = 1; mask < N; ++mask) {
			int b = __builtin_ctz(mask);
			tmp[mask] = tmp[mask ^ (1 << b)] + a[i][b];
		}
		for (int mask = 0; mask < N; ++mask) {
			tmp[repr[mask]] = max(tmp[repr[mask]], tmp[mask]);
		}

		for (int j = sz - 1; j >= 0; --j) {
			for (const auto& [u, v] : submasks[j]) {
				ans[j] = max(ans[j], ans[u] + tmp[S[v]]);
			}
			ans[j] = max(ans[j], tmp[S[j]]);
		}
	}
	cout << ans.back() << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}