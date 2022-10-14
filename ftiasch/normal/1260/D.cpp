#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int K = 200'000;

std::vector<std::tuple<int, int, int>> traps;

int solve(int mina) {
  // printf("mina=%d\n", mina);
  int result = 0, x = 0;
  for (auto [l, r, d] : traps) {
    if (mina < d) {
      // printf("+ [%d, %d]\n", l, r);
      if (l <= x) {
        result += std::max(r - x, 0);
      } else {
        result += r - l;
      }
      x = std::max(x, r);
    }
  }
  // printf("result=%d\n", result);
  return result;
}

int main() {
  int m, n, k, t;
  scanf("%d%d%d%d", &m, &n, &k, &t);
  t -= (n + 1);
  t >>= 1;
  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  for (int i = 0, l, r, d; i < k; ++i) {
    scanf("%d%d%d", &l, &r, &d);
    traps.emplace_back(l - 1, r, d);
  }
  std::sort(traps.begin(), traps.end());
  int low = 0;
  int high = m;
  while (low < high) {
    int middle = (low + high + 1) >> 1;
    if (solve(a[middle - 1]) <= t) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  printf("%d\n", low);
}