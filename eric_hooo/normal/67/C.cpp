#include <bits/stdc++.h>
using namespace std;

char s[5010], t[5010];
int dp[5010][5010];
int ps[5010][26], pt[5010][26];

void chmin(int &x, int y) {
	x = min(x, y);
}

int main() {
//	freopen("street.in", "r", stdin);
//	freopen("street.out", "w", stdout);
	int ins, del, rep, swp; scanf("%d%d%d%d", &ins, &del, &rep, &swp);
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	memset(ps, -1, sizeof(ps)), memset(pt, -1, sizeof(pt));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			ps[i][j] = ps[i + 1][j];
		}
		ps[i][s[i] - 'a'] = i;
	}
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			pt[i][j] = pt[i + 1][j];
		}
		pt[i][t[i] - 'a'] = i;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i < n) chmin(dp[i + 1][j], dp[i][j] + del);
			if (j < m) chmin(dp[i][j + 1], dp[i][j] + ins);
			if (i < n && j < m) chmin(dp[i + 1][j + 1], dp[i][j] + (s[i] == t[j] ? 0 : rep));
			if (i < n && j < m) {
				int pps = ps[i + 1][t[j] - 'a'], ppt = pt[j + 1][s[i] - 'a'];
				if (pps != -1 && ppt != -1) {
					chmin(dp[pps + 1][ppt + 1], dp[i][j] + del * (pps - i - 1) + ins * (ppt - j - 1) + swp);
				}
			}
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}