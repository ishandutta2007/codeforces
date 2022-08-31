#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int N;
double P[133][133];
int64 fact[10];
double dp[133][133];

int main()
{
  fact[0] = 1;
  for(int i = 1; i < 10; i++) fact[i] = fact[i - 1] * 2;

  cin >> N;
  for(int i = 0; i < fact[N]; i++) {
    for(int j = 0; j < fact[N]; j++) {
      cin >> P[i][j];
      P[i][j] /= 100.0;
    }
  }

  for(int i = 0; i < fact[N]; i++) {
    dp[0][i] = 1.0;
  }


  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < fact[N]; j++) {
      for(int k = 0; k < fact[N]; k++) {
        if(j / fact[i] == k / fact[i] && j / fact[i - 1] != k / fact[i - 1]) {
          dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * P[j][k];
        }
      }
    }
  }


  double ret = 0.0;
  for(int i = 2; i <= N; i++) {
    for(int j = 0; j < fact[N]; j++) {
      dp[i][j] *= fact[i - 1];
      double beet = 0;
      for(int k = 0; k < fact[N]; k++) {
        if(j / fact[i] == k / fact[i] && j / fact[i - 1] != k / fact[i - 1]) {
          beet = max(beet, dp[i - 1][j] + dp[i - 1][k]);
        }
      }
      dp[i][j] += beet;
      ret = max(ret, dp[i][j]);
    }
  }
  cout << fixed << setprecision(20) << ret << endl;
}