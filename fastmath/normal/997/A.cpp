#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = 1e18 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;

	int k = 0;
	for (int i = 0; i < n; ++i) {
	  	if (i == 0 || s[i] != s[i - 1]) {
	  	 	if (s[i] == '0') ++k;
	  	}
	}

	if (k == 0) {
		cout << "0\n";
		return 0;
	}

	int ans = INF; 
	for (int i = 0; i < k; ++i) {
		ans = min(ans, x * i + y * (k - i));
	}

	cout << ans << '\n';
 	return 0;
}