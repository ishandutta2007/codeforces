#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int N = 101;

int n, reward[N];
char s[N];
Long dp[N][N][N];

Long solve(int extra, int l, int r) {
  if (l > r) {
    assert(extra == 0);
    return 0;
  }
  Long &ref = dp[extra][l][r];
  if (ref == -1) {
    ref = solve(0, l, r - 1) + reward[extra + 1];
    for (int k = l; k < r; ++k) {
      if (s[k] == s[r]) {
        ref = std::max(ref, solve(extra + 1, l, k) + solve(0, k + 1, r - 1));
      }
    }
  }
  return ref;
}

int main() {
  scanf("%d%s", &n, s);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", reward + i);
  }
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", solve(0, 0, n - 1));
}