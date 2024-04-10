#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'0000;

int n;
long long result[N], fenwick[N];
std::vector<int> tree[N];
std::vector<std::pair<int, int>> updates[N];

void prepare(int p, int u, int d) {
  for (auto [radius, delta] : updates[u]) {
    for (int k = std::min(d + radius, n - 1); ~k; k -= ~k & k + 1) {
      fenwick[k] += delta;
    }
  }
  for (int k = d; k < n; k += ~k & k + 1) {
    result[u] += fenwick[k];
  }
  for (int v : tree[u]) {
    if (v != p) {
      prepare(u, v, d + 1);
    }
  }
  for (auto [radius, delta] : updates[u]) {
    for (int k = std::min(d + radius, n - 1); ~k; k -= ~k & k + 1) {
      fenwick[k] -= delta;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int v, d, x;
    scanf("%d%d%d", &v, &d, &x);
    updates[v - 1].emplace_back(d, x);
  }
  prepare(-1, 0, 0);
  for (int u = 0; u < n; ++u) {
    printf("%lld%c", result[u], " \n"[u + 1 == n]);
  }
}