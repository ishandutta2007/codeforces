#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define READ(T, V)                                                             \
  T V;                                                                         \
  std::cin >> V;

#define READ_VECTOR(T, V, n)                                                   \
  std::vector<T> V((n));                                                       \
  for (int i = 0; i < (n); ++i) {                                              \
    std::cin >> V[i];                                                          \
  }

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-186096lZbrMvTQ7AB.cpp"

#line 4 "/tmp/tmp-186096lZbrMvTQ7AB.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  READ(int, T);
  while (T--) {
    READ(std::string, buffer);
    int n = buffer.size();
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
      s[i] = buffer[i] - 'a' + 1;
    }
    int sum = std::accumulate(ALL(s), 0), a, b;
    if (n & 1) {
      b = std::min(s[0], s[n - 1]);
      a = sum - b;
    } else {
      a = sum;
      b = 0;
    }
    std::cout << (a > b ? "Alice " : "Bob ") << std::abs(a - b) << "\n";
  }
}