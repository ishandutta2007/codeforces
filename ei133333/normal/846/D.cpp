#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int W, H, K, Q;
  int X[250000], Y[250000], T[250000];

  scanf("%d %d %d %d", &W, &H, &K, &Q);
  for(int i = 0; i < Q; i++) {
    scanf("%d %d %d", &X[i], &Y[i], &T[i]);
    --X[i], --Y[i];
  }

  auto check = [&](int v)
  {
    vector< vector< bool > > mat(H, vector< bool >(W, false));
    for(int i = 0; i < Q; i++) {
      if(T[i] <= v) {
        mat[Y[i]][X[i]] = true;
      }
    }
    vector< vector< int > > dp(H + 1, vector< int >(W + 1, 0));
    for(int i = 1; i <= H; i++) {
      for(int j = 1; j <= W; j++) {
        if(mat[i - 1][j - 1]) dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
      }
    }
    int ret = 0;
    for(int i = 1; i <= H; i++) {
      for(int j = 1; j <= W; j++) {
        ret = max(ret, dp[i][j]);
      }
    }
    return (ret < K);
  };

  if(check(INF)) {
    puts("-1");
    return (0);
  }

  int low = -1, high = INF;
  while(high - low > 0) {
    int mid = (low + high + 1) >> 1;
    if(check(mid)) low = mid;
    else high = mid - 1;
  }

  printf("%d\n", low + 1);
}