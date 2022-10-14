#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-885806rWio3Q1We4lE.cpp"

const int M = 30;

using Dp = std::array<Long, M>;

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int k = io.read();
    Dp dp{};
    Long result = 0;
    for (int a : io.read_vector(n)) {
      for (int j = M; j--;) {
        dp[j] += (a >> j) - k;
        if (j) {
          dp[j] = std::max(dp[j], dp[j - 1] + (a >> j));
        }
      }
      result = std::max(result, *std::max_element(ALL(dp)));
    }
    std::cout << result << "\n";
  }
}