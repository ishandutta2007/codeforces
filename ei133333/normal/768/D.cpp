#include<bits/stdc++.h>

using namespace std;

double dp[8001][1002];

int main()
{
  int K, Q;
  cin >> K >> Q;

  fill_n(*dp, 8001 * 1002, 0.0);
  dp[1][1] = 2000.0;
  for(int i = 1; i < 8000; i++) {
    for(int j = 1; j <= K; j++) {
      long double hit = dp[i][j] * (K - j) / K;
      dp[i + 1][j + 1] += hit;
      dp[i + 1][j] += dp[i][j] - hit;
    }
  }

  while(Q--) {
    int P;
    cin >> P;
    for(int i = 0; i <= 8000; i++) {
      if(P <= dp[i][K]) {
        cout << i << endl;
        break;
      }
    }
  }
}