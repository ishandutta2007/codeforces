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
#line 2 "/tmp/tmp-45591QiuPtqJIL5fm.cpp"

#line 4 "/tmp/tmp-45591QiuPtqJIL5fm.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  READ(int, T);
  while (T--) {
    READ(std::string, s);
    std::set<char> cs;
    int k = 0;
    while (k < s.size() && cs.insert(s[k]).second) {
      k++;
    }
    bool ok = true;
    for (int i = k; i < s.size(); ++i) {
      ok &= s[i - k] == s[i];
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}