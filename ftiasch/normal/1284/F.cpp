#include <bits/stdc++.h>

const int N = 250000;

int n, depth[N], id[N], idx[N], dsu[N];
std::vector<int> path[N], t[2][N];

int dfs1(int p, int u) {
  depth[u] = ~p ? depth[p] + 1 : 0;
  int size = 1;
  std::pair<int, int> best{0, u};
  for (int v : t[0][u]) {
    if (v != p) {
      int tmp = dfs1(u, v);
      best = std::max(best, std::make_pair(tmp, id[v]));
      size += tmp;
    }
  }
  id[u] = best.second;
  idx[u] = path[id[u]].size();
  path[id[u]].push_back(u);
  for (int v : t[0][u]) {
    if (v != p && id[v] != id[u]) {
      path[id[v]].push_back(u);
    }
  }
  return size;
}

int find(int u) {
  if (dsu[u] != u) {
    dsu[u] = find(dsu[u]);
  }
  return dsu[u];
}

int bsearch(int *p, int *q, const std::function<bool(int)> &pred) {
  assert(pred(*p) != pred(*q));
  int l = 0;
  int r = q - p;
  while (l + 1 < r) {
    int m = l + r >> 1;
    if (pred(p[l]) != pred(p[m])) {
      r = m;
    } else {
      l = m;
    }
  }
  return p[l];
}

int first(int u) {
  int v = path[id[u]].back();
  return ~v ? depth[v] : -1;
}

int solve(int a, int b, const std::function<bool(int)> &pred) {
  assert(pred(a) != pred(b));
  while (true) {
    if (first(a) < first(b)) {
      std::swap(a, b);
    }
    int *p = path[id[a]].data();
    if (id[a] == id[b]) {
      if (idx[a] > idx[b]) {
        std::swap(a, b);
      }
      return bsearch(p + idx[a], p + idx[b], pred);
    } else {
      int *q = p + path[id[a]].size() - 1;
      if (pred(a) != pred(*q)) {
        return bsearch(p + idx[a], q, pred);
      }
      a = *q;
    }
  }
}

void dfs2(int p, int u) {
  for (int v : t[1][u]) {
    if (v != p) {
      dfs2(u, v);
      int uu = solve(u, v, [v](int u) -> bool { return find(u) == v; });
      int vv = path[id[uu]][idx[uu] + 1];
      if (find(vv) != v) {
        std::swap(uu, vv);
      }
      dsu[v] = uu;
      printf("%d %d %d %d\n", uu + 1, vv + 1, u + 1, v + 1);
    }
  }
}

struct FastIO {
  static const int S = 65536;
  char buf[S];
  int pos, len;
  bool eof;
  FILE *in;
  FastIO(FILE *_in = stdin) {
    in = _in;
    pos = len = 0;
    eof = false;
  }
  inline int nextChar() {
    if (pos == len) {
      pos = 0, len = fread(buf, 1, S, in);
    }
    if (pos == len) {
      eof = true;
      return -1;
    }
    return buf[pos++];
  }
  inline int nextInt() {
    int c = nextChar(), x = 0;
    while (c <= 32) {
      c = nextChar();
    }
    for (; isdigit(c); c = nextChar()) {
      x = x * 10 + c - '0';
    }
    return x;
  }
} io;

int main() {
  n = io.nextInt();
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < n - 1; ++i) {
      int a = io.nextInt() - 1;
      int b = io.nextInt() - 1;
      t[k][a].push_back(b);
      t[k][b].push_back(a);
    }
  }
  dfs1(-1, 0);
  path[id[0]].push_back(-1);
  std::iota(dsu, dsu + n, 0);
  printf("%d\n", n - 1);
  dfs2(-1, 0);
}