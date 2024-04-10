#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, L[602], R[602];

int dp[602][602], pr[602][602];

bool solve(int l, int r) {
  if (l > r) return true;
  if (dp[l][r] != -1) return dp[l][r];
  for (int pos = L[l] + (L[l] % 2 == 0); pos <= R[l] && pos <= 2 * (r - l + 1) - 1; pos += 2) {
    if (solve(l + 1, l + (pos / 2)) && solve(l + (pos / 2) + 1, r)) {
      pr[l][r] = pos;
      return dp[l][r] = true;
    }
  }
  return dp[l][r] = false;
}

char str[1502];

void build(int l, int r, int st = 0) {
  if (l > r) return;
  int pos = pr[l][r];
  str[st] = '(';
  str[st + pos] = ')';
  // puts(str);
  build(l + 1, l + (pos / 2), st + 1);
  build(l + (pos / 2) + 1, r, st + pos + 1);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &L[i], &R[i]);
  }
  memset(dp, -1, sizeof(dp));
  if (solve(0, n - 1)) {
    for (int i = 0; i < 2 * n; ++i)
      str[i] = '.';
    build(0, n - 1);
    puts(str);
  } else {
    puts("IMPOSSIBLE");
  }
  return 0;
}