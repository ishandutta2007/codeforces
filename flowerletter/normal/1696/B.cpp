#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	int T;
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i ++) cin >> a[i];
		int ans = 0;
		for(int i = 0; i < n; i ++) {
			if(a[i] && (i == 0 || a[i - 1] == 0)) ans ++;
		}
		cout << min(ans, 2) << '\n';
	}
	return 0;
}