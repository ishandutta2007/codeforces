#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int N = 300'000;

struct Stat {
  Stat(int c = 0) : sum(c), maxpf(c), maxsf(c) {}

  Long sum, maxpf, maxsf;
};

int n, a, d[N], c[N], parent[N];
Stat stat[N];

int find(int u) {
  if (u != parent[u]) {
    u = find(parent[u]);
  }
  return parent[u];
}

int main() {
  scanf("%d%d", &n, &a);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", d + i, c + i);
    c[i] = a - c[i];
  }
  Long result = std::max(*std::max_element(c, c + n), 0);
  std::vector<std::pair<int, int>> order(n - 1);
  for (int i = 0; i + 1 < n; ++i) {
    order[i] = {d[i + 1] - d[i], i};
  }
  std::sort(order.begin(), order.end());
  std::iota(parent, parent + n, 0);
  for (int i = 0; i < n; ++i) {
    stat[i] = Stat{c[i]};
  }
  for (auto [diff, i] : order) {
    int u = find(i);
    int v = find(i + 1);
    result =
        std::max(result, stat[u].maxsf + stat[v].maxpf - 1LL * diff * diff);
    stat[u].maxpf = std::max(stat[u].maxpf, stat[u].sum + stat[v].maxpf);
    stat[u].maxsf = std::max(stat[u].maxsf + stat[v].sum, stat[v].maxsf);
    stat[u].sum += stat[v].sum;
    parent[v] = u;
  }
  printf("%lld\n", result);
}