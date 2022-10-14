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
#line 2 "/tmp/tmp-169394b5Yo6CZThUSF.cpp"

#line 4 "/tmp/tmp-169394b5Yo6CZThUSF.cpp"

int main() {
  std::set<int> squares;
  for (int l = 1; l * l <= 1'000'000'000; ++l) {
    squares.insert(l * l);
  }
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    bool ok = false;
    ok |= (n % 2 == 0) && (squares.count(n / 2));
    ok |= (n % 4 == 0) && (squares.count(n / 4));
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}