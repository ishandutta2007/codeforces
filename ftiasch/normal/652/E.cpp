#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const int N = 300'000;

int n, m, head[N], to[N << 1], has_artifact[N], next[N << 1], depth[N], low[N];
bool used[N];
std::vector<int> stack;

std::pair<bool, bool> dfs(int u, int t) {
  bool has_t = u == t;
  bool ok = false;
  low[u] = depth[u];
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      stack.push_back(iterator);
      int v = to[iterator];
      if (~depth[v]) {
        low[u] = std::min(low[u], depth[v]);
      } else {
        depth[v] = depth[u] + 1;
        auto [v_has_t, v_ok] = dfs(v, t);
        has_t |= v_has_t;
        ok |= v_ok;
        if (low[v] == depth[v]) {
          stack.pop_back();
          if (v_has_t) {
            ok |= has_artifact[iterator >> 1];
          }
        }
        low[u] = std::min(low[u], low[v]);
      }
    }
  }
  if (low[u] == depth[u]) {
    while (!stack.empty() && depth[u] <= depth[to[stack.back() ^ 1]]) {
      if (has_t) {
        ok |= has_artifact[stack.back() >> 1];
      }
      stack.pop_back();
    }
  }
//   std::cout << std::boolalpha << KV(u + 1) << KV(has_t) << KV(ok) << KV(depth[u]) << KV(low[u]) << std::endl;
  return {has_t, ok};
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    to[i]--;
    if (i & 1) {
      scanf("%d", has_artifact + (i >> 1));
    }
  }
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  int s, t;
  scanf("%d%d", &s, &t);
  s--;
  t--;
  memset(depth, -1, sizeof(depth));
  depth[s] = 0;
  bool ok = dfs(s, t).second;
//   std::cout << "depth=" << std::vector<int>(depth, depth + n) << std::endl;
  puts(ok ? "YES" : "NO");
}