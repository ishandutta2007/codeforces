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

template <typename T, typename Compare = std::less<T>>
struct PQ : public std::priority_queue<T, std::vector<T>, Compare> {
  T pop() {
    using Base = std::priority_queue<T, std::vector<T>, Compare>;
    auto t = Base::top();
    Base::pop();
    return t;
  }
};

template <typename T> using MinPQ = PQ<T, std::greater<T>>;
#line 2 "/tmp/tmp-45520oaQz0k56uB2.cpp"

auto make_vector(int n) {
  return std::array<std::vector<int>, 2>{std::vector<int>(n),
                                         std::vector<int>(n)};
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::array<std::vector<int>, 2> a;
    for (int i = 0; i < 2; ++i) {
      a[i] = io.read_vector(n);
    }
    a[0][0]--;
    auto bmax = make_vector(n + 1);
    auto fmax = make_vector(n + 1);
    for (int i = 0; i < 2; ++i) {
      bmax[i][n] = fmax[i][n] = INT_MIN;
      for (int j = n; j--;) {
        bmax[i][j] = std::max(a[i][j], bmax[i][j + 1] + 1);
        fmax[i][j] = std::max(a[i][j] + (n - j - 1), fmax[i][j + 1]);
      }
    }
    int result = INT_MAX, prefix = 0;
    for (int j = 0, i = 0; j <= n; ++j, i ^= 1) {
      result = std::min(result, std::max({
                                    prefix,
                                    fmax[i][j] + (n - j),
                                    bmax[i ^ 1][j],
                                }));
      if (j < n) {
        int steps = (n - j - 1) << 1;
        prefix = std::max({prefix, a[i][j] + steps + 1, a[i ^ 1][j] + steps});
      }
    }
    std::cout << result + 1 << "\n";
  }
}