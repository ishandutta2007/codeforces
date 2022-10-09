#include <iostream>
#include <vector>
#include <algorithm>

#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	vector<int> z(n + 1);
	for (int i = 0; i < n; ++i) {
		int p = min(max(a[i] - n, 0), z[i]);
		ans += max(0, (a[i] - p) - n);
		a[i] = min(a[i], n);
		z[i] -= p;
		while (z[i] > 0) {
			int c = i;
			if (c + a[i] < n)
				++z[c + a[i]];
			a[i] = max(a[i] - 1, 1);
			--z[i];
			if (a[i] == 1) {
				z[i + 1] += z[i];
				z[i] = 0;
			}
		}
		while (a[i] > 1) {
			++ans;
			int c = i;
			if (c + a[i] < n)
				++z[c + a[i]];
			--a[i];
		}
	}
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