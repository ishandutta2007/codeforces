#line 1 "sol.cpp"
#include <bits/stdc++.h>

std::vector<int> get_pairs(int n, const std::vector<int> &a) {
  std::vector<int> pairs;
  pairs.reserve((n - 1) * n / 2);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      pairs.push_back(a[i] + a[j]);
    }
  }
  std::sort(pairs.begin(), pairs.end());
  return pairs;
}

std::vector<int> restore(int n, const std::vector<int> &a, int count,
                         int target) {
  if (count == 0) {
    return {};
  }
  if (count == 1) {
    return {
        static_cast<int>(std::find(a.begin(), a.end(), target) - a.begin()) +
        1};
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] + a[j] == target) {
        return {i + 1, j + 1};
      }
    }
  }
}

int main() {
  int n, m;
  scanf("%d", &n);
  long long sum0 = 0;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum0 += a[i];
  }
  scanf("%d", &m);
  std::vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    sum0 -= b[i];
  }
  auto a_pairs = get_pairs(n, a);
  auto b_pairs = get_pairs(m, b);
  std::tuple<long long, int, int, int> result{std::abs(sum0), 0, 0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      result = std::min(
          result, {std::abs(sum0 - 2LL * a[i] + 2LL * b[j]), 1, a[i], b[j]});
    }
  }
  {
    int j = 0;
    for (auto &&a_pair : a_pairs) {
      // sum0 - 2LL * a_pair + 2 * b_pairs <= 0
      while (j < b_pairs.size() && sum0 - 2LL * a_pair + 2LL * b_pairs[j] < 0) {
        j++;
      }
      if (j < b_pairs.size()) {
        result = std::min(result, {sum0 - 2LL * a_pair + 2LL * b_pairs[j], 2,
                                   a_pair, b_pairs[j]});
      }
      if (j) {
        result = std::min(result, {-sum0 + 2LL * a_pair - 2LL * b_pairs[j - 1],
                                   2, a_pair, b_pairs[j - 1]});
      }
    }
  }
  auto [min_sum, count, a_sum, b_sum] = result;
  printf("%lld\n%d\n", min_sum, count);
  auto a_plan = restore(n, a, count, a_sum);
  auto b_plan = restore(m, b, count, b_sum);
  for (int i = 0; i < count; ++i) {
    printf("%d %d\n", a_plan[i], b_plan[i]);
  }
}