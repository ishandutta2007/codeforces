#include <bits/stdc++.h>

const int N = 100001;

int n, depth[N], path[N], head[N];
std::vector<int> tree[N];

int prepare(int p, int u) {
  depth[u] = depth[p] + 1;
  int size = 1;
  std::pair<int, int> best{0, u};
  for (int v : tree[u]) {
    if (v != p) {
      int subsize = prepare(u, v);
      size += subsize;
      best = std::max(best, std::make_pair(subsize, path[v]));
    }
  }
  head[path[u] = best.second] = p;
  return size;
}

int LCA(int a, int b) {
  while (path[a] != path[b]) {
    int &x = depth[head[path[a]]] > depth[head[path[b]]] ? a : b;
    x = head[path[x]];
  }
  return depth[a] < depth[b] ? a : b;
}

int dist(int a, int b) { return depth[a] + depth[b] - 2 * depth[LCA(a, b)]; }

int test(int d, int k) { return d <= k && (k - d) % 2 == 0; }

int main() {
  scanf("%d", &n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  prepare(0, 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y, a, b, k;
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
    puts(test(dist(a, b), k) || test(dist(a, x) + 1 + dist(y, b), k) ||
                 test(dist(a, y) + 1 + dist(x, b), k)
             ? "YES"
             : "NO");
  }
}