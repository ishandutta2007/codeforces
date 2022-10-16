#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	long double l = 0.0, r = 1.1e9;
	for (int ITER = 0; ITER < 1000; ++ITER) {
		long double mid = (l + r) / 2;
		long double w = mid;
		bool fail = 0;
		for (int i = 0; i < n; ++i) {
			long double coef = (m + w) / a[i];
			if (coef > w) {
				l = mid;
				fail = 1;
				break;
			}
			w -= coef;
			coef = (m + w) / b[(i + 1) % n];
			if (coef > w) {
				l = mid;
				fail = 1;
				break;
			}
			w -= coef;
		}
		if (w < 0 || fail) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (l > 1e9 + 1) {
		cout << -1 << "\n";
	} else {
		cout << setprecision(10) << fixed << l << "\n";
	}
	return 0;	
}