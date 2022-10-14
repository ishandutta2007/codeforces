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
#line 2 "/tmp/tmp-882161g0plkKLQVbOB.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 4 "/tmp/tmp-882161g0plkKLQVbOB.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<std::pair<int, int>> edges(n);
    for (int i = 0; i < n; ++i) {
      int a = io.read() - 1;
      int b = io.read() - 1;
      edges[i] = {a, b};
    }
    auto check = [&]() {
      std::vector<int> deg(n), size(n, 1);
      DSU dsu(n);
      for (auto [a, b] : edges) {
        deg[a]++;
        deg[b]++;
        if (deg[a] > 2 || deg[b] > 2) {
          return false;
        }
        int u = dsu.find(a);
        int v = dsu.find(b);
        if (u != v) {
          dsu.merge(u, v);
          size[v] += size[u];
        } else if (size[u] & 1) {
          return false;
        }
      }
      return true;
    };
    std::cout << (check() ? "YES" : "NO") << "\n";
  }
}