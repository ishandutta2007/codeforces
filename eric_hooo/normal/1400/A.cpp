#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s; cin >> s;
		s = " " + s;
		string ans;
		for (int i = 1; i <= n; i++) {
			ans.push_back(s[i + i - 1]);
		}
		cout << ans << endl;
	}
	return 0;
}