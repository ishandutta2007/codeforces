#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		int ans = -1e9;
		for(int i = 0; i < n; ++i) {
			ans = max(ans, a[i] - a[(i + 1) % n]);
		}
		for(int i = 1; i < n - 1; ++i) {
			ans = max(ans, a[i] - a[0]);
			ans = max(ans, a[n - 1] - a[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}