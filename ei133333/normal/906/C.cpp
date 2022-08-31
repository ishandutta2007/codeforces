#include <bits/stdc++.h>

using namespace std;

int N, M;
int bit[22];
int dp[1 << 22];

int main()
{
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    bit[i] = 1 << i;
  }
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    bit[x] |= 1 << y;
    bit[y] |= 1 << x;
  }

  if(M == N * (N - 1) / 2) {
    cout << 0 << endl;
    return (0);
  }

  int ret = (1 << N) - 1;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < N; i++) {
    dp[1 << i] = bit[i];
  }
  for(int i = 1; i < (1 << N); i++) {
    if(dp[i] == -1) continue;
    int beet = 0;
    for(int j = 0; j < N; j++) {
      if((i >> j) & 1) beet |= bit[j];
    }
    for(int j = 0; j < N; j++) {
      if((beet >> j) & 1) {
        dp[i | (1 << j)] = dp[i] | bit[j];
      }
    }
  }
  
  for(int i = 0; i < (1 << N); i++) {
    if(dp[i] == (1 << N) - 1) {
      if(__builtin_popcount(i) < __builtin_popcount(ret)) {
        ret = i;
      }
    }
  }

  cout << __builtin_popcount(ret) << endl;
  for(int i = 0; i < N; i++) {
    if((ret >> i) & 1) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}