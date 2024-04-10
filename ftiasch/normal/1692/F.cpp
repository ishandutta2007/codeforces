#line 1 "/home/ftiasch/Documents/shoka/nd_array.h"
#include <array>

namespace details {

template <typename T, int... NS> struct NDArrayFactory;

template <typename T, int N0, int... NS> struct NDArrayFactory<T, N0, NS...> {
  using Array = std::array<typename NDArrayFactory<T, NS...>::Array, N0>;
};

template <typename T, int N0> struct NDArrayFactory<T, N0> {
  using Array = std::array<T, N0>;
};

} // namespace details

template <typename T, int... NS>
using NDArray = typename details::NDArrayFactory<T, NS...>::Array;
#line 2 "/tmp/tmp-56992Fh0agITKZO2K.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 4 "/tmp/tmp-56992Fh0agITKZO2K.cpp"

using Dp = NDArray<bool, 4, 10>;

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    Dp dp{};
    dp[0][0] = true;
    for (int a : io.read_vector(n)) {
      Dp new_dp = dp;
      for (int i = 0; i < 3; ++i) {
        for (int r = 0; r < 10; ++r) {
          new_dp[i + 1][(r + a) % 10] |= dp[i][r];
        }
      }
      dp.swap(new_dp);
    }
    std::cout << (dp[3][3] ? "YES" : "NO") << "\n";
  }
}