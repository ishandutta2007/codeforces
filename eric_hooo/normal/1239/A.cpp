#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int dp[100010][2];

void add(int &x, int y) {
	x = (x + y) % mod;
}

int main () {
	int n, m; cin >> n >> m;
	dp[1][0] = dp[1][1] = 1, dp[2][0] = dp[2][1] = 1;
	for (int i = 1; i <= max(n, m); i++) {
		// 0
		add(dp[i + 1][1], dp[i][0]);
		add(dp[i + 2][1], dp[i][0]);
		// 1
		add(dp[i + 1][0], dp[i][1]);
		add(dp[i + 2][0], dp[i][1]);
	}
	int ans = 0;
	add(ans, dp[n][0]), add(ans, dp[n][1]);
	add(ans, dp[m][0]), add(ans, dp[m][1]);
	add(ans, mod - 2);
	printf("%d\n", ans);
	return 0;
}