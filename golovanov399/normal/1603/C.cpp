#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

constexpr int mod = 998'244'353;

void solve() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	vector<int> cur_right(n), cur_left(n);
	vector<int> cur_cnt(n);
	long long s = 0;

	function<void(int, int)> set_right = [&](int i, int x) {
		if (cur_right[i] <= x) {
			return;
		}
		// ceil(a[i] / k) <= x
		// a[i] / k <= x
		// a[i] <= k * x
		// k >= a[i] / x
		int k = (a[i] + x - 1) / x;
		s -= 1ll * (i + 1) * (cur_cnt[i] - 1);
		cur_cnt[i] = k;
		cur_left[i] = a[i] / k;
		cur_right[i] = (a[i] + k - 1) / k;
		s += 1ll * (i + 1) * (cur_cnt[i] - 1);
		if (i > 0) {
			set_right(i - 1, cur_left[i]);
		}
	};

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		cur_cnt[i] = 1;
		cur_left[i] = cur_right[i] = a[i];
		if (i > 0) {
			set_right(i - 1, a[i]);
		}
		ans += s % mod;
	}
	cout << ans % mod << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}