#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, k, x;
  int dp[2][1024] = {{}};

  scanf("%d %d %d", &n, &k, &x);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    dp[0][t]++;
  }

  for(int i = 0; i < k; i++) {
    int sum = 0;
    for(int j = 0; j < 1024; j++) {
      if(sum & 1) {
        int cost = dp[0][j] >> 1;
        dp[1][j ^ x] += cost;
        dp[1][j] += dp[0][j] - cost;
      } else {
        int cost = (dp[0][j] + 1) >> 1;
        dp[1][j ^ x] += cost;
        dp[1][j] += dp[0][j] - cost;
      }
      sum += dp[0][j];
    }
    for(int j = 0; j < 1024; j++) {
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }

  int small = 114514, big = -114514;
  for(int i = 0; i < 1024; i++) {
    if(dp[0][i] > 0) {
      small = min(i, small);
      big = max(i, big);
    }
  }
  
  printf("%d %d\n", big, small);

}