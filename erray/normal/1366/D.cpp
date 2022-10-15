#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> dv(1e7 + 1);
	for (int i = 2; i <= 1e7; ++i) {
	  if (!dv[i]) {
	  	for (int j = i; j <= 1e7; j+= i) dv[j] = i;
	  }
	}
	int n;
	cin >> n;
	vector<pair<int, int>> ans;
	while (n--) {
		int x;
		cin >> x;
		int d = dv[x];
		int d1 = 1;
		while (x % d == 0) {
			x /= d;
			d1 *= d;		
		}
		if (x == 1) d1 = x = -1;
		ans.emplace_back(d1, x);
	}
	for (int i = 0; i < ans.size(); ++i) cout << ans[i].first << ' ';
	cout << '\n';
	for (int i = 0; i < ans.size(); ++i) cout << ans[i].second << ' ';
}