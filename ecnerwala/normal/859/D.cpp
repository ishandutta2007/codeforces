#include<bits/stdc++.h>
using namespace std;

const int MAXN = 8;
int N;
double P[1 << MAXN][1 << MAXN];

double alive[MAXN][1 << MAXN];
double dp[MAXN][1 << MAXN];


int main() {
	scanf("%d", &N);
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			int v; scanf("%d", &v);
			P[i][j] = v * 0.01;
		}
	}
	for (int i = 0; i < (1 << N); i++) {
		alive[0][i] = 1;
	}
	for (int l = 0; l < N; l++) {
		for (int i = 0; i < (1 << N); i++) {
			for (int j = 0; j < (1 << N); j++) {
				if (((i^j) >> l) == 1) {
					alive[l+1][i] += alive[l][i] * alive[l][j] * P[i][j];
				}
			}
		}
	}
	for (int i = 0; i < (1 << N); i++) {
		dp[0][i] = 0;
	}
	for (int l = 0; l < N; l++) {
		for (int i = 0; i < (1 << N); i++) {
			for (int j = 0; j < (1 << N); j++) {
				if (((i^j) >> l) == 1) {
					dp[l+1][i] = max(dp[l+1][i], dp[l][j]);
				}
			}
			dp[l+1][i] += dp[l][i];
			dp[l+1][i] += alive[l+1][i] * (1 << l);
		}
	}
	double res = 0;
	for (int i = 0; i < (1 << N); i++) {
		res = max(res, dp[N][i]);
	}
	printf("%.12f\n", res);
	return 0;
}