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
		vector<int> ans(4);
		ans[0] = 6;
		ans[1] = 10;
		ans[2] = 14;
		ans[3] = n - 30;
		bool ok = true;
		for (int i = 0; i < 3; ++i) ok &= (ans[i] != ans[3]);
		if (!ok) {
			--ans[3];
			++ans[2];
		}
		if (n < 31) {
			cout << "NO\n";
			continue;
		}	
		cout << "YES\n";
		for (auto el : ans) cout << el << ' ';
		cout << '\n';
	}
}