#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> vis(n + 1);
		for (int i = 0; i < n * 2; ++i) {
			int x;
			cin >> x;
			if (!vis[x]) cout << x << ' ';
			vis[x] = true;
		}
		cout << '\n';
	}
}