#include <iostream>
#include <vector>
#include <algorithm>

// #define int long long
#define all(a) a.begin(), a.end()

using namespace std;

bool check(int n, vector<int> a, int m, int k) {
	for (int i = 0; i < n; ++i)
		a[i] = (a[i] >= m) ? 1 : -1;
	vector<int> pref(n + 1);
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + a[i];
	int mn_pref = 0;
	for (int i = k - 1; i < n; ++i) {
		if (pref[i + 1] - mn_pref > 0)
			return true;
		mn_pref = min(mn_pref, pref[i - k + 2]);
	}
	return false;
}

signed main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	// cout << check(n, a, 4, k) << '\n';
	int l = 0, r = 1e9 + 228;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(n, a, m, k))
			l = m;
		else
			r = m;
	}
	cout << l << '\n';
}