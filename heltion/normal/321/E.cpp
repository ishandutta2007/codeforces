#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 4000 + 10;
int cost[maxn][maxn], c[maxn][maxn], dp[maxn][maxn];
void solve(int d, int L, int R, int optL, int optR){
	int optM = optL, M = (L + R) / 2;
	dp[d][M] = dp[d - 1][optM] + c[optM][M];
	if(d > 1)for(int i = optL + 1; i <= min(M - 1, optR); i += 1)
		if(dp[d - 1][i] + c[i][M] < dp[d][M]){
			optM = i;
			dp[d][M] = dp[d - 1][i] + c[i][M];
		}
	if(M > L) solve(d, L, M - 1, optL, optM);
	if(M < R) solve(d, M + 1, R, optM, optR);
}
int getint(){
	char c;
	while(c = getchar()) if(c >= '0') return c - '0'; 
	return 0;
} 
int main(){
	//freopen("C.in", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1)
			cost[i][j] = cost[i][j - 1] + getint();
	for(int i = 0; i <= n; i += 1)
		for(int j = i + 1; j <= n; j += 1){
			c[i][j] = c[i][j - 1] + cost[j][j] - cost[j][i];
		}
	for(int d = 1; d <= k; d += 1){
		solve(d, 1, n, 0, n);
	}
	printf("%d", dp[k][n]);
}