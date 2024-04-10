#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, limit;
  scanf("%d%d", &n, &limit);
  std::vector<int> values(n << 1);
  std::vector<std::pair<int, int>> segments(n);
  for (int i = 0, l, r; i < n; ++i) {
    scanf("%d%d", &l, &r);
    values[i << 1] = l;
    values[i << 1 | 1] = r;
    segments[i] = {l, r};
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  std::vector<int> sum(values.size() << 1);
  for (auto [l, r] : segments) {
    int ll = std::lower_bound(values.begin(), values.end(), l) - values.begin();
    int rr = std::lower_bound(values.begin(), values.end(), r) - values.begin();
    sum[ll << 1]++;
    sum[(rr << 1) + 1]--;
  }
  for (int i = 1; i < sum.size(); ++i) {
    sum[i] += sum[i - 1];
  }
  std::vector<std::pair<int, int>> plan;
  for (int i = 0; i < sum.size(); ++i) {
    if (sum[i] < limit) {
      i++;
    } else {
      int j = i;
      while (j < sum.size() && sum[j] >= limit) {
        j++;
      }
      plan.emplace_back(values[i >> 1], values[j >> 1]);
      i = j;
    }
  }
  printf("%d\n", static_cast<int>(plan.size()));
  for (auto [l, r] : plan) {
    printf("%d %d\n", l, r);
  }
}