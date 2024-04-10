#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

int dp[1002], p[1002];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  dp[1] = 2;
  for (int i = 2; i <= n; ++i) {
    dp[i] = 2;
    for (int j = p[i]; j < i; ++j) {
      dp[i] = (dp[i] + dp[j]) % mod;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[i]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}