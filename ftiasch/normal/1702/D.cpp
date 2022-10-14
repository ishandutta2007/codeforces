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
#line 2 "/tmp/tmp-882161gRO0TFDQgLiZ.cpp"

const int C = 26;

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    auto s = io.read<std::string>();
    int limit = io.read();
    int n = s.size();
    std::vector<int> index(n), count(C);
    for (int i = 0; i < n; ++i) {
      int c = s[i] - 'a';
      index[i] = count[c]++;
      limit -= (c + 1);
    }
    for (int c = C; c-- && limit < 0;) {
      while (count[c] > 0 && limit < 0) {
        count[c]--;
        limit += c + 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (index[i] < count[s[i] - 'a']) {
        std::cout << s[i];
      }
    }
    std::cout << "\n";
  }
}