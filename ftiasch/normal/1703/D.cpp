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
#line 2 "/tmp/tmp-8858069276PiR71twi.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto s = io.read_vector<std::string>(n);
    std::set<std::string> ss;
    for (int i = 0; i < n; ++i) {
      ss.insert(s[i]);
    }
    std::vector<char> result(n + 1);
    for (int i = 0; i < n; ++i) {
      bool ok = false;
      for (int j = 1; j < s[i].size() && !ok; ++j) {
        ok |= ss.count(s[i].substr(0, j)) &&
              ss.count(s[i].substr(j, s[i].size()));
      }
      result[i] = '0' + ok;
    }
    std::cout << result.data() << "\n";
  }
}