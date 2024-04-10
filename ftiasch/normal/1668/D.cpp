#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T> using Vector2D = std::vector<std::vector<T>>;

template <typename T = int> Vector2D<T> vector_2d(int n, int m) {
  return Vector2D<T>(n, std::vector<T>(m));
}

template <typename T = int> Vector2D<T> vector_2d(int n, int m, T d) {
  return Vector2D<T>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T> std::vector<int> discretize(const std::vector<T> &a) {
  auto values = a;
  std::sort(ALL(values));
  values.erase(std::unique(ALL(values)), values.end());
  std::vector<int> result(a.size());
  for (int i = 0; i < a.size(); ++i) {
    result[i] = std::lower_bound(ALL(values), a[i]) - values.begin();
  }
  return result;
}
#line 2 "/tmp/tmp-4448JXuUuTPpaRn9.cpp"

#line 4 "/tmp/tmp-4448JXuUuTPpaRn9.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    std::vector<int> s;
    {
      std::vector<Long> sum(n + 1);
      for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + read();
      }
      s = discretize(sum);
    }
    std::vector<int> dp(n + 1), same(n + 1, -2 * n), positive(n + 1, -2 * n),
        negative(n + 1, -2 * n);
    for (int i = 0; i <= n; ++i) {
      if (i) {
        dp[i] = same[s[i]];
        for (int k = s[i] - 1; ~k; k -= ~k & k + 1) {
          dp[i] = std::max(dp[i], positive[k] + i);
        }
        for (int k = s[i] + 1; k <= n; k += ~k & k + 1) {
          dp[i] = std::max(dp[i], negative[k] - i);
        }
      }
      same[s[i]] = std::max(same[s[i]], dp[i]);
      for (int k = s[i]; k <= n; k += ~k & k + 1) {
        positive[k] = std::max(positive[k], dp[i] - i);
      }
      for (int k = s[i]; ~k; k -= ~k & k + 1) {
        negative[k] = std::max(negative[k], dp[i] + i);
      }
    }
    std::cout << dp[n] << "\n";
  }
}