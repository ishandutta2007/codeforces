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
#line 2 "/tmp/tmp-900709lB9fuJWBqYBb.cpp"

auto indices(int n, const std::string &s) {
  std::vector<int> result;
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == s[i]) {
      result.push_back(i);
    }
  }
  return result;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto s = io.read<std::string>();
    auto t = io.read<std::string>();
    auto a = indices(n, s);
    auto b = indices(n, t);
    Long result = -1;
    if (s[0] == t[0] && s[n - 1] == t[n - 1] && a.size() == b.size()) {
      result = 0;
      for (int i = 0; i < a.size(); ++i) {
        result += std::abs(a[i] - b[i]);
      }
    }
    std::cout << result << "\n";
  }
}