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
#line 2 "/tmp/tmp-7080364490SjS2mgpf.cpp"

#line 4 "/tmp/tmp-7080364490SjS2mgpf.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  Long x = read<Long>();
  std::set<Long> s{x};
  std::queue<std::pair<Long, int>> q;
  q.emplace(x, 0);
  int result = -1;
  while (!q.empty()) {
    auto [x, dx] = q.front();
    q.pop();
    int length = 0;
    std::array<bool, 10> digits{};
    {
      Long y = x;
      while (y > 0) {
        length++;
        digits[y % 10] = true;
        y /= 10;
      }
    }
    if (length == n) {
      result = dx;
      break;
    }
    for (int d = 2; d < 10; ++d) {
      if (digits[d]) {
        Long xy = x * d;
        if (!s.count(xy)) {
          q.emplace(xy, dx + 1);
          s.insert(xy);
        }
      }
    }
  }
  std::cout << result << "\n";
}