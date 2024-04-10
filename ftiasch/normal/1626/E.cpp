#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

int n, parent[N], size[N];
bool ok[N];
std::vector<int> blacks, tree[N];

void prepare(int u) {
  size[u] = ok[u];
  for (int v : tree[u]) {
    if (v != parent[u]) {
      parent[v] = u;
      prepare(v);
      size[u] += size[v];
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int u = 0, c; u < n; ++u) {
    scanf("%d", &c);
    if (c) {
      ok[u] = true;
      blacks.push_back(u);
    }
  }
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  parent[0] = -1;
  prepare(0);
  for (int u : blacks) {
    for (int v : tree[u]) {
      ok[v] = true;
    }
  }
  std::queue<int> queue;
  for (int u = 0; u < n; ++u) {
    if (ok[u]) {
      queue.push(u);
    }
  }
  auto add = [&](int u) {
    if (!ok[u]) {
      ok[u] = true;
      queue.push(u);
    }
  };
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();
    if (~parent[u] && size[u] >= 2) {
      add(parent[u]);
    }
    for (int v : tree[u]) {
      if (v != parent[u] && static_cast<int>(blacks.size()) - size[v] >= 2) {
        add(v);
      }
    }
  }
  for (int u = 0; u < n; ++u) {
    printf("%d%c", ok[u], " \n"[u + 1 == n]);
  }
}