#include <bits/stdc++.h>
 
#define int long long
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<int> t(n);
	for (int &x: t) cin >> x;
	vector<int> pref_all(n + 1), pref(n + 1);
	for (int i = 1; i < n + 1; ++i) {
		pref_all[i] = pref_all[i - 1] + a[i - 1];
		pref[i] = pref[i - 1] + a[i - 1] * t[i - 1];
	}
	int ans = 0;
	for (int start = 1; start <= n - k + 1; ++start) {
		int score = 0;
		score += pref[start - 1];
		score += pref_all[start + k - 1] - pref_all[start - 1];
		score += pref[n] - pref[start + k - 1];
		ans = max(ans, score);
	}
	cout << ans << "\n";
	return 0;
}