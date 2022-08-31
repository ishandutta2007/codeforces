#include <bits/stdc++.h>

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
	vector<int> a(m);
	for (int i = 0; i < n; ++i) {
		a[nxt() % m] += 1;
	}
	int ans = 0;
	for (int i = 1; i * 2 < m; ++i) {
		int x = a[i], y = a[m - i];
		if (!x && !y) {
			continue;
		} else {
			ans += max(1, abs(x - y));
		}
	}
	ans += !!a[0];
	if (m % 2 == 0) {
		ans += !!a[m / 2];
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