#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Edge = std::pair<int, int>;

const int N = 100'000;

int get_id(int l, int r) { return l + r | (l != r); }

int n, m, parent[N], size[N], diff[N];
std::vector<Edge> tree[N << 1];

void insert(int l, int r, int a, int b, const Edge &e) {
  if (b < l || r < a) {
    return;
  }
  if (a <= l && r <= b) {
    tree[get_id(l, r)].push_back(e);
  } else {
    int m = (l + r) >> 1;
    insert(l, m, a, b, e);
    insert(m + 1, r, a, b, e);
  }
}

std::pair<int, int> find(int u) {
  int d = 0;
  while (u != parent[u]) {
    d ^= diff[u];
    u = parent[u];
  }
  return {u, d};
}

std::vector<int> history;

int merge(int x, int y) {
  auto [rx, dx] = find(x);
  auto [ry, dy] = find(y);
  if (rx == ry) {
    return dx ^ dy;
  } else {
    if (size[rx] < size[ry]) {
      std::swap(rx, ry);
    }
    history.push_back(ry);
    parent[ry] = rx;
    size[rx] += size[ry];
    diff[ry] = dx ^ dy ^ 1;
    return 1;
  }
}

void solve(int l, int r, bool ok) {
  int checkpoint = history.size();
  for (auto [x, y] : tree[get_id(l, r)]) {
    ok &= merge(x, y) == 1;
  }
  if (l == r) {
    puts(ok ? "YES" : "NO");
  } else {
    int m = (l + r) >> 1;
    solve(l, m, ok);
    solve(m + 1, r, ok);
  }
  while (history.size() > checkpoint) {
    int y = history.back();
    history.pop_back();
    int x = parent[y];
    size[x] -= size[y];
    parent[y] = y;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  std::map<Edge, int> edges;
  for (int i = 0, x, y; i < m; ++i) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    Edge e{x, y};
    auto [iterator, emplaced] = edges.emplace(e, i);
    if (!emplaced) {
      insert(0, m - 1, iterator->second, i - 1, e);
      edges.erase(iterator);
    }
  }
  for (auto [e, i] : edges) {
    insert(0, m - 1, i, m - 1, e);
  }
  std::iota(parent, parent + n, 0);
  std::fill(size, size + n, 1);
  solve(0, m - 1, true);
}