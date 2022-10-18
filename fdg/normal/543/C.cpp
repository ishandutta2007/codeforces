#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

string w[22];
int arr[22][22];

int what[22][22], mwhat[22][22];

int dp[1<<20];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> w[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> arr[i][j];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      mwhat[i][j] = 1<<i;
      for (int t = 0; t < n; ++t)
        if (w[i][j] == w[t][j] && t != i) {
          mwhat[i][j] |= 1<<t;
          what[i][j] += arr[t][j];
        }
    }
  }

  int cur = 0, next = 1, ans = 2000000000;
  for (int i = 0; i < (1<<n); ++i)
    dp[i] = ans / 2;

  dp[0] = 0;
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      for (int mask = (1<<n) - 1; mask >= 0; --mask) {
        dp[mask | mwhat[i][j]] = min(dp[mask | mwhat[i][j]], dp[mask] + what[i][j]);
        dp[mask | (1<<i)] = min(dp[mask | (1<<i)], dp[mask] + arr[i][j]);
      }
      // cur ^= 1, next ^= 1;
      // memset(dp[next], -1, sizeof(dp[next]));
      // if (dp[cur][(1<<n) - 1] != -1)
      //   ans = min(ans, dp[cur][(1<<n) - 1]);
    }
  }

  printf("%d\n", dp[(1<<n) - 1]);
  return 0;
}