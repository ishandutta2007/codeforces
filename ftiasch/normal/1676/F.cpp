#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-141040rrhOv9aL6IGJ.cpp"

#line 4 "/tmp/tmp-141040rrhOv9aL6IGJ.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int limit = read();
    std::map<int, int> count;
    for (int a : read_vector(n)) {
      count[a]++;
    }
    auto i = count.begin();
    std::tuple<int, int, int> result{-1, -1, -1};
    while (i != count.end()) {
      if (i->second < limit) {
        i++;
      } else {
        auto j = i;
        while (true) {
          auto jj = std::next(j);
          if (jj == count.end() || j->first + 1 < jj->first ||
              jj->second < limit) {
            break;
          }
          j = jj;
        }
        result = std::max(
            result, std::make_tuple(j->first - i->first, i->first, j->first));
        i = std::next(j);
      }
    }
    auto [_, l, r] = result;
    if (~l) {
      std::cout << l << " " << r << "\n";
    } else {
      std::cout << -1 << "\n";
    }
  }
}