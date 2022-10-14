// #include "debug.h"

#include <bits/stdc++.h>

const int N = 100'000;

int n, maxl, maxw, size[N], imbalance[N];
bool divided[N];
std::vector<int> vertices;
std::vector<std::pair<int, int>> tree[N];

void prepare(int p, int u) {
  vertices.push_back(u);
  size[u] = 1;
  imbalance[u] = 0;
  for (auto [v, _] : tree[u]) {
    if (v != p && !divided[v]) {
      prepare(u, v);
      size[u] += size[v];
      imbalance[u] = std::max(imbalance[u], size[v]);
    }
  }
}

using Lst = std::vector<std::pair<int, int>>;

void dfs(Lst &lst, int p, int u, int suml, int sumw) {
  lst.emplace_back(sumw, suml);
  for (auto [v, w] : tree[u]) {
    if (v != p && !divided[v]) {
      dfs(lst, u, v, suml + 1, sumw + w);
    }
  }
}

int fenwick[N];

long long count(Lst &lst) {
  std::sort(lst.begin(), lst.end());
  int m = 0;
  for (auto &&p : lst) {
    m = std::max(m, p.second);
  }
  memset(fenwick, 0, sizeof(int) * (m + 1));
  long long result = 0;
  int n = lst.size();
  for (int i = n, j = 0; i--;) {
    while (j < n && lst[j].first + lst[i].first <= maxw) {
      for (int k = lst[j].second; k <= m; k += ~k & k + 1) {
        fenwick[k]++;
      }
      j++;
    }
    for (int k = std::min(maxl - lst[i].second, m); k >= 0; k -= ~k & k + 1) {
      result += fenwick[k];
    }
  }
  //   std::cout << KV(maxl) << KV(maxw) << KV(lst) << KV(result) << std::endl;
  return result;
}

long long result = 0;

void divide(int root) {
  vertices.clear();
  prepare(-1, root);
  std::pair<int, int> candidate{imbalance[root], root};
  for (int u : vertices) {
    candidate =
        std::min(candidate, {std::max(imbalance[u], size[root] - size[u]), u});
  }
  root = candidate.second;
  divided[root] = true;
  Lst glb{{0, 0}};
  for (auto [v, w] : tree[root]) {
    if (!divided[v]) {
      Lst lst;
      dfs(lst, root, v, 1, w);
      result -= count(lst);
      for (auto &&p : lst) {
        glb.push_back(p);
      }
    }
  }
  result += count(glb);
  for (auto [v, w] : tree[root]) {
    if (!divided[v]) {
      divide(v);
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &maxl, &maxw);
  for (int i = 1, p, w; i < n; ++i) {
    scanf("%d%d", &p, &w);
    p--;
    tree[p].emplace_back(i, w);
    tree[i].emplace_back(p, w);
  }
  divide(0);
  std::cout << ((result - n) >> 1) << std::endl;
}