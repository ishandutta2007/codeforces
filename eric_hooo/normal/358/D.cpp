#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[3010][3];
int dp[3010][2];

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i][0]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i][1]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i][2]);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2; j++){
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < 2; j++){
			if (dp[i][j] == -INF) continue;
			for (int k = 0; k < 2; k++){
				dp[i + 1][k ^ 1] = max(dp[i + 1][k ^ 1], dp[i][j] + a[i][j + k]);
			}
		}
	}
	printf("%d\n", max(dp[n - 1][0] + a[n - 1][0], dp[n - 1][1] + a[n - 1][1]));
	return 0;
}