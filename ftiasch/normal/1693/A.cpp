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
#line 2 "/tmp/tmp-262300RpP9p1xZdPcs.cpp"

bool check(int n, std::vector<Long> a) {
  int last_nz = n;
  while (last_nz && !a[last_nz - 1]) {
    last_nz--;
  }
  if (last_nz == 0) {
    return true;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      return false;
    }
    if (a[i] == 0) {
      return last_nz <= i + 1;
    }
    if (i + 1 == n) {
      return false;
    }
    a[i + 1] += a[i];
  }
  return false;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto a = io.read_vector<Long>(n);
    std::cout << (check(n, std::move(a)) ? "Yes" : "No") << "\n";
  }
}