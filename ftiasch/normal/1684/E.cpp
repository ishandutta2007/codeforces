#line 1 "util.h"
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

template <typename T> using Vector2D = std::vector<std::vector<T>>;

template <typename T = int> Vector2D<T> vector_2d(int n, int m) {
  return Vector2D<T>(n, std::vector<T>(m));
}

template <typename T = int> Vector2D<T> vector_2d(int n, int m, T d) {
  return Vector2D<T>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-696031R81bGuuwNt1L.cpp"

#line 4 "/tmp/tmp-696031R81bGuuwNt1L.cpp"

struct Quota : std::priority_queue<int> {
  Quota(int q) : q(q) {}

  void add(int v) {
    q -= v;
    push(v);
    while (q < 0) {
      q += top();
      pop();
    }
  }

  int q;
};

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int m = read();
    std::map<int, int> c;
    for (int a : read_vector(n)) {
      c[a]++;
    }
    int result = n;
    Quota quota(m);
    int holes = 0, distincts = 0;
    for (auto [k, v] : c) {
      if (n < k) {
        distincts++;
        quota.add(v);
      }
    }
    for (int mex = 0; mex <= n; ++mex) {
      holes += !c.count(mex);
    }
    for (int mex = n; mex >= 0; --mex) {
      holes -= !c.count(mex);
      {
        auto iterator = c.find(mex);
        if (iterator != c.end()) {
          distincts++;
          quota.add(iterator->second);
        }
      }
      if (holes <= m) {
        result = std::min<int>(result, distincts - quota.size());
      }
    }
    std::cout << result << std::endl;
  }
}