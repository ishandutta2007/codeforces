// #include "debug.h"

#include <bits/stdc++.h>

using VI = std::vector<int>;

std::pair<int, int> find_first_and_last(const VI &v, int x) {
  int first = std::find(v.begin(), v.end(), x) - v.begin();
  int last = static_cast<int>(
                 v.size() - (std::find(v.rbegin(), v.rend(), x) - v.rbegin())) -
             1;
  return {first, last};
}

std::pair<int, int> solve(const VI &v) {
  VI sum(v.size() + 1);
  std::inclusive_scan(v.begin(), v.end(), sum.begin() + 1);
  // sum[0] = 0
  int min_sum = *std::min_element(sum.begin(), sum.end());
  int max_sum = *std::max_element(sum.begin(), sum.end());
  int result0 = max_sum - min_sum + 1;
  // std::cout << KV(v) << KV(sum) << KV(result0) << std::endl;
  auto [first_min, last_min] = find_first_and_last(sum, min_sum);
  auto [first_max, last_max] = find_first_and_last(sum, max_sum);
  int result1 = result0;
  if (result1 > 2 && (last_min < first_max || last_max < first_min)) {
    result1--;
  }
  return {result0, result1};
}

char s[200'001];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    VI v[2];
    for (int i = 0; s[i]; ++i) {
      v[s[i] == 'W' || s[i] == 'S'].push_back(s[i] == 'W' || s[i] == 'D' ? 1
                                                                         : -1);
    }
    auto [x0, x1] = solve(v[0]);
    auto [y0, y1] = solve(v[1]);
    printf("%lld\n", std::min(1LL * x0 * y1, 1LL * x1 * y0));
  }
}