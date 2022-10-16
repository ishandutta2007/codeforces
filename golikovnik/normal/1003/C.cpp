#include <bits/stdc++.h>

// #define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<int> pref(n + 1);
	partial_sum(a.begin(), a.end(), pref.begin() + 1);
	double ans = 0.0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int len = j - i + 1;
			if (len >= k) {
				ans = max(ans, (pref[j + 1] - pref[i]) * 1.0 / len);
			}
		}
	}
	cout << setprecision(10) << fixed << ans << "\n";
	return 0;	
}