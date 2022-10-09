#include <iostream>
#include <vector>
#include <algorithm>

#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n, u, v;
	cin >> n >> u >> v;
	int last;
	cin >> last;
	int ans = 2e9 + 228;
	for (int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		if (abs(a - last) == 1)
			ans = min(ans, min(u, v));
		if (abs(a - last) > 1)
			ans = 0;
		last = a;
	}
	ans = min(ans, min(u + v, 2 * v));
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// solve();
	int t;
	cin >> t;
	while (t--)
		solve();
}