#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 998244353;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	for (cin >> t; t; t -= 1) {
		int n;
		cin >> n;
		vector<int> a(n), dp(n + 1), pw(n + 1, 1), c(n + 3), p(n + 3);
		for (int i = 1; i <= n; i += 1) pw[i] = pw[i - 1] * 2 % mod;
		for (int& ai : a) {
			cin >> ai;
			c[ai] += 1;
		}
		int ans = 0;
		for (int& ai : a) {
			p[ai] += 1;
			int f = (dp[ai] + (ai ? dp[ai - 1] : 1)) % mod;
			ans = (ans + f) % mod; 
			if (ai >= 2)
				ans = (ans + (LL)dp[ai - 2] * pw[c[ai] - p[ai] + c[ai - 2] - p[ai - 2]]) % mod;
			dp[ai] = (dp[ai] + f) % mod;
		}
		cout << (ans + pw[c[1]] - 1) % mod << "\n";
	}
	return 0;
}