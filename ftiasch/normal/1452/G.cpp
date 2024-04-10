#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const int N = 200'000;

int n, d[N], size[N], imbalance[N], timestamp[N], result[N];
bool divided[N];
std::vector<int> tree[N], vertices;
std::vector<std::pair<int, int>> dlist[N], ancestors[N];

void prepare(int p, int u) {
  vertices.push_back(u);
  size[u] = 1;
  imbalance[u] = 0;
  for (int v : tree[u]) {
    if (v != p && !divided[v]) {
      prepare(u, v);
      size[u] += size[v];
      imbalance[u] = std::max(imbalance[u], size[v]);
    }
  }
}

void divide(int root) {
  vertices.clear();
  prepare(-1, root);
  {
    std::pair<int, int> candidate{imbalance[root], root};
    for (int v : vertices) {
      candidate = std::min(candidate,
                           {std::max(imbalance[v], size[root] - size[v]), v});
    }
    root = candidate.second;
  }
  auto &queue = dlist[root];
  timestamp[root] = root;
  queue.emplace_back(root, 0);
  ancestors[root].emplace_back(root, 0);
  for (int head = 0; head < static_cast<int>(queue.size()); ++head) {
    auto [u, du] = queue[head];
    for (int v : tree[u]) {
      if (!divided[v] && timestamp[v] != root) {
        timestamp[v] = root;
        queue.emplace_back(v, du + 1);
        ancestors[v].emplace_back(root, du + 1);
      }
    }
  }
  std::reverse(queue.begin(), queue.end());
  divided[root] = true;
  for (int v : tree[root]) {
    if (!divided[v]) {
      divide(v);
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
  memset(d, -1, sizeof(*d) * n);
  std::vector<int> queue;
  queue.reserve(n);
  {
    int m;
    scanf("%d", &m);
    while (m--) {
      int v;
      scanf("%d", &v);
      v--;
      d[v] = 0;
      queue.push_back(v);
    }
  }
  for (int head = 0; head < static_cast<int>(queue.size()); ++head) {
    int u = queue[head];
    for (int v : tree[u]) {
      if (!~d[v]) {
        d[v] = d[u] + 1;
        queue.push_back(v);
      }
    }
  }
  vertices.reserve(n);
  memset(timestamp, -1, sizeof(*timestamp) * n);
  divide(0);
  assert(static_cast<int>(queue.size()) == n);
  for (int i = n; i--;) {
    int u = queue[i];
    for (auto [a, da] : ancestors[u]) {
      auto &list = dlist[a];
      while (!list.empty() && da + list.back().second < d[u]) {
        int v = list.back().first;
        result[v] = std::max(result[v], d[u]);
        list.pop_back();
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", result[i], " \n"[i + 1 == n]);
  }
}