#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<long long> s(n + 1);
  std::vector<std::pair<long long, int>> minsuf(n + 1);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    s[i] = a;
  }
  minsuf[n] = {0, n};
  for (int i = n; i--;) {
    s[i] += s[i + 1];
    minsuf[i] = std::min({s[i], i}, minsuf[i + 1]);
  }
  std::pair<long long, int> minpre = {std::numeric_limits<long long>::max(),
                                      -1};
  std::tuple<long long, int, int, int> result = {
      std::numeric_limits<long long>::min(), -1, -1, -1};
  for (int i = 0; i <= n; ++i) {
    minpre = std::min(minpre, {s[i], i});
    result = std::max(result,
                      {s[0] - 2 * minpre.first + 2 * s[i] - 2 * minsuf[i].first,
                       minpre.second, i, minsuf[i].second});
  }
  auto [_, i, j, k] = result;
  printf("%d %d %d\n", i, j, k);
}