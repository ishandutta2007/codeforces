#include <bits/stdc++.h>

const int N = 400000;
const int D = 20;

int n, k, r, distance[N], queue[N], dsuparent[N], depth[N], jump[N][D];
std::vector<int> tree[N];

void add_edge(int a, int b) {
  tree[a].push_back(b);
  tree[b].push_back(a);
}

int find_root(int u) {
  if (dsuparent[u] != u) {
    dsuparent[u] = find_root(dsuparent[u]);
  }
  return dsuparent[u];
}

void prepare(int p, int u) {
  depth[u] = depth[p] + 1;
  jump[u][0] = p;
  for (int i = 0; jump[u][i]; ++i) {
    jump[u][i + 1] = jump[jump[u][i]][i];
  }
  for (int v : tree[u]) {
    if (v != p) {
      prepare(u, v);
    }
  }
}

int LA(int u, int d) {
  for (int i = D; i--;) {
    if (d >> i & 1) {
      u = jump[u][i];
    }
  }
  return u;
}

int LCA(int a, int b) {
  if (depth[a] > depth[b]) {
    std::swap(a, b);
  }
  b = LA(b, depth[b] - depth[a]);
  if (a == b) {
    return a;
  }
  for (int i = D; i--;) {
    if (jump[a][i] != jump[b][i]) {
      a = jump[a][i], b = jump[b][i];
    }
  }
  return jump[a][0];
}

bool solve(int a, int b) {
  int w = LCA(a, b);
  int d = depth[a] + depth[b] - depth[w] * 2;
  if (d <= k * 2) {
    return true;
  }
  int u = depth[a] - depth[w] >= k ? LA(a, k) : LA(b, d - k);
  int v = depth[b] - depth[w] >= k ? LA(b, k) : LA(a, d - k);
  return find_root(u) == find_root(v);
}

int main() {
  scanf("%d%d%d", &n, &k, &r);
  for (int i = 1, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    add_edge(a, n + i);
    add_edge(b, n + i);
  }
  memset(distance, -1, sizeof(distance));
  std::iota(dsuparent, dsuparent + N, 0);
  int rear = r;
  for (int i = 0; i < r; ++i) {
    scanf("%d", queue + i);
    distance[queue[i]] = 0;
  }
  for (int head = 0; head < rear; ++head) {
    int u = queue[head];
    if (distance[u] < k) {
      for (int v : tree[u]) {
        if (distance[v] == -1) {
          distance[queue[rear++] = v] = distance[u] + 1;
        }
        dsuparent[find_root(u)] = find_root(v);
      }
    }
  }
  depth[0] = -1;
  prepare(0, 1);
  int q, a, b;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &a, &b);
    puts(solve(a, b) ? "YES" : "NO");
  }
}