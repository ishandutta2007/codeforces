#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<int> p(n);
	for (int &x: p) cin >> x;
	int l = 0, r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		vector<int> can(n, 1);
		for (int i = 0; i < mid; ++i) {
			can[p[i] - 1] = 0;
		}
		int it = 0;
		for (int i = 0; i < n; ++i) {
			if (can[i] and s[i] == t[it]) ++it;
			if (it == m) break;
		}
		if (it == m) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << "\n";
	return 0;
}