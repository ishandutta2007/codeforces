#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<bool> vis(1001);
		while (n--) {
			int x;
			cin >> x;
			vis[x] = true;
		}
		int ans = -1;
		while (m--) {
			int x;
			cin >> x;
			if (vis[x]) ans = x;
		}
		if (ans == -1) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n1 " << ans << '\n';
	}
}