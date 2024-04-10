#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5030;
ll dp[MAXN][MAXN];
ll A[MAXN];
ll S[MAXN];
int N;
int M;
int K;
int main() {
cin >> N >> M >> K;
S[0] = 0;
for(int  i = 0; i < N; i++) cin >> A[i], S[i + 1] = S[i] + A[i];
for(int i = N; i >= M; i--) S[i] -= S[i - M];
dp[0][0] = 0;
for(int i = 1; i <= N; i++) {
for(int j = 0; j <= i / M && j <= K; j++) {
dp[i][j] = dp[i - 1][j];
if(i >= M && j > 0) dp[i][j] = max(dp[i][j], dp[i - M][j - 1] + S[i]);
}
}
cout << dp[N][K] << '\n';
return 0;
}