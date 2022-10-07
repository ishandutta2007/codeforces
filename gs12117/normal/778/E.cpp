#include<stdio.h>
int n;
char a[1010];
int al;
char b[1010][1010];
int bl[1010];
char tmp[1010];
int dp[1010][1010];
int pord[1010];
int pup[1010];
int npord[1010];
int val[12];
int rev(char *s) {
	int l;
	for (l = 0; s[l]; l++);
	for (int i = 0; i < l; i++) {
		tmp[i] = s[i];
	}
	for (int i = 0; i < l; i++) {
		s[i] = tmp[l - 1 - i];
	}
	return l;
}
int main() {
	scanf("%s", a);
	al = rev(a);
	for (int i = al; i < 1007; i++)a[i] = '0';
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
		bl[i] = rev(b[i]);
		for (int j = bl[i]; j < 1007; j++)b[i][j] = '0';
	}
	for (int i = 0; i < 10; i++) {
		scanf("%d", &val[i]);
	}
	for (int i = 0; i < 1007; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1999999999;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		pord[i] = i;
	}
	for (int i = 0; i < 1007; i++) {
		int un = 0;
		for (int j = 0; j < 10; j++) {
			if ((a[i] != '?'&&a[i] - '0' != j) || j == 0 && i == al - 1) {
				for (int k = 0; k < n; k++) {
					int t = j + b[pord[k]][i] - '0';
					t++;
					if (t == 10) {
						t -= 10;
						npord[un] = pord[k];
						un++;
					}
				}
				continue;
			}
			int res = 0;
			for (int k = 0; k < n; k++) {
				int t = j + b[k][i] - '0';
				if (t >= 10) {
					t -= 10;
				}
				if (t != 0 || i < al || i < bl[k])res += val[t];
			}
			if (dp[i + 1][un] < res + dp[i][0])dp[i + 1][un] = res + dp[i][0];
			for (int k = 0; k < n; k++) {
				int t = j + b[pord[k]][i] - '0';
				if (t >= 10) {
					t -= 10;
				}
				if (t != 0 || i < al || i < bl[pord[k]])res -= val[t];
				t++;
				if (t == 10) {
					t -= 10;
					npord[un] = pord[k];
					un++;
				}
				if (t != 0 || i < al || i < bl[pord[k]])res += val[t];
				if (dp[i + 1][un] < res + dp[i][k + 1])dp[i + 1][un] = res + dp[i][k + 1];
			}
		}
		for (int j = 0; j < n; j++) {
			pord[j] = npord[j];
		}
	}
	printf("%d", dp[1006][0]);
	return 0;
}