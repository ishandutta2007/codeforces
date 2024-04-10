#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	int l = 0, r = 0;
	int sl = 0, sr = 0;
	int ans = 0;
	while (l + r <= n) {
		if (sl == sr) {
			ans = sl;
			sl += a[l], ++l;
			continue;
		}
		while (sl < sr) {
			sl += a[l], ++l;
		}
		if (l + r > n) continue;
		while (sl > sr) {
			sr += a[n - r - 1], ++r;
		}
	}
	cout << ans << "\n";
	return 0;	
}