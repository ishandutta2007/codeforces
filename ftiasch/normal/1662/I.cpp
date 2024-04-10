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
#line 2 "/tmp/tmp-4448yPhBZPZQnZ8G.cpp"

#line 4 "/tmp/tmp-4448yPhBZPZQnZ8G.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int m = read();
  auto p = read_vector(n);
  auto q = read_vector(m);
  std::ranges::sort(q);
  std::vector<int> d(n, INT_MAX);
  for (int i = 0, j = 0; i < n; ++i) {
    int x = 100 * i;
    while (j < m && q[j] < x) {
      j++;
    }
    if (j < m) {
      d[i] = std::min(d[i], q[j] - x);
    }
    if (j) {
      d[i] = std::min(d[i], x - q[j - 1]);
    }
  }
  std::vector<std::pair<int, int>> events;
  events.reserve(n << 1);
  for (int i = 0; i < n; ++i) {
    int x = 100 * i;
    // d[i] == 0?
    events.emplace_back(x - d[i], p[i]);
    events.emplace_back(x + d[i], -p[i]);
  }
  Long result = 0, sum = 0;
  std::ranges::sort(events);
  for (auto [_, p] : events) {
    sum += p;
    result = std::max(result, sum);
  }
  std::cout << result << "\n";
}