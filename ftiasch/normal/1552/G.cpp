#include <bits/stdc++.h>

using u64 = uint64_t;

const int N = 40;
const int M = 10;

int n, m, k[M], q[M + 1];
u64 suffix[M][N + 1];

bool dfs(int i, u64 s) {
  if (i == m) {
    return ((s & ~s >> 1) & ((1ULL << (n - 1)) - 1ULL)) == 0;
  }
  int c = __builtin_popcountll(s & suffix[i][0]);
  s &= ~suffix[i][0];
  for (int j = c; j <= c + q[i]; ++j) {
    if (!dfs(i + 1, s | suffix[i][k[i] - j])) {
      return false;
    }
  }
  return true;
}

bool check() {
  if (q[m] > 1) {
    return false;
  }
  if (n == 1) {
    return true;
  }
  return dfs(0, 0);
}

int main() {
  scanf("%d%d", &n, &m);
  u64 untouched = (1ULL << n) - 1;
  for (int i = 0; i < m; ++i) {
    scanf("%d", k + i);
    static int index[N];
    for (int j = 0; j < k[i]; ++j) {
      scanf("%d", index + j);
      index[j]--;
    }
    suffix[i][k[i]] = 0;
    for (int j = k[i]; j--;) {
      suffix[i][j] = 1ULL << index[j] | suffix[i][j + 1];
    }
    q[i] = __builtin_popcountll(untouched & suffix[i][0]);
    untouched &= ~suffix[i][0];
  }
  q[m] = __builtin_popcountll(untouched);
  puts(check() ? "ACCEPTED" : "REJECTED");
}