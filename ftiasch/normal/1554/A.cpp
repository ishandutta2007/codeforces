#include <bits/stdc++.h>

const int N = 100000;

int n, a[N], parent[N], maximum[N];
std::pair<int, int> o[N];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

void merge(int u, int v) {
  u = find(u);
  parent[u] = v;
  maximum[v] = std::max(maximum[v], maximum[u]);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      o[i] = {a[i], i};
    }
    std::sort(o, o + n, std::greater<std::pair<int, int>>());
    memset(parent, -1, sizeof(*parent) * n);
    long long result = 0;
    for (int _ = 0; _ < n; ++_) {
      int i = o[_].second;
      parent[i] = i;
      maximum[i] = a[i];
      bool ok = false;
      if (i && ~parent[i - 1]) {
        ok = true;
        merge(i - 1, i);
      }
      if (i + 1 < n && ~parent[i + 1]) {
        ok = true;
        merge(i + 1, i);
      }
      if (ok) {
        result = std::max(result, 1LL * a[i] * maximum[i]);
      }
    }
    std::cout << result << "\n";
  }
}