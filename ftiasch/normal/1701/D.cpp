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
#line 2 "/tmp/tmp-504410DZsmwg4oPy3V.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<std::tuple<int, int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
      int b = io.read();
      // b <= (i + 1) / x < b + 1
      // <=> (i + 1) / (b + 1) < x <= (i + 1) / b
      intervals[i] = {(i + 1) / (b + 1) + 1, b ? (i + 1) / b : n, i};
    }
    std::sort(ALL(intervals));
    std::vector<int> a(n);
    auto iterator = intervals.begin();
    MinPQ<std::pair<int, int>> pq;
    for (int i = 1; i <= n; ++i) {
      while (iterator != intervals.end() && std::get<0>(*iterator) <= i) {
        auto [_, r, j] = *(iterator++);
        pq.emplace(r, j);
      }
      a[pq.top().second] = i;
      pq.pop();
    }
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] << " \n"[i + 1 == n];
    }
  }
}