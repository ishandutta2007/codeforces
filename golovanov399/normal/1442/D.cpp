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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void remax(long long& x, long long y) {
	x = max(x, y);
}

void solve() {
	int n = nxt(), k = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(nxt());
		generate(all(a[i]), nxt);
	}

	vector<long long> total(n);
	for (int i = 0; i < n; ++i) {
		total[i] = accumulate(all(a[i]), 0ll);
	}

	auto insert_to_knap = [&](vector<long long>& knap, int l, long long x) {
		for (int i = k - l; i >= 0; --i) {
			if (knap[i] > -1) {
				remax(knap[i + l], knap[i] + x);
			}
		}
	};

	vector<vector<long long>> knaps = {vector<long long>(k + 1, -1)};
	knaps[0][0] = 0;

	long long ans = 0;
	auto handle = [&](const vector<long long>& knap, int pos) {
		long long cur = 0;
		for (int j = 0; j <= (int)a[pos].size() && j <= k; ++j) {
			if (knap[k - j] > -1) {
				remax(ans, cur + knap[k - j]);
			}
			if (j < (int)a[pos].size()) {
				cur += a[pos][j];
			}
		}
	};

	function<void(int, int)> rec = [&](int l, int r) {
		if (r == l + 1) {
			handle(knaps.back(), l);
			return;
		}
		int m = (l + r) / 2;
		auto tmp = knaps.back();
		for (int i = l; i < m; ++i) {
			insert_to_knap(tmp, a[i].size(), total[i]);
		}
		knaps.push_back(tmp);
		rec(m, r);
		knaps.pop_back();
		tmp = knaps.back();
		for (int i = m; i < r; ++i) {
			insert_to_knap(tmp, a[i].size(), total[i]);
		}
		knaps.push_back(tmp);
		rec(l, m);
		knaps.pop_back();
	};

	rec(0, n);
	cout << ans << "\n";

	// vector<vector<long long>> pre_knap(n + 1, vector<long long>(k + 1, -1));
	// auto suf_knap = pre_knap;
	// pre_knap[0][0] = 0;
	// for (int i = 0; i < n; ++i) {
	// 	pre_knap[i + 1] = pre_knap[i];
	// 	for (int j = 0; j + (int)a[i].size() <= k; ++j) {
	// 		if (pre_knap[i][j] > -1) {
	// 			remax(pre_knap[i + 1][j + (int)a[i].size()], pre_knap[i][j] + total[i]);
	// 		}
	// 	}
	// }
	// suf_knap[n][0] = 0;
	// for (int i = n - 1; i >= 0; --i) {
	// 	suf_knap[i] = suf_knap[i + 1];
	// 	for (int j = 0; j + (int)a[i].size() <= k; ++j) {
	// 		if (suf_knap[i + 1][j] > -1) {
	// 			remax(suf_knap[i][j + (int)a[i].size()], suf_knap[i + 1][j] + total[i]);
	// 		}
	// 	}
	// }

}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}