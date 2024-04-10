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
#line 2 "/tmp/tmp-33797wDVtYAb1cn2h.cpp"

#line 4 "/tmp/tmp-33797wDVtYAb1cn2h.cpp"

struct Stat {
  Stat(int n) : count(n) {
    for (int i = 0; i < n; ++i) {
      set.insert(i);
    }
  }

  void add(int i, int delta) {
    if (!count[i]) {
      set.erase(i);
    }
    count[i] += delta;
    if (!count[i]) {
      set.insert(i);
    }
  }

  bool has(int l, int r) const {
    auto it = set.lower_bound(l);
    return it != set.end() && *it < r;
  }

  std::vector<int> count;
  std::set<int> set;
};

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int q = read();
  Stat xs(n), ys(n);
  while (q--) {
    int op = read();
    if (op == 3) {
      int x1 = read() - 1;
      int y1 = read() - 1;
      int x2 = read();
      int y2 = read();
      std::cout << (xs.has(x1, x2) && ys.has(y1, y2) ? "No" : "Yes") << "\n";
    } else {
      int x = read() - 1;
      int y = read() - 1;
      int delta = op == 1 ? 1 : -1;
      xs.add(x, delta);
      ys.add(y, delta);
    }
  }
}