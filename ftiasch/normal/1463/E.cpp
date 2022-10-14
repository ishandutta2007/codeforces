// #include "debug.h"

#include <bits/stdc++.h>

const int N = 300'000;

int n, m, p[N], nxt[N], prv[N], chain_id[N], deg[N];
std::vector<int> graph[N], queue;
std::vector<std::vector<int>> chains;

bool work() {
  memset(chain_id, -1, sizeof(int) * n);
  //   std::cout << std::vector<int>(nxt, nxt + n) << std::endl;
  for (int u = 0; u < n; ++u) {
    if (!~nxt[u]) {
      int new_chain_id = chains.size();
      std::vector<int> chain;
      for (int v = u; ~v; v = prv[v]) {
        chain_id[v] = new_chain_id;
        chain.push_back(v);
        if (~p[v] && chain_id[p[v]] == new_chain_id) {
          return false;
        }
      }
      std::reverse(chain.begin(), chain.end());
      chains.emplace_back(std::move(chain));
    }
  }
  if (std::count(chain_id, chain_id + n, -1)) {
    return false;
  }
  for (int u = 0; u < n; ++u) {
    if (~p[u]) {
      int x = chain_id[p[u]];
      int y = chain_id[u];
      if (x != y) {
        deg[y]++;
        graph[x].push_back(y);
      }
    }
  }
  for (int u = 0; u < static_cast<int>(chains.size()); ++u) {
    if (!deg[u]) {
      queue.push_back(u);
    }
  }
  for (int head = 0; head < static_cast<int>(queue.size()); ++head) {
    int u = queue[head];
    for (int v : graph[u]) {
      if (!--deg[v]) {
        queue.push_back(v);
      }
    }
  }
  return queue.size() == chains.size();
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i);
    p[i]--;
  }
  memset(nxt, -1, sizeof(int) * n);
  memset(prv, -1, sizeof(int) * n);
  for (int i = 0, x, y; i < m; ++i) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    nxt[x] = y;
    prv[y] = x;
  }
  if (work()) {
    std::vector<int> plan;
    plan.reserve(n);
    for (int c : queue) {
      for (int v : chains[c]) {
        plan.push_back(v);
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", plan[i] + 1, " \n"[i + 1 == n]);
    }
  } else {
    printf("%d\n", 0);
  }
}