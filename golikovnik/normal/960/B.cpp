#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int sqr(int x) {
	return x * x;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	vector<int> a(n), b(n);
	set<pair<int, int>, greater<pair<int, int>>> q;
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	for (int i = 0; i < n; ++i) {
		q.insert({sqr(a[i] - b[i]), i});
	}
	for (int i = 0; i < k1 + k2; ++i) {
		int j = q.begin()->second;
		int new_val = -1;
		if (sqr(a[j] - b[j] + 1) < sqr(a[j] - b[j] - 1)) {
			new_val = sqr(a[j] - b[j] + 1);
			++a[j];
		} else {
			new_val = sqr(a[j] - b[j] - 1);
			--a[j];
		}
		q.erase(q.begin());
		q.insert({new_val, j});
	}
	int ans = 0;
	for (auto x: q) ans += x.first;
	cout << ans << "\n";
	return 0;
}