#include<bits/stdc++.h>

using namespace std;

int dp[200][2];
int N, K, D;
const int MOD = 1e9 + 7;

int main() {
cin >> N >> K >> D;
dp[0][0] = 1;
for(int i = 1; i <= N; i++)
for(int k = 1; k <= K && k <= i; k++) {
dp[i][1] += dp[i - k][1]; dp[i][1] %= MOD;
dp[i][k >= D] += dp[i - k][0]; dp[i][k >= D] %= MOD;
}
cout << dp[N][1] << '\n';
return 0;
}