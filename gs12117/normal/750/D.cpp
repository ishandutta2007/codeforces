#include<stdio.h>
int n;
int a[32];
int dp[32][320][320];
const int ofs = 160;
const int vect[8][2] = {
	{ 1,0 },
	{ 1,1 },
	{ 0,1 },
	{ -1,1 },
	{ -1,0 },
	{ -1,-1 },
	{ 0,-1 },
	{ 1,-1 }
};
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			dp[i][ofs + j*vect[i % 8][0]][ofs + j*vect[i % 8][1]] = 1;
		}
		for (int j = 0-ofs; j < 320-ofs; j++) {
			for (int k = 0-ofs; k < 320-ofs; k++) {
				if (dp[i + 1][ofs + j][ofs + k] == 1) {
					dp[i][ofs + j + a[i] * vect[i % 8][0]][ofs + k + a[i] * vect[i % 8][1]] = 1;
					dp[i][ofs + k + a[i] * vect[i % 8][0]][ofs - j + a[i] * vect[i % 8][1]] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 320; i++) {
		for (int j = 0; j < 320; j++) {
			ans+=dp[0][i][j];
		}
	}
	printf("%d", ans);
	return 0;
}