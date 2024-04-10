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
#line 2 "/tmp/tmp-900709NRG9rKgjwFeM.cpp"

int main() {
  IO io;
  int n = io.read();
  int q = io.read();
  auto a = io.read_vector(n);
  std::map<int, int> ones;
  auto add = [&](int x) {
    while (true) {
      auto iterator = ones.lower_bound(x);
      if (iterator != ones.end() && iterator->second < x) {
        auto [r, l] = *iterator;
        ones.erase(iterator);
        if (l < x - 1) {
          ones[x - 1] = l;
        }
        x = r + 1;
      } else {
        ones[x] = x - 1;
        break;
      }
    }
  };
  auto sub = [&](int x) {
    auto iterator = ones.lower_bound(x);
    assert(iterator != ones.end());
    auto [r, l] = *iterator;
    ones.erase(iterator);
    if (l < x) {
      if (l < x - 1) {
        ones[x - 1] = l;
      }
      if (x < r) {
        ones[r] = x;
      }
    } else {
      ones[l] = x - 1;
      if (l + 1 < r) {
        ones[r] = l + 1;
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    add(a[i]);
  }
  while (q--) {
    int k = io.read() - 1;
    int l = io.read();
    sub(a[k]);
    add(a[k] = l);
    std::cout << ones.rbegin()->first << "\n";
  }
}