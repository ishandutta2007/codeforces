#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

int n, m, parent[N], path_min[N], marked_min;
bool marked[N];
std::vector<int> tree[N];

void prepare(int p, int u) {
  parent[u] = p;
  path_min[u] = ~p ? std::min(path_min[p], u) : u;
  for (int v : tree[u]) {
    if (v != p) {
      prepare(u, v);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    tree[a - 1].push_back(b - 1);
    tree[b - 1].push_back(a - 1);
  }
  int root;
  scanf("%*d%d", &root);
  root %= n;
  prepare(-1, root);
  marked_min = root;
  marked[root] = true;
  int last = 0;
  for (int _ = 1; _ < m; ++_) {
    int op, offset;
    scanf("%d%d", &op, &offset);
    int v = (last + offset) % n;
    if (op == 1) {
      while (~v && !marked[v]) {
        marked_min = std::min(marked_min, v);
        marked[v] = true;
        v = parent[v];
      }
    } else {
      last = std::min(marked_min, path_min[v]) + 1;
      printf("%d\n", last);
    }
  }
}