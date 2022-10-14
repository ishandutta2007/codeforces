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
#line 2 "/tmp/tmp-215011hIgelqTeGQWj.cpp"

#line 4 "/tmp/tmp-215011hIgelqTeGQWj.cpp"

struct Solver {
  Solver(int n_) : n{n_}, tree(n), parent(n), up(n), size(n + n), stack(n) {
    for (int i = 0; i < n - 1; ++i) {
      int a = read() - 1;
      int b = read() - 1;
      int c = read() - 1;
      tree[a].emplace_back(b, c);
      tree[b].emplace_back(a, c);
    }
    for (int i = 0; i < n; ++i) {
      size[n + i] = n;
      stack[i].push_back(n + i);
    }
    parent[0] = -1;
    dfs(0);
  }

  int dfs(int u) {
    int size_u = 1;
    for (auto [v, w] : tree[u]) {
      if (v != parent[u]) {
        up[v] = stack[w].back();
        stack[w].push_back(v);
        parent[v] = u;
        int size_v = dfs(v);
        stack[w].pop_back();
        size[v] += size_v;
        size[up[v]] -= size_v;
        size_u += size_v;
      }
    }
    return size_u;
  }

  Long count() const {
    Long result = 0;
    for (int u = 0; u < n; ++u) {
      for (auto [v, _] : tree[u]) {
        if (v != parent[u]) {
          result += 1LL * size[v] * size[up[v]];
        }
      }
    }
    return result;
  }

  int n;
  std::vector<std::vector<std::pair<int, int>>> tree;
  std::vector<int> parent, up, size;
  std::vector<std::vector<int>> stack;
};

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  std::cout << Solver{n}.count() << "\n";
}