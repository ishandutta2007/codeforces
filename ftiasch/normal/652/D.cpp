#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> values(n);
  std::vector<std::tuple<int, int, int>> intervals(n);
  for (int i = 0, l, r; i < n; ++i) {
    scanf("%d%d", &l, &r);
    intervals[i] = {r, l, i};
    values[i] = l;
  }
  std::sort(values.begin(), values.end());
  std::sort(intervals.begin(), intervals.end());
  std::vector<int> result(n), fenwick(n);
  for (auto [r, l, i] : intervals) {
    int ll = std::lower_bound(values.begin(), values.end(), l) - values.begin();
    for (int k = ll; k < n; k += ~k & k + 1) {
      result[i] += fenwick[k];
    }
    for (int k = ll; ~k; k -= ~k & k + 1) {
      fenwick[k]++;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", result[i]);
  }
}