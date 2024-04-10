#include <bits/stdc++.h>
using namespace std;

const int mod = 51123987;

int dp[150][60][60][60];
char s[150], tmp[150];
int nxta[150], nxtb[150], nxtc[150];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	int n; scanf("%d", &n);
	scanf("%s", s);
	nxta[n] = nxtb[n] = nxtc[n] = n;
	for (int i = n - 1; i >= 0; i--) {
		nxta[i] = nxta[i + 1], nxtb[i] = nxtb[i + 1], nxtc[i] = nxtc[i + 1];
		if (s[i] == 'a') nxta[i] = i;
		if (s[i] == 'b') nxtb[i] = i;
		if (s[i] == 'c') nxtc[i] = i;
	}
	int ans = 0;
	dp[0][0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int a = 0; a < 55 && a <= n; a++) {
			for (int b = 0; b < 55 && a + b <= n; b++) {
				for (int c = 0; c < 55 && a + b + c <= n; c++) {
					if (!dp[i][a][b][c]) continue;
					int val = dp[i][a][b][c];
					if (a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1) add(ans, val);
					if (nxta[i] < n) add(dp[nxta[i]][a + 1][b][c], val);
					if (nxtb[i] < n) add(dp[nxtb[i]][a][b + 1][c], val);
					if (nxtc[i] < n) add(dp[nxtc[i]][a][b][c + 1], val);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}