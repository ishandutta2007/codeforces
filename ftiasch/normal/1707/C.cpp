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
#line 1 "/home/ftiasch/Documents/shoka/y_combinator.h"
#include <functional>

// Authored by ecnerwala

namespace details {

template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

} // namespace details

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return details::y_combinator_result<std::decay_t<Fun>>(
      std::forward<Fun>(fun));
}
#line 3 "/tmp/tmp-12490127bM4ZT9W7vJK.cpp"

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

template <typename T, typename Compare = std::less<T>>
struct PQ : public std::priority_queue<T, std::vector<T>, Compare> {
  T pop() {
    using Base = std::priority_queue<T, std::vector<T>, Compare>;
    auto t = Base::top();
    Base::pop();
    return t;
  }
};
#line 5 "/tmp/tmp-12490127bM4ZT9W7vJK.cpp"

int main() {
  IO io;
  int n = io.read();
  int m = io.read();
  DSU dsu(n);
  std::vector<std::vector<int>> tree(n), non_tree_edges(n);
  for (int i = 0; i < m; ++i) {
    int a = io.read() - 1;
    int b = io.read() - 1;
    if (dsu.merge(a, b)) {
      tree[a].push_back(b);
      tree[b].push_back(a);
    } else {
      non_tree_edges[a].push_back(b);
      non_tree_edges[b].push_back(a);
    }
  }
  std::vector<bool> done(n);
  std::vector<int> current_child(n, -1), delta(n);
  y_combinator([&](auto dfs, int p, int u) -> void {
    done[u] = true;
    for (int v : non_tree_edges[u]) {
      if (done[v]) {
        if (~current_child[v]) {
          delta[u]++;
          delta[0]++;
          delta[current_child[v]]--;
        } else {
          delta[u]++;
          delta[v]++;
        }
      }
    }
    for (int v : tree[u]) {
      if (v != p) {
        current_child[u] = v;
        dfs(u, v);
      }
    }
    current_child[u] = -1;
  })(-1, 0);
  std::vector<char> result(n + 1, '\0');
  y_combinator([&](auto dfs, int p, int u, int sum) -> void {
    sum += delta[u];
    result[u] = "01"[sum == m - (n - 1)];
    for (int v : tree[u]) {
      if (v != p) {
        dfs(u, v, sum);
      }
    }
  })(-1, 0, 0);
  std::cout << result.data() << "\n";
}