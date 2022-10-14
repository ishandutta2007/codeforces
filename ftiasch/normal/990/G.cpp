#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, a[N], vertices[N + 1], now, timestamp[N], parent[N], size[N];
long long result[N + 1];
std::vector<std::pair<int, int>> edges[N + 1];

int find(int u) {
  if (timestamp[u] != now) {
    timestamp[u] = now;
    parent[u] = u;
    size[u] = 1;
  }
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

long long merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    return 0;
  }
  long long result = 1LL * size[a] * size[b];
  size[a] += size[b];
  parent[b] = a;
  return result;
}

int main() {
  scanf("%d", &n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    vertices[a[i]]++;
    m = std::max(m, a[i]);
  }
  for (int i = 0, x, y; i < n - 1; ++i) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    edges[std::__gcd(a[x], a[y])].emplace_back(x, y);
  }
  for (int d = m; d >= 1; --d) {
    now = d;
    for (int i = d; i <= m; i += d) {
      result[d] += vertices[i];
      for (auto [x, y] : edges[i]) {
        result[d] += merge(x, y);
      }
    }
    for (int i = d + d; i <= m; i += d) {
      result[d] -= result[i];
    }
  }
  for (int d = 1; d <= m; ++d) {
    if (result[d]) {
      printf("%d %lld\n", d, result[d]);
    }
  }
}