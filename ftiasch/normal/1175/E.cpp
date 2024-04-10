#include <bits/stdc++.h>

using Pair = std::pair<int, int>;

const int N = 200'000;
const int D = 19;

int n, jump[N][D];
Pair intervals[N], prefix_max[N];

int cover(int r) {
  auto iterator =
      std::upper_bound(prefix_max, prefix_max + n, Pair{r, INT_MAX});
  if (iterator == prefix_max) {
    return -1;
  }
  return std::prev(iterator)->second;
}

int solve(int l, int r) {
  int i = cover(l);
  if (i == -1 || intervals[i].second < l ||
      intervals[jump[i][D - 1]].second < r) {
    return -1;
  }
  if (r <= intervals[i].second) {
    return 1;
  }
  int result = 2;
  for (int d = D; d--;) {
    if (intervals[jump[i][d]].second < r) {
      i = jump[i][d];
      result += 1 << d;
    }
  }
  return result;
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &intervals[i].first, &intervals[i].second);
  }
  std::sort(intervals, intervals + n);
  {
    Pair max{-1, -1};
    for (int i = 0; i < n; ++i) {
      auto [l, r] = intervals[i];
      max = std::max(max, {r, i});
      prefix_max[i] = {l, max.second};
    }
  }
  for (int i = 0; i < n; ++i) {
    jump[i][0] = cover(intervals[i].second);
  }
  for (int i = n; i--;) {
    for (int d = 1; d < D; ++d) {
      jump[i][d] = jump[jump[i][d - 1]][d - 1];
    }
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", solve(l, r));
  }
}