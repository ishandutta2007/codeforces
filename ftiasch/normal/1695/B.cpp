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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-91229zU2V79OmwIZ2.cpp"

bool check(int n, const std::vector<int> &a) {
  if (n & 1) {
    return true;
  }
  int m[]{INT_MAX, INT_MAX};
  for (int i = 0; i < n; ++i) {
    m[i & 1] = std::min(m[i & 1], a[i]);
  }
  if (m[0] != m[1]) {
    return m[0] > m[1];
  }
  for (int i = 0; i < n; i += 2) {
    if (m[0] == a[i]) {
      return false;
    }
    if (m[1] == a[i + 1]) {
      return true;
    }
  }
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto a = io.read_vector(n);
    std::cout << (check(n, a) ? "Mike" : "Joe") << "\n";
  }
}