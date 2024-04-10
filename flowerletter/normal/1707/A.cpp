#include <bits/stdc++.h>
using namespace std;

int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n), ans(n);
		for(int i = 0; i < n; i ++) cin >> a[i];
		int cur = 0;
		for(int i = n - 1; i >= 0; i --) {
			if(a[i] <= cur) ans[i] = 1;
			else if(cur < q) cur ++, ans[i] = 1;
			else ans[i] = 0;
		}
		for(int i = 0; i < n; i ++) cout << ans[i]; cout << '\n';
	}
	return 0;
}