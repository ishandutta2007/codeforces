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

void solve() {
	int n = nxt();
	vector<int> a, b;
	for (int i = 0; i < 2 * n; ++i) {
		int x = abs(nxt()), y = abs(nxt());
		(x ? a : b).push_back(x + y);
	}
	long double ans = 0;
	sort(all(a));
	sort(all(b));
	for (int i = 0; i < n; ++i) {
		ans += hypotl(a[i], b[i]);
	}
	cout << ans << "\n";
}

int main() {
	cout << setprecision(12) << fixed;
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}