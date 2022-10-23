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
	int ans = n;
	for (int init = 1; init < n; ++init) {
		long long sum = accumulate(a.begin(), a.begin() + init, 0ll);
		int i = init;
		bool ok = true;
		int mn = init;
		while (i < n) {
			long long cur = 0;
			int len = 0;
			while (i < n && cur < sum) {
				cur += a[i++];
				++len;
			}
			if (cur != sum) {
				ok = false;
				break;
			} else {
				mn = max(mn, len);
			}
		}
		if (ok) {
			ans = min(ans, mn);
		}
	}
	cout << ans << "\n";
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