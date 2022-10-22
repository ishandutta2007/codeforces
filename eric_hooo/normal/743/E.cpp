#include <bits/stdc++.h>
using namespace std;

int a[1010];
int dp[1010][300];
vector <int> all[8];

void chmax(int &a, int b){
	a = a > b ? a : b;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;
		all[a[i]].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i <= n / 8; i++){
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int j = 0; j < n; j++){
			for (int mask = 0; mask < (1 << 8); mask++){
				if (dp[j][mask] == -1) continue;
				for (int k = 0; k < 8; k++){
					if (mask >> k & 1) continue;
					int pos = lower_bound(all[k].begin(), all[k].end(), j) - all[k].begin();
					if (i == 0) chmax(dp[j][mask ^ 1 << k], dp[j][mask]);
					else if (pos + i - 1 < all[k].size()){
						chmax(dp[all[k][pos + i - 1] + 1][mask ^ 1 << k], dp[j][mask] + i);
					}
					if (pos + i < all[k].size()){
						chmax(dp[all[k][pos + i] + 1][mask ^ 1 << k], dp[j][mask] + i + 1);
					}
				}
			}
		}
		for (int j = 0; j <= n; j++){
			chmax(ans, dp[j][(1 << 8) - 1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}