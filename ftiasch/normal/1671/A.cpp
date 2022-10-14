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
#line 2 "/tmp/tmp-91692DFw8AnY3pJld.cpp"

#line 4 "/tmp/tmp-91692DFw8AnY3pJld.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  CIN(int, T);
  while (T--) {
    CIN(std::string, s);
    s = "c" + s + "c";
    bool ok = true;
    for (int i = 1; i + 1 < s.size(); ++i) {
      ok &= s[i - 1] == s[i] || s[i] == s[i + 1];
    }
    puts(ok ? "YES" : "NO");
  }
}