#line 1 "Documents/shoka/util.h"
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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-262300PkNgWirVi8qM.cpp"

int main() {
  IO io;
  int n = io.read();
  auto a = io.read_vector(n);
  std::vector<int> u(n, n + 1), d(n, 0);
  Long result = 0;
  int count = 0;
  for (int i = n; i--;) {
    count++;
    for (int j = i + 1; j < n; ++j) {
      count -= u[j] > 0 || d[j] <= n;
      int old_u = u[j];
      int old_d = d[j];
      u[j] = 0;
      if (a[j - 1] < a[j]) {
        u[j] = std::max(u[j], u[j - 1]);
      }
      if (d[j - 1] < a[j]) {
        u[j] = std::max(u[j], a[j - 1]);
      }
      d[j] = n + 1;
      if (a[j - 1] > a[j]) {
        d[j] = std::min(d[j], d[j - 1]);
      }
      if (u[j - 1] > a[j]) {
        d[j] = std::min(d[j], a[j - 1]);
      }
      count += u[j] > 0 || d[j] <= n;
      if (u[j] == old_u && d[j] == old_d) {
        break;
      }
    }
    result += count;
  }
  std::cout << result << "\n";
}