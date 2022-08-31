#include<iostream>

using namespace std;

const int MOD = 1e9 + 7;
int dp[4000][4000];

int main() {
	int N, K;
	cin >> N >> K;
	for(int i = 1; i <= N; i++) {
		dp[i][1] = 1;
		for(int k = 1; k < K && dp[i][k]; k++) {
			for(int j = i; j <= N; j += i) {
				dp[j][k + 1] += dp[i][k];
				if(dp[j][k + 1] >= MOD) dp[j][k + 1] -= MOD;
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= N; i++) {
		res += dp[i][K];
		if(res >= MOD) res -= MOD;
	}
	cout << res << '\n';
	return 0;
}