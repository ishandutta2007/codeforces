#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000000000000000;

int n;
int a[60];
long long dp[60][2][2];

long long dfs(int now, int p1, int p2) {
	if (now == (n + 1) / 2) return 1;
	if (~dp[now][p1][p2]) return dp[now][p1][p2];
	long long &res = dp[now][p1][p2] = 0;
	int rev = n - now - 1;
	for (int i = (a[now] == -1 ? 0 : a[now]); i <= (a[now] == -1 ? 1 : a[now]); i++) {
		for (int j = (a[rev] == -1 ? 0 : a[rev]); j <= (a[rev] == -1 ? 1 : a[rev]); j++) {
			if (now == rev && i != j) continue;
			if (now == 0 && i == 1) continue;
			if (p1 && i > j) continue;
			if (p2 && i > (1 - j)) continue;
			res = min(INF, res + dfs(now + 1, p1 & (i == j), p2 & (i != j)));
		}
	}
	return res;
}

int main () {
	long long k; cin >> n >> k; k++;
	memset(a, -1, sizeof(a)), memset(dp, -1, sizeof(dp));
	if (dfs(0, 1, 1) < k) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i] = 0;
		memset(dp, -1, sizeof(dp));
		long long tmp = dfs(0, 1, 1);
		if (tmp < k) a[i] = 1, k -= tmp;
		cout << a[i];
	}
	cout << endl;
	return 0;
}