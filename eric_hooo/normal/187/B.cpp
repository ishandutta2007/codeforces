#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int dis[70][70][70];
int dp[1010][70][70];

int main(){
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	memset(dp, INF, sizeof(dp));
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= n; k++){
				scanf("%d", &dis[i][j][k]);
			}
		}
		for (int j = 1; j <= n; j++){
			for (int a = 1; a <= n; a++){
				for (int b = 1; b <= n; b++){
					if (dis[i][a][b] > dis[i][a][j] + dis[i][j][b]){
						dis[i][a][b] = dis[i][a][j] + dis[i][j][b];
					}
				}
			}
		}
		for (int a = 1; a <= n; a++){
			for (int b = 1; b <= n; b++){
				dp[0][a][b] = min(dp[0][a][b], dis[i][a][b]);
			}
		}
	}
	for (int i = 1; i <= 1000; i++){
		for (int a = 1; a <= n; a++){
			for (int b = 1; b <= n; b++){
				dp[i][a][b] = dp[i - 1][a][b];
			}
		}
		for (int a = 1; a <= n; a++){
			for (int b = 1; b <= n; b++){
				for (int c = 1; c <= n; c++){
					if (dp[i][a][c] > dp[i - 1][a][b] + dp[0][b][c]){
						dp[i][a][c] = dp[i - 1][a][b] + dp[0][b][c];
					}
				}
			}
		}
	}
	while (q--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", dp[c][a][b]);
	}
	return 0;
}