#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500'000;
const int M = 1'000'000 + 1;

int n, limit, a[N], count[M];

int main() {
  scanf("%d%d", &n, &limit);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::tuple<int, int, int> best{0, 0, 0};
  for (int i = 0, j = 0, kind = 0; i < n; ++i) {
    kind += !(count[a[i]]++);
    while (kind > limit) {
      kind -= !(--count[a[j++]]);
    }
    best = std::max(best, {i - j + 1, j, i});
  }
  auto [_, l, r] = best;
  printf("%d %d\n", l + 1, r + 1);
}