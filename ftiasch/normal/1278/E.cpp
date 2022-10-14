#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500'000;

std::vector<int> tree[N];
int b[N], e[N];

void dfs(int p, int u, int &&r) {
  int children = tree[u].size() - (p != -1);
  int current = e[u] = (r += children + 1);
  for (int v : tree[u]) {
    if (v != p) {
        b[v] = --current;
        dfs(u, v, std::move(r));
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  b[0] = 1;
  dfs(-1, 0, 1);
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", b[i], e[i]);
  }
}