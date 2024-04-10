#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	string s, t; cin >> s >> t;
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] + (s[i - 1] != t[i - 1]);
		if (i >= 2 && s[i - 1] == t[i - 2] && s[i - 2] == t[i - 1]) {
			dp[i] = min(dp[i], dp[i - 2] + 1);
		}
	}	
	cout << dp[n] << "\n";
	return 0;
}