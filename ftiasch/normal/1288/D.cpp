#include <bits/stdc++.h>

const int N = 300000;
const int M = 8;

int n, m, a[N][M], idx[1 << M];

std::pair<int, int> check(int bound) {
  memset(idx, -1, sizeof(idx));
  for (int i = 0; i < n; ++i) {
    int msk = 0;
    for (int j = 0; j < m; ++j) {
      msk |= (a[i][j] >= bound) << j;
    }
    idx[msk] = i;
  }
  for (int msk = 0; msk < 1 << m; ++msk) {
    if (~idx[msk]) {
      for (int sub = msk;; sub = sub - 1 & msk) {
        int oth = (((1 << m) - 1) ^ msk) | sub;
        if (~idx[oth]) {
          return {idx[msk], idx[oth]};
        }
        if (!sub) {
          break;
        }
      }
    }
  }
  return {-1, -1};
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int low = 0;
  int high = 1e9;
  while (low < high) {
    int middle = low + high + 1 >> 1;
    if (~check(middle).first) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  auto res = check(low);
  printf("%d %d\n", res.first + 1, res.second + 1);
}