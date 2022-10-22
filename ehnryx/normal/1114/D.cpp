#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+1;
int val[N], dp[N][N];

int solve(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 0;
	if (val[l] == val[l+1]) return dp[l][r] = solve(l+1,r);
	if (val[r] == val[r-1]) return dp[l][r] = solve(l,r-1);
	if (val[l] == val[r]) return dp[l][r] = 1 + solve(l+1,r-1);
	else return dp[l][r] = 1 + min(solve(l+1,r), solve(l,r-1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> val[i];
	}

	memset(dp, -1, sizeof dp);
	cout << solve(1,n) << '\n';

	return 0;
}