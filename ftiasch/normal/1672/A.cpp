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
#line 2 "/tmp/tmp-127379sQl7dMn8e71g.cpp"

#line 4 "/tmp/tmp-127379sQl7dMn8e71g.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    CIN(int, T);
    while (T --) {
        CIN(int, n);
        int sg = 0;
        for (int i = 0; i < n; ++ i) {
            CIN(int, a);
            if (~a & 1) {
                sg ^= 1;
            }
        }
        std::cout << (sg ? "errorgorn" : "maomao90") << "\n";
    }
}