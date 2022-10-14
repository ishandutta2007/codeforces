#line 1 "util.h"
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
#line 2 "/tmp/tmp-900709tF7nk343pT85.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int m = io.read();
    auto a = io.read_vector(n);
    int lower = INT_MAX, upper = INT_MAX;
    for (int i = 0; i < n; ++i) {
      lower = std::min(lower, a[i] / m);
      upper = std::min(upper, a[i]);
    }
    int result = INT_MAX, maximum = 0;
    std::vector<std::vector<int>> events(upper + 1);
    for (int i = 0; i < n; ++i) {
      int q = a[i] / m;
      if (q + 1 <= upper) {
        events[q + 1].push_back(i);
      }
      maximum = std::max(maximum, q);
    }
    for (int minimum = lower; minimum <= upper; ++minimum) {
      for (int i : events[minimum]) {
        // max p. s.t. a[i] / minimum >= p
        int p = std::min(a[i] / minimum, m);
        int q = a[i] / p;
        if (q + 1 <= upper) {
          events[q + 1].push_back(i);
        }
        maximum = std::max(maximum, q);
      }
      events[minimum].clear();
      events[minimum].shrink_to_fit();
      result = std::min(result, maximum - minimum);
    }
    std::cout << result << "\n";
  }
}