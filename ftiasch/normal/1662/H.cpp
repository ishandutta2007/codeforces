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

template <typename T> std::vector<int> discretize(const std::vector<T> &a) {
  auto values = a;
  std::sort(ALL(values));
  values.erase(std::unique(ALL(values)), values.end());
  std::vector<int> result(a.size());
  for (int i = 0; i < a.size(); ++i) {
    result[i] = std::lower_bound(ALL(values), a[i]) - values.begin();
  }
  return result;
}
#line 2 "/tmp/tmp-44485fJkDeePEaSb.cpp"

#line 4 "/tmp/tmp-44485fJkDeePEaSb.cpp"

struct DivSet : std::set<int> {
  void add_divisor_of(int n) {
    for (int d = 1; d * d <= n; ++d) {
      if (n % d == 0) {
        insert(d);
        insert(n / d);
      }
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int a = read() - 2;
    int b = read() - 2;
    DivSet s;
    s.insert(1);
    if ((~a & 1) && (b & 1) || (a & 1) && (~b & 1)) {
      s.insert(2);
    }
    s.add_divisor_of(std::__gcd(a, b + 2));
    s.add_divisor_of(std::__gcd(a + 2, b));
    s.add_divisor_of(std::__gcd(a + 1, b + 1));
    std::cout << s.size();
    for (int a : s) {
      std::cout << " " << a;
    }
    std::cout << "\n";
  }
}