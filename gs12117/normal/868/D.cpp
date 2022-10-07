#include<cstdio>
#include<cstring>
int n, q;
char s[110][110];
int dp[210][12][4096];
char cs[210][15];
char ce[210][15];
int clen[210];
char stmp[40];
void calcdp(int x, char *row) {
	int m = strlen(row);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < (1 << (i + 1)); j++) {
			for (int k = 0; k + i < m; k++) {
				int sflg = 0;
				for (int ii = 0; ii <= i; ii++) {
					if (((j >> ii) & 1) != row[k + ii]-'0') {
						sflg = 1;
						break;
					}
				}
				if (sflg == 0) {
					dp[x][i][j] = 1;
					break;
				}
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		calcdp(i, s[i]);
		int sl = strlen(s[i]);
		clen[i] = sl;
		if (clen[i] > 14)clen[i] = 14;
		for (int j = 0; j < clen[i]; j++) {
			cs[i][j] = s[i][j];
			ce[i][j] = s[i][sl - clen[i] + j];
		}
	}
	scanf("%d", &q);
	for (int i = n; i < n + q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		for (int j = 0; j < 12; j++) {
			for (int k = 0; k < (1 << (j + 1)); k++) {
				dp[i][j][k] = dp[a][j][k] | dp[b][j][k];
			}
		}
		for (int j = 0; j < clen[a]; j++) {
			stmp[j] = ce[a][j];
		}
		for (int j = 0; j < clen[b]; j++) {
			stmp[j + clen[a]] = cs[b][j];
		}
		stmp[clen[a] + clen[b]] = 0;
		calcdp(i, stmp);
		clen[i] = clen[a] + clen[b];
		if (clen[i] > 14)clen[i] = 14;
		for (int j = 0; j < clen[a]; j++) {
			cs[i][j] = cs[a][j];
		}
		for (int j = 0; j + clen[a] < clen[i]; j++) {
			cs[i][j + clen[a]] = cs[b][j];
		}
		for (int j = 0; j < clen[b]; j++) {
			ce[i][j + clen[i] - clen[b]] = ce[b][j];
		}
		for (int j = 0; j + clen[b] < clen[i]; j++) {
			ce[i][j] = ce[a][j + clen[a] + clen[b] - clen[i]];
		}
		int res = 12;
		for (int j = 0; j < 12; j++) {
			int flg = 0;
			for (int k = 0; k < (1 << (j + 1)); k++) {
				if (dp[i][j][k] == 0) {
					flg = 1;
					break;
				}
			}
			if (flg == 1) {
				res = j;
				break;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}