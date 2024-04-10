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
#line 2 "/tmp/tmp-536911vzfbk5q5nXDM.cpp"

int main() {
  IO io;
  auto ss = io.read1<std::string>();
  int n = ss.size();
  std::vector<char> s(n);
  std::copy(ALL(ss), s.begin());
  std::vector<int> fail(n), ffail(n);
  auto add = [&](int i) -> void {
    fail[i] = -1;
    if (i) {
      ffail[i - 1] = s[fail[i - 1] + 1] != s[i]
                         ? fail[i - 1]
                         : (~fail[i - 1] ? ffail[fail[i - 1]] : -1);
      int j = fail[i - 1];
      while (true) {
        if (s[j + 1] == s[i]) {
          fail[i] = j + 1;
          break;
        }
        if (!~j) {
          break;
        }
        j = ffail[j];
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    add(i);
  }
  for (int _ = io.read1(); _--;) {
    auto tt = io.read1<std::string>();
    int m = tt.size();
    s.resize(n + m);
    std::copy(ALL(tt), s.begin() + n);
    fail.resize(n + m);
    ffail.resize(n + m);
    for (int i = 0; i < m; ++i) {
      add(n + i);
    }
    for (int i = 0; i < m; ++i) {
      std::cout << fail[n + i] + 1 << " \n"[i + 1 == m];
    }
  }
}