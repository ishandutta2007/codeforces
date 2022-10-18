#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[1001];
int mod = 1000000007;

int ADD = 10000;

int dp[1001][20001];

void add(int& r, int a) {
  r += a;
  if (r >= mod) {
    r -= mod;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  int ans = 0;
  dp[n][ADD] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for(int j = -ADD; j <= ADD; ++j) {
      if (dp[i + 1][j + ADD]) {
        add(dp[i][j + arr[i] + ADD], dp[i + 1][j + ADD]);
        add(dp[i][j - arr[i] + ADD], dp[i + 1][j + ADD]);
      }
    }
    if (i != n - 1) {
      add(dp[i][arr[i] + ADD], 1);
      add(dp[i][-arr[i] + ADD], 1);
    }
    add(ans, dp[i][ADD]);
  }
  printf("%d\n", ans);
  return 0;
}