#include <bits/stdc++.h>
using namespace std;

long long dp[100010][3];
int a[100010], b[100010];

void chmax(long long &a, long long b){
	a = max(a, b);
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++){
		chmax(dp[i + 1][0], dp[i][0]);
		chmax(dp[i + 1][1], dp[i][0] + a[i]);
		chmax(dp[i + 1][2], dp[i][0] + b[i]);
		chmax(dp[i + 1][0], dp[i][1]);
		chmax(dp[i + 1][2], dp[i][1] + b[i]);
		chmax(dp[i + 1][0], dp[i][2]);
		chmax(dp[i + 1][1], dp[i][2] + a[i]);
	}
	printf("%I64d\n", max(max(dp[n][0], dp[n][1]), dp[n][2]));
	return 0;
}