#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<long long> dp(1e6 * 2);
	const int mod = 1e9 + 7;
	for (int i = 2; i < (int)1e6 * 2; ++i) {
		dp[i] = dp[i - 1] + (dp[i - 2] << 1) + (i % 3 == 2 ? 4 : 0);
		dp[i]	%= mod;				                                 		
	}
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n - 1] << '\n';		
	}
}