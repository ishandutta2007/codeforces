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
#line 2 "/tmp/tmp-330131QLcRv7tAbpKr.cpp"

#line 4 "/tmp/tmp-330131QLcRv7tAbpKr.cpp"

const int MOD = 1'000'000'007;

int main() {
  std::ios::sync_with_stdio(false);
  for (int T = read(); T--;) {
    int n = read();
    auto a = read_vector(n);
    auto b = read_vector(n);
    auto c = read_vector(n);
    std::vector<std::pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
      p[a[i] - 1] = {b[i] - 1, c[i] - 1};
    }
    int result = 1;
    std::vector<bool> visited(n);
    for (int u = 0; u < n; ++u) {
      if (!visited[u]) {
        int size = 0;
        bool fixed = false;
        int v = u;
        do {
          size++;
          fixed |= ~p[v].second;
          v = p[v].first;
          visited[v] = true;
        } while (v != u);
        if (size > 1 && !fixed) {
          result += result;
          if (result >= MOD) {
            result -= MOD;
          }
        }
      }
    }
    std::cout << result << "\n";
  }
}