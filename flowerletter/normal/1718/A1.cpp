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
		vector<int> a(n), f(n);
		map<int, int> lst;
		for(int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		for(int i = 1; i < n; i ++) a[i] ^= a[i - 1];
		lst[0] = -1;
		for(int i = 0; i < n; i ++) {
			if(i) f[i] = f[i - 1];
			if(lst.count(a[i])) {
				if(lst[a[i]] != -1) f[i] = max(f[i], f[lst[a[i]]] + 1);
				else f[i] = max(f[i], 1);
			}
			lst[a[i]] = i;
		}
		int ans = n - f[n - 1];
		cout << ans << '\n';
	}
	return 0;
}