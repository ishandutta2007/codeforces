#include <bits/stdc++.h>
using namespace std;

string s[30];
int dp[1 << 20];
int num[1 << 20];
int val[1 << 20];
int a[30][30];
int mm[26], maxj[26];

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		num[1 << i] = i;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < m; i++) {
		for (int mask = 1; mask < (1 << n); mask++) {
			val[mask] = val[mask - (mask & -mask)] + a[num[mask & -mask]][i];
		}
		memset(mm, 0, sizeof(mm)), memset(maxj, 0, sizeof(maxj));
		for (int j = 0; j < n; j++) {
			mm[s[j][i] - 'a'] |= 1 << j;
			maxj[s[j][i] - 'a'] = max(maxj[s[j][i] - 'a'], a[j][i]);
		}
		for (int mask = 0; mask < (1 << n); mask++) {
			for (int j = 0; j < n; j++) {
				if (mask >> j & 1) continue;
				dp[mask | 1 << j] = min(dp[mask | 1 << j], dp[mask] + a[j][i]);
			}
		}
		for (int j = 0; j < 26; j++) {
			maxj[j] = val[mm[j]] - maxj[j];
			for (int mask = 0; mask < (1 << n); mask++) {
				int tmp = mask & mm[j];
				dp[mask] = min(dp[mask], dp[mask ^ tmp] + min(val[tmp], maxj[j]));
			}
		}
	}
	printf("%d\n", dp[(1 << n) - 1]);
	return 0;
}