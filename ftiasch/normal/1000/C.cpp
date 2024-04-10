#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::pair<Long, Long>> s(n);
  std::vector<Long> values;
  values.reserve(n << 1);
  for (int i = 0; i < n; ++i) {
    Long l, r;
    scanf("%lld%lld", &l, &r);
    s[i] = {l, r + 1};
    values.push_back(l);
    values.push_back(r + 1);
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  int m = values.size();
  std::vector<int> cover(m);
  for (auto [l, r] : s) {
    cover[std::lower_bound(values.begin(), values.end(), l) - values.begin()]++;
    cover[std::lower_bound(values.begin(), values.end(), r) - values.begin()]--;
  }
  std::vector<Long> result(n + 1);
  for (int i = 0; i + 1 < m; ++i) {
    result[cover[i]] += values[i + 1] - values[i];
    cover[i + 1] += cover[i];
  }
  for (int i = 1; i <= n; ++i) {
    printf("%lld%c", result[i], " \n"[i == n]);
  }
}