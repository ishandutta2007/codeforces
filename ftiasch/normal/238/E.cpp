#include <bits/stdc++.h>

const int N = 100;
const int M = 2;
const int INF = 1e9;
const int MODS[M] = {1000000007, 1000000009};

struct Hash {
  Hash(int v = 0) {
    for (size_t i = 0; i < M; ++i) {
      rs[i] = v % MODS[i];
    }
  }

  Hash &operator+=(const Hash &o) {
    for (size_t i = 0; i < M; ++i) {
      rs[i] += o.rs[i];
      if (rs[i] >= MODS[i]) {
        rs[i] -= MODS[i];
      }
    }
    return *this;
  }

  int rs[sizeof(MODS)];
};

bool cmp(const Hash &a, const Hash &b, const Hash &c) {
  for (size_t i = 0; i < M; ++i) {
    if (1LL * a.rs[i] * b.rs[i] % MODS[i] != c.rs[i]) {
      return false;
    }
  }
  return true;
}

int n, m, dist[N][N], s[N], t[N], deg[N][N], dp[N][N];
bool graph[N][N], on[N][N], must[N][N], visited[N][N];
Hash ways[N][N];

void sssp(int s, int dist[N], Hash ways[N]) {
  for (int i = 0; i < n; ++i) {
    dist[i] = INF;
  }
  memset(ways, 0, sizeof(*ways) * n);
  dist[s] = 0;
  ways[s] = 1;
  std::priority_queue<std::pair<long long, int>> queue;
  queue.emplace(0, s);
  while (!queue.empty()) {
    auto t = queue.top();
    queue.pop();
    if (t.first == -dist[t.second]) {
      int u = t.second;
      for (int v = 0; v < n; ++v) {
        if (graph[u][v]) {
          if (dist[u] + 1 < dist[v]) {
            dist[v] = dist[u] + 1;
            ways[v] = 0;
            queue.emplace(-dist[v], v);
          }
          if (dist[u] + 1 == dist[v]) {
            ways[v] += ways[u];
          }
        }
      }
    }
  }
}

int main() {
  int src, dst;
  scanf("%d%d%d%d", &n, &m, &src, &dst);
  src--, dst--;
  for (int i = 0, u, v; i < m; ++i) {
    scanf("%d%d", &u, &v);
    u--, v--;
    graph[u][v] = true;
  }
  for (int s = 0; s < n; ++s) {
    sssp(s, dist[s], ways[s]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    for (int v = 0; v < n; ++v) {
      dp[i][v] = INF;
    }
  }
  std::deque<std::pair<int, int>> queue;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", s + i, t + i);
    s[i]--, t[i]--;
    if (dist[s[i]][t[i]] < INF) {
      for (int v = 0; v < n; ++v) {
        on[i][v] = dist[s[i]][v] + dist[v][t[i]] == dist[s[i]][t[i]];
        must[i][v] =
            on[i][v] && cmp(ways[s[i]][v], ways[v][t[i]], ways[s[i]][t[i]]);
      }
      for (int u = 0; u < n; ++u) {
        if (on[i][u]) {
          for (int v = 0; v < n; ++v) {
            deg[i][u] += graph[u][v] && dist[s[i]][u] + 1 + dist[v][t[i]] == dist[s[i]][t[i]];
          }
        }
      }
      if (must[i][dst]) {
        dp[i][dst] = 1;
        queue.emplace_back(i, dst);
      }
    }
  }
  while (!queue.empty()) {
    auto i = queue.front().first;
    auto v = queue.front().second;
    queue.pop_front();
    if (visited[i][v]) {
      continue;
    }
    visited[i][v] = true;
    if (must[i][v]) {
      for (int j = 0; j < m; ++j) {
        if (on[j][v] && dp[j][v] > dp[i][v] + 1) {
          dp[j][v] = dp[i][v] + 1;
          queue.emplace_back(j, v);
        }
      }
    }
    for (int u = 0; u < n; ++u) {
      if (graph[u][v] &&
          dist[s[i]][u] + 1 + dist[v][t[i]] == dist[s[i]][t[i]]) {
        deg[i][u]--;
        if (deg[i][u] == 0 && dp[i][u] > dp[i][v]) {
          dp[i][u] = dp[i][v];
          queue.emplace_front(i, u);
        }
      }
    }
  }
  int result = INF;
  for (int i = 0; i < m; ++i) {
    if (must[i][src]) {
      result = std::min(result, dp[i][src]);
    }
  }
  printf("%d\n", result < INF ? result : -1);
}