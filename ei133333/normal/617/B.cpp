#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int N, x[100];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> x[i];
  }

  int dp[100][100];
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < N; i++) {
    for(int j = i; j < N; j++) {
      int isOne = 0;
      for(int k = i; k <= j; ++k) isOne += x[k] == 1;
      dp[i][j] = isOne == 1;
    }
  }

  int64 dp2[101] = {};
  dp2[0] = 1;
  for(int i = 0; i < N; i++) {
    for(int j = i; j < N; j++) {
      if(dp[i][j]) dp2[j + 1] += dp2[i];
    }
  }
  cout << dp2[N] << endl;
}