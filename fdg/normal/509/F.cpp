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

int b[505];

int dp[505][505];

int solve(int l, int r) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) return dp[l][r] = 1;
  int ans = 0;
  for (int i = l + 1; i <= r; ++i) {
    if (i == r || b[i + 1] > b[l + 1]) {
      ans = (ans + 1LL * solve(l + 1, i) * solve(i, r)) % mod;
    }
  }
  return dp[l][r] = ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, n - 1) << endl;
  return 0;
}