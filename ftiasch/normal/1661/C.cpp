#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define READ(T, V)                                                             \
  T V;                                                                         \
  std::cin >> V;

#define READ_VECTOR(T, V, n)                                                   \
  std::vector<T> V((n));                                                       \
  for (int i = 0; i < (n); ++i) {                                              \
    std::cin >> V[i];                                                          \
  }

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-79632j4arztRgRqEB.cpp"

#line 4 "/tmp/tmp-79632j4arztRgRqEB.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  READ(int, T);
  while (T--) {
    READ(int, n);
    READ_VECTOR(int, hs, n);
    auto check = [&](int target, Long middle) -> bool {
      Long ones = (middle + 1) >> 1;
      Long twos = middle - ones;
      for (int h : hs) {
        Long need = target - h;
        {
          Long t = std::min(need >> 1, twos);
          need -= t << 1;
          twos -= t;
        }
        if (need > ones) {
            return false;
        }
        ones -= need;
      }
      return true;
    };
    auto solve = [&](int target) -> Long {
      Long low = 0, high = static_cast<Long>(2'000'000'000) * n;
      while (low < high) {
        Long middle = (low + high) >> 1;
        if (check(target, middle)) {
          high = middle;
        } else {
          low = middle + 1;
        }
      }
      return high;
    };
    int maxh = *std::ranges::max_element(hs);
    std::cout << std::min(solve(maxh), solve(maxh + 1)) << std::endl;
  }
}