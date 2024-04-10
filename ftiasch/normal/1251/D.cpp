#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    long long s;
    scanf("%d%lld", &n, &s);
    std::vector<std::pair<int, int>> ranges(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &ranges[i].first, &ranges[i].second);
    }
    std::sort(ranges.begin(), ranges.end());
    int low = 1;
    int high = 1e9;
    while (low < high) {
      int middle = (low + high + 1) >> 1;
      auto check = [&]() {
        int sum = n >> 1;
        long long used = 0;
        for (auto [l, r] : ranges) {
          if (r < middle) {
            sum--;
            used += l;
          } else if (middle <= l) {
            used += l;
          }
        }
        if (sum < 0) {
          return false;
        }
        for (auto [l, r] : ranges) {
          if (l < middle && middle <= r) {
            if (sum > 0) {
              used += l;
              sum--;
            } else {
              used += middle;
            }
          }
        }
        return used <= s;
      }();
      if (check) {
        low = middle;
      } else {
        high = middle - 1;
      }
    }
    printf("%d\n", low);
  }
}