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
#line 2 "/tmp/tmp-56992nG4HkV6xQ7Nx.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int s = io.read();
    int result = -1, prefix_sum = 0;
    std::map<int, int> map;
    map[0] = 0;
    for (int i = 1; i <= n; ++i) {
      prefix_sum += io.read();
      auto iterator = map.find(prefix_sum - s);
      if (iterator != map.end()) {
        result = std::max(result, i - iterator->second);
      }
      map.emplace(prefix_sum, i);
    }
    std::cout << (~result ? n - result : -1) << "\n";
  }
}