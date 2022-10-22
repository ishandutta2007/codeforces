#include <bits/stdc++.h>
using namespace std;

int cnt[1000010];
int dp[1000010][5][3];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j <= 4; j++){
			for (int k = 0; k <= 2; k++){
				if (dp[i][j][k] == -1) continue;
//				cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
				for (int l = 0; l <= min(min(j, k), cnt[i + 1]); l++){
					int x = (cnt[i + 1] - l) / 3, y = (cnt[i + 1] - l) % 3;
					int t = min(j - l, 2);
					dp[i + 1][y][t] = max(dp[i + 1][y][t], dp[i][j][k] + l + x);
					if (x) dp[i + 1][min(y + 3, 4)][t] = max(dp[i + 1][min(y + 3, 4)][t], dp[i][j][k] + l + x - 1);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 4; i++){
		for (int j = 0; j <= 2; j++){
			ans = max(ans, dp[m][i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}