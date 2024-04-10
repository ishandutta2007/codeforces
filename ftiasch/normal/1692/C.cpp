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
#line 2 "/tmp/tmp-56992k6THugv4aCCh.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    std::array<int, 15> dcount{}, adcount{};
    for (int i = 0; i < 8; ++i) {
      auto row = io.read<std::string>();
      for (int j = 0; j < 8; ++j) {
        if (row[j] == '#') {
          dcount[i - j + 7]++;
          adcount[i + j]++;
        }
      }
    }
    int d = std::ranges::max_element(dcount) - dcount.begin() - 7;
    int ad = std::ranges::max_element(adcount) - adcount.begin();
    std::cout << 1 + ((d + ad) >> 1) << " " << 1 + ((ad - d) >> 1) << "\n";
  }
}