#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n;
	cin >> n;
	vector<int> s(n);
	for (int &x: s) cin >> x;
	vector<int> c(n);
	for (int &x: c) cin >> x;
	int ans = LLONG_MAX;
	for (int j = 1; j + 1 < n; ++j) {
		int ii = -1;
		for (int i = 0; i < j; ++i) {
			if (s[i] < s[j] and (ii < 0 or c[i] < c[ii])) ii = i;
		}
		int kk = n;
		for (int k = n - 1; k > j; --k) {
			if (s[k] > s[j] and (kk == n or c[k] < c[kk])) kk = k;
		}
		if (ii >= 0 and kk < n) ans = min(ans, c[ii] + c[j] + c[kk]);
	}
	if (ans == LLONG_MAX) {
		cout << "-1\n";
		return 0;
	}
	cout << ans << "\n";
	return 0;
}