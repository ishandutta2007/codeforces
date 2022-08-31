#include<bits/stdc++.h>
using namespace std;

const int MAXN = 600;
int N;
int C[MAXN];
int dp[MAXN][MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &C[i]);
	for(int i = 0; i < N; i++) {
		dp[i][i + 1] = 1;
	}
	for(int i = 0; i + 1 < N; i++) {
		dp[i][i + 2] = ((C[i] == C[i + 1]) ? 1 : 2);
	}
	for(int l = 3; l <= N; l++) {
		for(int i = 0; i + l <= N; i++) {
			int j = i + l;
			int v = l;
			for(int k = i + 1; k < j; k++) {
				v = min(v, dp[i][k] + dp[k][j]);
			}
			if(C[i] == C[j - 1]) {
				v = min(v, dp[i + 1][j - 1]);
			}
			dp[i][j] = v;
		}
	}
	cout << dp[0][N] << '\n';
	return 0;
}