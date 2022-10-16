#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<int> pref(n + 1);
	partial_sum(a.begin(), a.end(), pref.begin() + 1);
	while (m--) {
		int b;
		cin >> b;
		int f = lower_bound(pref.begin(), pref.end(), b) - pref.begin();
		int k = b - pref[f - 1];
		cout << f << " " << k << "\n";
	}
	return 0;
}