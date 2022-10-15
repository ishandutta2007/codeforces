#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		string a, b;
		cin >> n >> a >> b;
		set<int> s;
		bool ok = true;
		vector<vector<int>> pos(20);
		for (int i = 0; i < n; ++i) {
			pos[a[i] - 'a'].push_back(b[i] - 'a');
			ok &= (a[i] <= b[i]);
		}
		if (!ok) {
			cout << -1 << '\n';
			continue;
		}
		int ans = 0;
		for (int i = 0; i < 20; ++i) {
			int mn = 30;
			vector<int> as;
			for (auto el : pos[i]) {
				if (el != i) {
					mn = min(el, mn);
					as.push_back(el);
				}
			} 
			if (mn != 30) {
				++ans;
				pos[mn].insert(pos[mn].end(), as.begin(), as.end());
			}
		}
		cout << ans << '\n';
	}
}