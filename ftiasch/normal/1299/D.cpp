#include <bits/stdc++.h>

using State = uint32_t;

const int M = 32;
const int S = 375;

std::vector<State> states;
int add_one[S][M], combine[S][S];

State add(State s, int x) {
  int ns = s | 1U << x;
  for (int y = 0; y < M; ++y) {
    if (s >> y & 1) {
      ns |= 1U << (x ^ y);
    }
  }
  return ns;
}

int get_id(State s) {
  return std::find(states.begin(), states.end(), s) - states.begin();
}

void generate(State s) {
  if (get_id(s) == static_cast<int>(states.size())) {
    states.push_back(s);
    for (int i = 0; i < M; ++i) {
      generate(add(s, i));
    }
  }
}

const int N = 100000;
const int MOD = 1e9 + 7;

void update(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, m, parent[N], now, timestamp[N], depth[N], sum[N], dp[2][S];
std::vector<std::pair<int, int>> graph[N];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

void dfs(int &s, int p, int u, int x) {
  timestamp[u] = now, depth[u] = depth[p] + 1, sum[u] = x;
  for (auto &&iterator : graph[u]) {
    int v = iterator.first;
    int w = iterator.second;
    if (v != p) {
      if (timestamp[v] == now) {
        if (depth[v] < depth[u]) {
          s = add_one[s][sum[v] ^ x ^ w];
        }
      } else {
        dfs(s, u, v, x ^ w);
      }
    }
  }
}

int main() {
  states.push_back(0);
  generate(1);
  for (int i = 0; i < S; ++i) {
    for (int j = 0; j < S; ++j) {
      auto s = states[i];
      if (i && j && (s & states[j]) == 1) {
        for (int y = 0; y < M; ++y) {
          if (states[j] >> y & 1) {
            s = add(s, y);
          }
        }
        combine[i][j] = get_id(s);
      } else {
        combine[i][j] = 0;
      }
    }
    add_one[i][0] = 0;
    for (int j = 1; j < M; ++j) {
      add_one[i][j] = combine[i][get_id(1U << j | 1)];
    }
  }

  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++i) {
      graph[i].clear();
      parent[i] = i;
    }
    for (int i = 0, a, b, c; i < m; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      a--, b--;
      if (a > b) {
        std::swap(a, b);
      }
      graph[a].emplace_back(b, c);
      if (a) {
        graph[b].emplace_back(a, c);
        if (find(a) != find(b)) {
          parent[find(a)] = find(b);
        }
      }
    }
    std::map<int, std::vector<std::pair<int, int>>> outedges;
    for (auto v : graph[0]) {
      outedges[find(v.first)].push_back(v);
    }
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    int row = 0;
    for (auto &&iterator : outedges) {
      row ^= 1;
      memcpy(dp[row], dp[row ^ 1], sizeof(dp[row]));
      auto &&vs = iterator.second;
      int v0 = vs.size();
      for (int i = 0; i < v0; ++i) {
        now++;
        int s = 1;
        dfs(s, 0, vs[i].first, vs[i].second);
        for (int i = 0; i < S; ++i) {
          update(dp[row][combine[i][s]], dp[row ^ 1][i]);
        }
        if (i == 0 && v0 == 2) {
          int v = vs[1].first;
          int w = vs[1].second;
          s = add_one[s][sum[v] ^ w];
          for (int i = 0; i < S; ++i) {
            update(dp[row][combine[i][s]], dp[row ^ 1][i]);
          }
        }
      }
    }
    int result = 0;
    for (int s = 1; s < S; ++s) {
      update(result, dp[row][s]);
    }
    printf("%d\n", result);
  }
}