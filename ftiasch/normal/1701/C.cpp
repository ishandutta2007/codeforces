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
#line 2 "/tmp/tmp-50441021Rwswj1pgyC.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    std::vector<int> count(n);
    for (int i = 0; i < m; ++i) {
      count[io.read() - 1]++;
    }
    auto check = [&](int limit) {
      Long supply = 0, demand = 0;
      for (int i = 0; i < n; ++i) {
        if (count[i] <= limit) {
          supply += (limit - count[i]) >> 1;
        } else {
          demand += count[i] - limit;
        }
      }
      return supply >= demand;
    };
    int low = 0;
    int high = 2 * m;
    while (low < high) {
      int middle = (low + high) >> 1;
      if (check(middle)) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    std::cout << high << "\n";
  }
}