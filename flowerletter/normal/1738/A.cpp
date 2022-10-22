#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		vector<vector<int>> a(2);
		vector<int> x(n), y(n);
		for(int i = 0; i < n; i ++) {
			cin >> x[i];
		}
		for(int i = 0; i < n; i ++) {
			cin >> y[i];
		}
		for(int i = 0; i < n; i ++) {
			a[x[i]].emplace_back(y[i]);
		}
		if(a[0].size() < a[1].size()) swap(a[0], a[1]);
		sort(a[0].begin(), a[0].end());
		reverse(a[0].begin(), a[0].end());
		sort(a[1].begin(), a[1].end());
		reverse(a[1].begin(), a[1].end());
		i64 s = accumulate(a[1].begin(), a[1].end(), 0ll) + accumulate(a[0].begin(), a[0].begin() + a[1].size(), 0ll) + 
				accumulate(a[0].begin(), a[0].end(), 0ll) + accumulate(a[1].begin(), a[1].end(), 0ll);
		if(a[0].size() == a[1].size()) s -= min(a[0].back(), a[1].back());
		cout << s << '\n';
	}
	return 0;
}