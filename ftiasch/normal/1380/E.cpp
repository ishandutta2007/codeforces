#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, m, t[N], parent[N << 1], result[N];
std::array<int, 2> a[N];
std::vector<int> queries[N];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

void dfs(int u) {
  if (u >= m) {
    for (int v : a[u - m]) {
      dfs(v);
      parent[v] = u;
    }
  } else {
    for (int v : queries[u]) {
      if (parent[v] != v) {
        int w = find(v);
        assert(w >= m);
        result[w - m]++;
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", t + i);
    t[i]--;
  }
  for (int i = 0, x, y; i < m - 1; ++i) {
    scanf("%d%d", &x, &y);
    a[i] = {x - 1, y - 1};
  }
  {
    std::vector<int> r(m);
    std::iota(r.begin(), r.end(), 0);
    for (int i = 0; i < m - 1; ++i) {
      auto [x, y] = a[i];
      a[i] = {r[x], r[y]};
      r[x] = r[y] = m + i;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (t[i - 1] != t[i]) {
      queries[t[i - 1]].push_back(t[i]);
      queries[t[i]].push_back(t[i - 1]);
    }
  }
  std::iota(parent, parent + (m << 1), 0);
  dfs(m + (m - 2));
  int sum = 0;
  for (int i = m; i--;) {
    sum += result[i];
    result[i] = sum;
  }
  for (int i = 0; i < m; ++i) {
    printf("%d\n", result[i]);
  }
}