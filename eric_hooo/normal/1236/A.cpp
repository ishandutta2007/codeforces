#include <bits/stdc++.h>
using namespace std;

int dp[110][110][110];

int dfs(int a, int b, int c) {
	if (~dp[a][b][c]) return dp[a][b][c];
	dp[a][b][c] = 0;
	if (a >= 1 && b >= 2) dp[a][b][c] = max(dp[a][b][c], dfs(a - 1, b - 2, c) + 3);
	if (b >= 1 && c >= 2) dp[a][b][c] = max(dp[a][b][c], dfs(a, b - 1, c - 2) + 3);
	return dp[a][b][c];
}

int main () {
	memset(dp, -1, sizeof(dp));
	int T; scanf("%d", &T);
	while  (T--) {
		int a, b, c; cin >> a >> b >> c;
		cout << dfs(a, b, c) << endl;
	}
	return 0;
}