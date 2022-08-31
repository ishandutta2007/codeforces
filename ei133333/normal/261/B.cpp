#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  double fact[51], all = 0.0;
  fact[0] = 1;
  for(int i = 1; i < 51; i++) fact[i] = fact[i - 1] * i;

  int N, A[50], P;
  double dp[51][51];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  cin >> P;

  int sum = 0;
  for(int i = 0; i < N; i++) sum += A[i];

  if(sum <= P) {
    cout << N << endl;
    return (0);
  }

  for(int i = 0; i < N; i++) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int j = 0; j < N; j++) {
      if(i == j) continue;
      for(int k = N - 1; k >= 0; k--) {
        for(int l = P; l >= A[j]; l--) {
          dp[k + 1][l] += dp[k][l - A[j]];
        }
      }
    }
    for(int j = 0; j < N; j++) {
      for(int k = max(0, P - A[i] + 1); k <= P; k++) {
        all += fact[j] * fact[N - 1 - j] * dp[j][k] * j;
      }
    }
  }

  cout << fixed << setprecision(10) << all / fact[N] << endl;
}