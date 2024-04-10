
#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

struct Shit {
	int val;
	long long cnt;
};

Shit merge(const Shit& a, const Shit& b) {
	if (a.val != b.val) {
		return (a.val < b.val) ? a : b;
	} else {
		return {a.val, (a.cnt + b.cnt) % mod};
	}
}

void solve() {
	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].second = nxt();
		a[i].first = nxt();
	}
	sort(all(a), [](const pair<int, int>& p, const pair<int, int>& q) {
		return p.second < q.second;
	});
	vector<Shit> dp(n + 1, {mod, 0});
	Shit ans = {mod, 0};
	int mnf = 0;
	for (auto p : a) {
		mnf = max(mnf, p.first);
	}
	for (int i = 0; i < n; ++i) {
		int l = -1, r = i;
		while (r > l + 1) {
			int m = (l + r) / 2;
			if (a[m].second <= a[i].first) {
				l = m;
			} else {
				r = m;
			}
		}
		Shit res;
		if (r == 0) {
			res = {a[i].first, 1};
		} else {
			res = {a[i].first + dp[r].val, dp[r].cnt};
		}
		if (mnf < a[i].second) {
			ans = merge(ans, res);
		}
		// cerr << "[" << a[i].first << ", " << a[i].second << "]: " << res.val << " " << res.cnt << "\n";
		res.val -= a[i].second;
		dp[i + 1] = merge(dp[i], res);
	}
	cout << ans.cnt << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}