#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, K, two = 0, five = 0;

  cin >> N >> K;

  int dp[201][6001];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;

  for(int i = 0; i < N; i++) {
    int64 P;
    cin >> P;
    int latte = 0, malta = 0;
    while(P % 2 == 0) {
      ++latte;
      P /= 2;
    }
    while(P % 5 == 0) {
      ++malta;
      P /= 5;
    }
    for(int j = K - 1; j >= 0; j--) {
      for(int k = 6000; k >= malta; k--) {
        if(dp[j][k - malta] == -1) continue;
        dp[j + 1][k] = max(dp[j + 1][k], dp[j][k - malta] + latte);
      }
    }
  }


  int ret = 0;
  for(int i = 0; i <= 6000; i++) {
    ret = max(ret, min(i, dp[K][i]));
  }
  cout << ret << endl;

}