#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	int T;
	for(cin >> T; T; T --) {
		int n, z;
		cin >> n >> z;
		int mx = 0;
		for(int i = 0; i < n; i ++) {
			int x;
			cin >> x;
			mx = max(mx, x | z);
		}
		cout << mx << '\n';
	}
	
	return 0;
}