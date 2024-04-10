#include <bits/stdc++.h>

namespace {

const int N = 200'000;
const int D = 18;

using Edge = std::tuple<int, int, int>; // cap, a, b

using Query = std::tuple<int, int, int>; // x, v, id

int n, q, e[N];
std::vector<std::pair<int, int>> tree[N];
Edge edges[N - 1];
Query queries[N];

int depth[N];
std::pair<int, int> jump[N][D];

void prepare(int p, int u) {
  depth[u] = ~p ? depth[p] + 1 : 0;
  for (int j = 1; j < D; ++j) {
    int v = jump[u][j - 1].first;
    if (~v) {
      jump[u][j] = {jump[v][j - 1].first,
                    std::max(jump[u][j - 1].second, jump[v][j - 1].second)};
    } else {
      jump[u][j] = {-1, -1};
    }
  }
  for (auto [v, toll] : tree[u]) {
    if (v != p) {
      jump[v][0] = {u, toll};
      prepare(u, v);
    }
  }
}

int query_max(int a, int b) {
  if (depth[a] > depth[b]) {
    return query_max(b, a);
  }
  int result = 0;
  for (int j = D; j--;) {
    if ((depth[b] - depth[a]) >> j & 1) {
      result = std::max(result, jump[b][j].second);
      b = jump[b][j].first;
    }
  }
  if (a == b) {
    return result;
  }
  for (int j = D; j--;) {
    if (jump[a][j].first != jump[b][j].first) {
      result = std::max({result, jump[a][j].second, jump[b][j].second});
      a = jump[a][j].first;
      b = jump[b][j].first;
    }
  }
  return std::max({result, jump[a][0].second, jump[b][0].second});
}

struct Summary {
  std::pair<int, int> query(int u) const {
    return {max_e, std::max(max_toll, query_max(u, v))};
  }

  int v, max_e, max_toll;
};

Summary singleton(int v) { return {v, e[v], 0}; }

Summary operator+(const Summary &a, const Summary &b) {
  if (a.max_e != b.max_e) {
    return a.max_e > b.max_e ? a : b;
  }
  return Summary{a.v, a.max_e,
                 std::max({a.max_toll, b.max_toll, query_max(a.v, b.v)})};
}

int parent[N];
Summary summary[N];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

std::pair<int, int> result[N];

} // namespace

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", e + i);
  }
  for (int i = 0, cap, toll, a, b; i < n - 1; ++i) {
    scanf("%d%d%d%d", &a, &b, &cap, &toll);
    a--;
    b--;
    edges[i] = {cap, a, b};
    tree[a].emplace_back(b, toll);
    tree[b].emplace_back(a, toll);
  }
  jump[0][0] = {-1, -1};
  prepare(-1, 0);
  std::sort(edges, edges + (n - 1));
  for (int i = 0, v, x; i < q; ++i) {
    scanf("%d%d", &x, &v);
    queries[i] = {x, v - 1, i};
  }
  std::sort(queries, queries + q);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
    summary[i] = singleton(i);
  }
  for (int i = q, j = n - 2; i--;) {
    while (j >= 0 && std::get<0>(edges[j]) >= std::get<0>(queries[i])) {
      auto [_, a, b] = edges[j--];
      // std::cerr << KV(_) << " " << KV(a) << " " << KV(b) << std::endl;
      int fa = find(a);
      int fb = find(b);
      if (fa != fb) {
        parent[fb] = fa;
        summary[fa] = summary[fa] + summary[fb];
      }
    }
    auto [_, v, id] = queries[i];
    result[id] = summary[find(v)].query(v);
    // std::cerr << KV(_) << " " << KV(v) << " " << KV(id) << std::endl;
  }
  for (int i = 0; i < q; ++i) {
    printf("%d %d\n", result[i].first, result[i].second);
  }
}