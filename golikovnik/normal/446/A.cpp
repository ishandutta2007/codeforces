#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define szof(x) int32_t((x).size())
#define dbg(x) cerr << #x << " = " << x << "\n";

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	if (n < 3) {
		cout << n << "\n";
		return 0;
	}
	vector<int> a(n); for (int &x: a) cin >> x;
	vector<int> pref(n), suff(n);
	pref[0] = 1;
	for (int i = 1; i < n; ++i) {
		pref[i] = (a[i] > a[i - 1] ? pref[i - 1] + 1 : 1);
	}	
	suff[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i) {
		suff[i] = (a[i] < a[i + 1]  ? suff[i + 1] + 1 : 1);
	}
	int ans = 0;
	for (int i = 1; i + 1 < n; ++i) {
		ans = max(ans, pref[i - 1] + 1);
		ans = max(ans, suff[i + 1] + 1);
		if (a[i + 1] - a[i - 1] >= 2) {
			ans = max(ans, 1 + pref[i - 1] + suff[i + 1]);
		}
	} 	
	ans = max(ans, suff[1] + 1);
	ans = max(ans, pref[n - 2] + 1);
	cout << ans << "\n";
	return 0;	
}