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
	  vector<int> ans;
		for (int i = 0; i < n; ++i) {
		  int shift =  i >> 1;
			if (!(i & 1)) {
				if (b[n - i - 1] == a[shift]) ans.push_back(0);				
			} else if (b[n - i - 1] != a[n - 1 - shift]) ans.push_back(0);
			ans.push_back(n - i - 1);
		}
		cout << ans.size() << ' ';
		for (auto el : ans) {
			cout << el + 1 << ' ';
	 	}
		cout << '\n';
	}
}