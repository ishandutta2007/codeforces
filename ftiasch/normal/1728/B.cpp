#line 1 "/home/ftiasch/Documents/shoka/util.h"
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
#line 2 "/tmp/tmp-219118Ms7KWUjLFLY3.cpp"

int main() {
  IO io;
  int T = io.read1();
  while (T--) {
    int n = io.read1();
    std::vector<int> p;
    p.reserve(n);
    for (int i = n - 2; i >= 1; --i) {
      p.push_back(i);
    }
    p.push_back(n - 1);
    p.push_back(n);
    if (n & 1) {
      std::swap(p[0], p[n - 2]);
    }
    for (int i = 0; i < n; ++i) {
      std::cout << p[i] << " \n"[i + 1 == n];
    }
  }
}