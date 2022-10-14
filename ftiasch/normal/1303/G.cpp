#include <bits/stdc++.h>
#include <functional>

using Long = long long;

const int N = 150000;

struct Line {
  Long at(int x) const { return k * x + b; }

  Long k, b;
} lines[N << 1];

int n, n0, a[N], resolved[N], size[N], imbalance[N];
Long result = 0;
std::vector<int> tree[N], vertices;

void prepare(int p, int u) {
  vertices.push_back(u);
  size[u] = 1, imbalance[u] = 0;
  for (int v : tree[u]) {
    if (v != p && !resolved[v]) {
      prepare(u, v);
      size[u] += size[v];
      imbalance[u] = std::max(imbalance[u], size[v]);
    }
  }
}

int get_id(int l, int r) { return l + r | l != r; }

void add(int l, int r, Line line) {
  int id = get_id(l, r);
  int m = l + r >> 1;
  if (lines[id].at(m) < line.at(m)) {
    std::swap(lines[id], line);
  }
  if (l < r) {
    if (lines[id].at(l) < line.at(l)) {
      add(l, m, line);
    } else {
      add(m + 1, r, line);
    }
  }
}

Long ask(int l, int r, int x) {
  Long result = lines[get_id(l, r)].at(x);
  if (l < r) {
    int m = l + r >> 1;
    result = std::max(result, x < m ? ask(l, m, x) : ask(m + 1, r, x));
  }
  return result;
}

void dfs1(int p, int u, int s0, Long s1, Long s2) {
  add(0, n0, Line{s1, s2});
  result = std::max(result, s2);
  for (int v : tree[u]) {
    if (v != p && !resolved[v]) {
      dfs1(u, v, s0 + 1, s1 + a[v], s2 + (s0 + 1LL) * a[v]);
    }
  }
}

void dfs2(int p, int u, int s0, Long s1, Long s2) {
  result = std::max(result, ask(0, n0, s0) + s2);
  for (int v : tree[u]) {
    if (v != p && !resolved[v]) {
      dfs2(u, v, s0 + 1, s1 + a[v], s2 + s1 + a[v]);
    }
  }
}

void divide(int root) {
  vertices.clear();
  prepare(-1, root);
  {
    std::pair<int, int> best{imbalance[root], root};
    for (int v : vertices) {
      best = std::min(best,
                      std::make_pair(std::max(imbalance[v], size[root] - size[v]), v));
    }
    root = best.second;
  }
  n0 = size[root] - 1;
  resolved[root] = true;
  memset(lines, 0, sizeof(*lines) * (n0 + 1 << 1));
  add(0, n0, Line{a[root], a[root]});
  for (int v : tree[root]) {
    if (!resolved[v]) {
      dfs2(root, v, 1, a[v], a[v]);
      dfs1(root, v, 2, a[root] + a[v], a[root] + 2 * a[v]);
    }
  }
  memset(lines, 0, sizeof(*lines) * (n0 + 1 << 1));
  add(0, n0, Line{a[root], a[root]});
  for (int i = tree[root].size(); i--;) {
    int v = tree[root][i];
    if (!resolved[v]) {
      dfs2(root, v, 1, a[v], a[v]);
      dfs1(root, v, 2, a[root] + a[v], a[root] + 2 * a[v]);
    }
  }
  for (int v : tree[root]) {
    if (!resolved[v]) {
      divide(v);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--, b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    result = std::max(result, static_cast<Long>(a[i]));
  }
  divide(0);
  std::cout << result << std::endl;
}