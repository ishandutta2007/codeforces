#line 1 "/home/ftiasch/Documents/shoka/dsu.h"
#include <vector>

class DSU {
public:
  DSU(int n) : parent(n, -1) {}

  int find(int u) {
    if (!~parent[u]) {
      return u;
    }
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  bool merge(int a, int b) {
    if (find(a) == find(b)) {
      return false;
    }
    parent[find(a)] = find(b);
    return true;
  }

private:
  std::vector<int> parent;
};
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
#line 3 "/tmp/tmp-774758dWHVChIauzGs.cpp"

#line 5 "/tmp/tmp-774758dWHVChIauzGs.cpp"

struct Segment {
  Long max_pre = 0, sum = 0, max_suf = 0;
};

Segment singleton(int a) { return Segment{std::max(a, 0), a, std::max(a, 0)}; }

Segment operator+(const Segment &u, const Segment &v) {
  return {std::max(u.max_pre, u.sum + v.max_pre), u.sum + v.sum,
          std::max(u.max_suf + v.sum, v.max_suf)};
}

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    auto a = read_vector(n);
    std::vector<std::pair<int, int>> order(n);
    for (int i = 0; i < n; ++i) {
      order[i] = {a[i], i};
    }
    std::ranges::sort(order);
    std::vector<bool> visited(n);
    std::vector<Segment> s(n);
    DSU dsu(n);
    bool ok = true;
    for (auto [a, i] : order) {
      Segment left, right;
      if (i && visited[i - 1]) {
        left = s[dsu.find(i - 1)];
      }
      if (i + 1 < n && visited[i + 1]) {
        right = s[dsu.find(i + 1)];
      }
      ok &= a >= left.max_suf + a + right.max_pre;
      s[i] = left + singleton(a) + right;
      if (i && visited[i - 1]) {
        dsu.merge(i - 1, i);
      }
      if (i + 1 < n && visited[i + 1]) {
        dsu.merge(i + 1, i);
      }
      visited[i] = true;
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}