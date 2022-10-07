#include<stdio.h>
int n;
char s[80];
int a[80];
int vn, kn, sn;
int dp[80][80][80];
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'V') {
			vn++;
			a[i] = 0;
		}
		else if (s[i] == 'K') {
			kn++;
			a[i] = 1;
		}
		else {
			sn++;
			a[i] = 2;
		}
	}
	sn++;
	a[n] = 2;
	n++;
	for (int i = 0; i <= vn; i++) {
		for (int j = 0; j <= kn; j++) {
			dp[i][j][0] = 999999999;
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i <= vn; i++) {
		for (int j = 0; j <= kn; j++) {
			for (int k = 1; k <= sn; k++) {
				int pi, pj, pk;
				dp[i][j][k] = 999999999;
				for (int ii = 0; ii <= i; ii++) {
					for (int jj = 0; jj <= j; jj++) {
						int res = 0;
						int in = 0;
						int out = 0;
						int p[3];
						int pb[3];
						int ra[3];
						int rb[3];
						p[0] = 0;
						p[1] = 0;
						p[2] = 0;
						pb[0] = 0;
						pb[1] = 0;
						pb[2] = 0;
						ra[0] = ii;
						ra[1] = jj;
						ra[2] = k - 1;
						rb[0] = i;
						rb[1] = j;
						rb[2] = k;
						for (int kk = 0; kk < n; kk++) {
							int h = a[kk];
							p[h]++;
							if (p[h] <= ra[h]) {
								res += out;
							}
							else if (p[h] <= rb[h]) {
								out++;
								pb[h]++;
								if (a[kk] == 1)res += pb[0];
								if (a[kk] != 2)res += pb[2];
							}
						}
						if (dp[i][j][k] > res + dp[ii][jj][k - 1]) {
							dp[i][j][k] = res + dp[ii][jj][k - 1];
						}
					}
				}
			}
		}
	}
	printf("%d", dp[vn][kn][sn]);
	return 0;
}