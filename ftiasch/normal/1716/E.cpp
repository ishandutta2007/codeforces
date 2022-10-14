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
#line 2 "/tmp/tmp-21838UoD7A7ixZ97H.cpp"

struct Segment {
  Long sum, max, pmax, smax;
};

Segment concat(const Segment &u, const Segment &v) {
  return {u.sum + v.sum, std::max({u.max, u.smax + v.pmax, v.max}),
          std::max(u.pmax, u.sum + v.pmax), std::max(u.smax + v.sum, v.smax)};
}

int main() {
  IO io;
  int n = io.read();
  std::vector<Segment> dp(1 << n);
  for (int mask = 0; mask < 1 << n; ++mask) {
    int a = io.read();
    int m = std::max(a, 0);
    dp[mask] = {a, m, m, m};
  }
  for (int i = 0; i < n; ++i) {
    for (int mask0 = 0; mask0 < 1 << n; ++mask0) {
      if (~mask0 >> i & 1) {
        int mask1 = mask0 | 1 << i;
        std::tie(dp[mask0], dp[mask1]) = std::make_pair(
            concat(dp[mask0], dp[mask1]), concat(dp[mask1], dp[mask0]));
      }
    }
  }
  int q = io.read();
  int mask = 0;
  while (q--) {
    mask ^= 1 << (io.read());
    std::cout << dp[mask].max << "\n";
  }
}