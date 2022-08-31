#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 60;
const int MAXH = 60;
const int MAXM = 60;

int N, H, M;
int L[MAXM], R[MAXM], X[MAXM];
ll C[MAXM];

// dp state is left, right, height
ll dp[MAXN][MAXN][MAXH];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> H >> M;
	for (int i = 0; i < M; i++) {
		cin >> L[i] >> R[i] >> X[i] >> C[i];
	}

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= N; i++) {
		for (int h = 0; h <= H; h++) {
			dp[i+1][i][h] = 0;
		}
	}

	for (int l = 1; l <= N; l++) {
		for (int i = 1, j = i+l-1; j <= N; i++, j++) {
			for (int h = 0; h <= H; h++) {
				if (h > 0) {
					dp[i][j][h] = dp[i][j][h-1];
				} else {
					dp[i][j][h] = 0;
				}
				for (int k = i; k <= j; k++) {
					ll fines = 0;
					for (int m = 0; m < M; m++) {
						if (i <= L[m] && L[m] <= k && k <= R[m] && R[m] <= j) {
							if (h > X[m]) {
								fines += C[m];
							}
						}
					}
					dp[i][j][h] = max(dp[i][j][h], h * h - fines + dp[i][k-1][h] + dp[k+1][j][h]);
				}
				//cerr << i << ' ' << j << ' ' << h << ' ' << dp[i][j][h] << '\n';
			}
		}
	}
	cout << dp[1][N][H] << '\n';

	return 0;
}