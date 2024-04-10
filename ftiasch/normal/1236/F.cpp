#include <bits/stdc++.h>

const int N = 500000;
const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int two[N + 1], n, m, top, degree[N], sum, sum2, vsum[N], head[N], to[N << 1],
    next[N << 1], depth[N], low[N], stack[N];
bool used[N];
std::vector<std::vector<int>> cycles;

void dfs(int u) {
  low[u] = depth[u];
  stack[top++] = u;
  // printf("dfs %d: ", u + 1);
  // for (int i = 0; i < top; ++ i) {
  //   printf(" %d", stack[i] + 1);
  // }
  // puts("");
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      int v = to[iterator ^ 1];
      if (~depth[v]) {
        low[u] = std::min(low[u], depth[v]);
      } else {
        depth[v] = depth[u] + 1;
        dfs(v);
        low[u] = std::min(low[u], low[v]);
        if (depth[u] == low[v]) {
          int ptop = top;
          while (stack[--top] != v) {}
          int size = ptop - top + 1;
          int *cycle = stack + top - 1;
          add(sum, two[size]);
          add(sum2, 1LL * two[size] * two[size] % MOD);
          add(vsum[u], two[size]);
          for (int i = 1; i < size; ++i) {
            add(vsum[cycle[i]], two[size]);
          }
          cycles.emplace_back(cycle, cycle + size);
          cycles.back()[0] = u;
        } else if (depth[u] + 1 == low[v]) {
          top--;
        }
      }
    }
  }
}

int main() {
  two[0] = 1;
  for (int i = 1; i <= N; ++i) {
    two[i] = two[i - 1] * static_cast<long long>(5e8 + 4) % MOD;
  }
  while (scanf("%d%d", &n, &m) == 2) {
    memset(degree, 0, sizeof(degree));
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m << 1; ++i) {
      scanf("%d", to + i);
      degree[--to[i]]++;
      next[i] = head[to[i]];
      head[to[i]] = i;
    }
    memset(used, 0, sizeof(used));
    memset(depth, -1, sizeof(depth));
    memset(vsum, 0, sizeof(vsum));
    top = sum = sum2 = depth[0] = 0;
    cycles.clear();
    dfs(0);
    int result = 0;
    // E[X] = E[V - E + C]
    add(result, 1LL * n * two[1] % MOD);       // V
    add(result, MOD - 1LL * m * two[2] % MOD); // E
    add(result, sum);                          // C
    result = MOD - 1LL * result * result % MOD;
    add(result, (1LL * n * two[1] + n * (n - 1LL) % MOD * two[2]) % MOD); // V^2
    long long aedges = 0;
    for (int i = 0; i < n; ++i) {
      aedges += degree[i] * (degree[i] - 1LL);
      // -2*V*E
      add(result, MOD - 1LL * degree[i] * two[1] % MOD);
      add(result, MOD - 1LL * (m - degree[i]) * two[2] % MOD);
    }
    add(result, (1LL * m * two[2] + 1LL * aedges * two[3] +
                 1LL * (m * (m - 1LL) - aedges) % MOD * two[4]) %
                    MOD); // E^2
    // C^2
    add(result, (sum + 1LL * sum * sum + MOD - sum2) % MOD);
    for (auto &&cycle : cycles) {
      int s = cycle.size();
      int t = two[s];
      // +2*V*C
      // add(result, 2LL * s * t % MOD);
      add(result, 1LL * (n - s) * t % MOD);
      // -2*E*C
      // add(result, MOD - 2LL * s * t % MOD);
      int aedges = -s;
      for (int v : cycle) {
        add(result, 1LL * (vsum[v] + MOD - t) * t % MOD); // C^2
        aedges += degree[v];
        // printf("%d ", v + 1);
      }
      // puts("");
      // -2*E*C
      add(result, MOD - 1LL * (aedges - s) * t % MOD);
      add(result, MOD - 1LL * (m - aedges) * t % MOD * two[1] % MOD);
    }
    printf("%d\n", result);
  }
}