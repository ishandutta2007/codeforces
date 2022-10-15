#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		multiset<int> ms1(s.begin(), s.end()), ms2(t.begin(), t.end());
		if (ms1 != ms2) {
			cout << -1 << '\n';
			continue;
		}
		vector<vector<int>> suf_s(n + 1, vector<int>(200)), suf_t(n + 1, vector<int>(200));
		for (int i = n - 1; i + 1; --i) {
			suf_s[i] = suf_s[i + 1];
			suf_t[i] = suf_t[i + 1];
			++suf_s[i][s[i]];
			++suf_t[i][t[i]];
		}
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				dp[i][j] = 1e9;
				if(s[i - 1] == t[j - 1]) {
					dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
				} else {
					if (suf_s[i][t[j - 1]] > suf_t[j][t[j - 1]]) {
						dp[i][j] = min(dp[i][j - 1], dp[i][j]);
					} 
					dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
				}
			}
		}
		cout << dp[n][n] << '\n';
	}
}