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
#line 2 "/tmp/tmp-8858064Mua09eUJUrq.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto s = io.read_vector<std::string>(n);
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n));
    int result = 0;
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        if (!visited[x][y]) {
          int count[]{0, 0};
          int i = x, j = y;
          do {
            count[s[i][j] - '0']++;
            visited[i][j] = true;
            std::tie(i, j) = std::make_pair(n - 1 - j, i);
          } while (!visited[i][j]);
          result += std::min(count[0], count[1]);
        }
      }
    }
    std::cout << result << "\n";
  }
}