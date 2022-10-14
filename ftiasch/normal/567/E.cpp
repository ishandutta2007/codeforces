#include <bits/stdc++.h>

using Graph = std::vector<std::vector<std::pair<int, int>>>;

const int M = 2;
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

const int N = 100000;

int a[N], b[N], l[N];
long long dis[N], rdis[N];
Hash ways[N], rways[N];

void sssp(const Graph &g, int s, long long dis[N], Hash ways[N]) {
  int n = g.size();
  for (int i = 0; i < n; ++i) {
    dis[i] = 1000000000000000000LL;
  }
  memset(ways, 0, sizeof(*ways) * n);
  dis[s] = 0;
  ways[s] = 1;
  std::priority_queue<std::pair<long long, int>> queue;
  queue.emplace(0, s);
  while (!queue.empty()) {
    auto t = queue.top();
    queue.pop();
    if (t.first == -dis[t.second]) {
      int u = t.second;
      for (const auto &iterator : g[u]) {
        int v = iterator.first;
        if (dis[u] + iterator.second < dis[v]) {
          dis[v] = dis[u] + iterator.second;
          ways[v] = 0;
          queue.emplace(-dis[v], v);
        }
        if (dis[u] + iterator.second == dis[v]) {
          ways[v] += ways[u];
        }
      }
    }
  }
}

int main() {
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  s--;
  t--;
  Graph graph(n), rgraph(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", a + i, b + i, l + i);
    a[i]--;
    b[i]--;
    graph[a[i]].push_back({b[i], l[i]});
    rgraph[b[i]].push_back({a[i], l[i]});
  }
  sssp(graph, s, dis, ways);
  sssp(rgraph, t, rdis, rways);
  for (int i = 0; i < m; ++i) {
    if (dis[a[i]] + l[i] + rdis[b[i]] == dis[t] &&
        cmp(ways[a[i]], rways[b[i]], ways[t])) {
      puts("YES");
    } else {
      long long need = dis[a[i]] + l[i] + rdis[b[i]] - dis[t] + 1;
      if (need < l[i]) {
        printf("CAN %d\n", static_cast<int>(need));
      } else {
        puts("NO");
      }
    }
  }
}