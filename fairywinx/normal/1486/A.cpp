#include <iostream>
#include <vector>
#include <algorithm>

// #define int long long
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum < i * (i + 1) / 2) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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