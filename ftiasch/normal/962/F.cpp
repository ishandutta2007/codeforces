#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

int n, m, head[N], to[N << 1], next[N << 1], depth[N], low[N], now,
    timestamp[N];
bool used[N];
std::vector<int> edges, result;

void dfs(int u, int d) {
  depth[u] = low[u] = d;
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      int v = to[iterator];
      if (~depth[v]) {
        edges.push_back(iterator);
        low[u] = std::min(low[u], depth[v]);
      } else {
        edges.push_back(iterator);
        dfs(v, d + 1);
        if (depth[u] < low[v]) {
          edges.pop_back();
        } else if (depth[u] == low[v]) {
          now++;
          std::vector<int> cycle;
          int e;
          do {
            e = edges.back();
            edges.pop_back();
            cycle.push_back(e);
          } while (to[e ^ 1] != u);
          int vertices = 0;
          for (auto e : cycle) {
            vertices += timestamp[to[e]] != now;
            timestamp[to[e]] = now;
          }
          if (vertices == static_cast<int>(cycle.size())) {
            for (int e : cycle) {
              result.push_back((e >> 1) + 1);
            }
          }
        }
        low[u] = std::min(low[u], low[v]);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    to[i]--;
  }
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  memset(depth, -1, sizeof(depth));
  for (int u = 0; u < n; ++u) {
    if (!~depth[u]) {
      dfs(u, 0);
    }
  }
  printf("%d\n", static_cast<int>(result.size()));
  std::sort(result.begin(), result.end());
  for (size_t i = 0; i < result.size(); ++i) {
    printf("%d%c", result[i], " \n"[i + 1 == result.size()]);
  }
}