#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

int ans[101];

void anss(vector<int> a, int l, int r, int d) {
	if (r < l)
		return;
	if (r == l) {
		ans[l] = d;
		return;
	}
	int mx = l;
	for (int i = l; i <= r; ++i) {
		if (a[mx] < a[i])
			mx = i;
	}
	ans[mx] = d;
	anss(a, l, mx - 1, d + 1);
	anss(a, mx + 1, r, d + 1);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	anss(a, 0, n - 1, 0);
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}

signed main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}