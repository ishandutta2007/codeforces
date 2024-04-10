#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T;
	for(cin >> T; T; T --) {
		int n;
		i64 x;
		cin >> n >> x;
		i64 ans = x < n ? x * (x - 1) / 2 : (x - n + x - 1) * n / 2;

		x = min(x, (i64)n);
		vector<i64> a(n);
		for(int i = 0; i < n; i ++) cin >> a[i];
		for(int i = 1; i < n; i ++) a[i] += a[i - 1];
		i64 mx = 0;
		for(int i = x - 1; i < n; i ++) {
			mx = max(mx, a[i] - (i < x ? 0 : a[i - x]));
		}
		cout << mx + ans << '\n';
	}
	return 0;
}