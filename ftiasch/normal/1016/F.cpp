#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

int n, m, forbid[N];
std::vector<std::pair<int, int>> tree[N];
long long dist[2][N];

void prepare(int t, int p, int u) {
  for (auto [v, w] : tree[u]) {
    if (v != p) {
      dist[t][v] = dist[t][u] + w;
      prepare(t, u, v);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b, c; i < n - 1; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    tree[a].emplace_back(b, c);
    tree[b].emplace_back(a, c);
  }
  memset(dist, -1, sizeof(dist));
  for (int t = 0; t < 2; ++t) {
    int u = t ? n - 1 : 0;
    dist[t][u] = 0;
    prepare(t, -1, u);
  }
  // max{min{d[0][a] + d[1][b], d[1][a] + d[0][b]}}
  // suppose d[0][a] + d[1][b] <= d[1][a] + d[0][b]
  // <=> d[0][a] - d[1][a] <= d[0][b] - d[1][b]
  std::vector<std::pair<long long, int>> order(n);
  for (int u = 0; u < n; ++u) {
    order[u] = {dist[0][u] - dist[1][u], u};
  }
  std::sort(order.begin(), order.end());
  std::set<std::pair<long long, int>> candidates;
  memset(forbid, -1, sizeof(forbid));
  long long result = 0;
  for (auto [_, b] : order) {
    for (auto [a, _] : tree[b]) {
      forbid[a] = b;
    }
    for (auto iterator = candidates.rbegin(); iterator != candidates.rend();
         ++iterator) {
      auto [_, a] = *iterator;
      if (forbid[a] != b) {
        result = std::max(result, dist[0][a] + dist[1][b]);
        break;
      }
    }
    candidates.emplace(dist[0][b], b);
  }
  while (m--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", std::min(dist[0][n - 1], result + x));
  }
}