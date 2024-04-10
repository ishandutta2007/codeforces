#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define CIN(T, V)                                                              \
  T V;                                                                         \
  std::cin >> V;

#define ALL(v) (v).begin(), (v).end()

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-127379a0T0MEagrUli.cpp"

#line 4 "/tmp/tmp-127379a0T0MEagrUli.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  CIN(int, T);
  while (T--) {
    CIN(std::string, s);
    bool ok = true;
    int imbalance = 0, n = s.size();
    for (int i = 0; i < n && ok; ++i) {
      if (s[i] == 'A') {
        imbalance++;
      } else {
        imbalance--;
        ok &= imbalance >= 0;
      }
    }
    std::cout << (ok && s[n - 1] == 'B' ? "YES" : "NO") << "\n";
  }
}