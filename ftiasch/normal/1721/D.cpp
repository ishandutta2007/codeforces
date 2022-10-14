#line 1 "util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  explicit IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  template <typename... T> std::tuple<T...> read() const {
    std::tuple<T...> t;
    read_tuple(t, std::make_index_sequence<sizeof...(T)>());
    return t;
  }

  template <typename T = int> T read1() const { return std::get<0>(read<T>()); }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read1<T>();
    }
    return v;
  }

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }

private:
  template <typename Tuple, size_t... Index>
  static void read_tuple(Tuple &t, std::index_sequence<Index...>) {
    (..., (std::cin >> std::get<Index>(t)));
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
#line 2 "/tmp/tmp-64734m6howAuv4jzl.cpp"

int main() {
  IO io;
  int T = io.read1();
  while (T--) {
    int n = io.read1();
    auto a = io.read_vector(n);
    auto b = io.read_vector(n);
    std::vector<int> aa(n), bb(n);
    auto test = [&](int x) -> bool {
      std::transform(ALL(a), aa.begin(), [&](int a) { return a & x; });
      std::sort(ALL(aa));
      std::transform(ALL(b), bb.begin(), [&](int b) { return (b & x) ^ x; });
      std::sort(ALL(bb));
      return std::equal(ALL(aa), bb.begin());
    };
    int result = 0;
    for (int i = 30; i--;) {
      if (test(result | 1 << i)) {
        result |= 1 << i;
      }
    }
    std::cout << result << "\n";
  }
}