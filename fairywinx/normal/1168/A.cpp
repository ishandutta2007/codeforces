#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int n, vector<int> &a, int m, int val) {
	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] + val >= m) {
			int r = (a[i] + val) % m;
			if (r < c) {
				if (a[i] + val < c)
					return false;
				c = max(c, a[i]);
			}
		} else {
			if (a[i] + val < c)
				return false;
			c = max(c, a[i]);
		}
	}
	return true;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int l = -1, r = 1e9 + 228;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (check(n, a, m, mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	// int t;
	// cin >> t;
	// while (t--)
	// 	solve();
}