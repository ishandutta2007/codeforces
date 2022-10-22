#include <bits/stdc++.h>
using namespace std;

int a[10], b[10], c[10][10];
int dp[20010], ndp[20010];
int pw[8];

void Solve(int now, int mask, int need, int val, int *cst) {
	if (now == -1) {
		if (!need) ndp[mask] = min(ndp[mask], val);
		return ;
	}
	int cur = mask / pw[now] % 5;
	for (int i = 0; i <= cur; i++) {
		if (i > need) break;
		Solve(now - 1, mask - i * pw[now], need - i, val + (i ? cst[now] : 0), cst);
	}
}

int main() {
	pw[0] = 1; for (int i = 1; i < 8; i++) pw[i] = pw[i - 1] * 5;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> c[i][j];
	int Beg = 0; for (int i = 0; i < m; i++) Beg += pw[i] * b[i];
	memset(dp, 0x3f, sizeof(dp)); dp[Beg] = 0;
	for (int i = 0; i < n; i++) {
		memset(ndp, 0x3f, sizeof(ndp));
		for (int j = 0; j < pw[m]; j++) {
			if (dp[j] == 0x3f3f3f3f) continue;
			Solve(m - 1, j, a[i], dp[j], c[i]);
		}
		swap(dp, ndp);
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < pw[m]; i++) ans = min(ans, dp[i]);
	if (ans == 0x3f3f3f3f) ans = -1;
	cout << ans << endl;
	return 0;
}