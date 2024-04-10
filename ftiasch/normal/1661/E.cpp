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
#line 2 "/tmp/tmp-148550gEdgcGTS3Prd.cpp"
// #include "debug.h"

#line 5 "/tmp/tmp-148550gEdgcGTS3Prd.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  READ(int, n);
  std::vector<std::array<bool, 3>> s(n + 1);
  for (int i = 0; i < 3; ++i) {
    READ(std::string, buffer);
    for (int j = 0; j < n; ++j) {
      s[j][i] = (buffer[j] == '1');
    }
  }
  std::vector<int> vsum(n + 1), esum(n + 1), fsuml(n + 1), fsumr(n + 1);
  for (int i = n; i--;) {
    vsum[i] = s[i][0] + s[i][1] + s[i][2] + vsum[i + 1];
    esum[i] = (s[i][0] && s[i][1]) + (s[i][1] && s[i][2]) +
              (s[i][0] && s[i + 1][0]) + (s[i][1] && s[i + 1][1]) +
              (s[i][2] && s[i + 1][2]) + esum[i + 1];
  }
//   std::cerr << KV(esum[0]) << std::endl;
  const std::array<bool, 3> SOLID{true, true, true}, HOLLOW{true, false, true};
  for (int i = 0; i < n;) {
    if (s[i] == HOLLOW) {
      int j = i;
      while (j + 1 < n && s[j + 1] == HOLLOW) {
        j++;
      }
      if (i && s[i - 1] == SOLID && j + 1 < n && s[j + 1] == SOLID) {
        fsuml[i - 1]++;
        fsumr[j + 1]++;
      }
      i = j + 1;
    } else {
      if (s[i][0] && s[i][1] && s[i + 1][0] && s[i + 1][1]) {
        fsuml[i]++;
        fsumr[i + 1]++;
      }
      if (s[i][1] && s[i][2] && s[i + 1][1] && s[i + 1][2]) {
        fsuml[i]++;
        fsumr[i + 1]++;
      }
      i++;
    }
  }
  for (int i = n; i--;) {
    fsuml[i] += fsuml[i + 1];
    fsumr[i] += fsumr[i + 1];
  }
  READ(int, q);
  while (q--) {
    READ(int, l);
    READ(int, r);
    l--;
    int v = vsum[l] - vsum[r];
    int e = esum[l] - esum[r] - (s[r - 1][0] && s[r][0]) -
            (s[r - 1][1] && s[r][1]) - (s[r - 1][2] && s[r][2]);
    int f = std::max(fsuml[l] - fsumr[r], 0);
    std::cout << v - e + f << "\n";
  }
}