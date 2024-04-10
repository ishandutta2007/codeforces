// #include "debug.h"

#include <bits/stdc++.h>

const int N = 100'000;

int n, q, c[N], dfn[N], size[N], ordered_c[N], prefer[N], result[N], cnt[N],
    cntcnt[N + 1];
std::vector<int> tree[N];
std::vector<std::pair<int, int>> queries[N];

void prepare(int &&clock, int p, int u) {
  ordered_c[dfn[u] = clock++] = c[u];
  size[u] = 1;
  std::pair<int, int> candidate{0, u};
  for (int v : tree[u]) {
    if (v != p) {
      prepare(std::move(clock), u, v);
      size[u] += size[v];
      candidate = std::max(candidate, {size[v], v});
    }
  }
  prefer[u] = candidate.second;
}

void add(int c) {
  cnt[c]++;
  cntcnt[cnt[c]]++;
}

void remove(int c) {
  cntcnt[cnt[c]]--;
  cnt[c]--;
}

void work(int p, int u) {
  for (int v : tree[u]) {
    if (v != p && v != prefer[u]) {
      work(u, v);
      for (int i = dfn[v]; i < dfn[v] + size[v]; ++i) {
        remove(ordered_c[i]);
      }
    }
  }
  if (prefer[u] != u) {
    work(u, prefer[u]);
  }
  add(c[u]);
  for (int i = dfn[u] + 1; i < dfn[prefer[u]]; ++i) {
    add(ordered_c[i]);
  }
  for (int i = dfn[prefer[u]] + size[prefer[u]]; i < dfn[u] + size[u]; ++i) {
    add(ordered_c[i]);
  }
//   std::cout << KV(u) << std::vector<int>(cnt, cnt + 3) << std::endl;
  for (auto [k, id] : queries[u]) {
    result[id] = cntcnt[k];
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", c + i);
    c[i]--;
  }
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  prepare(0, -1, 0);
  for (int i = 0, u, k; i < q; ++i) {
    scanf("%d%d", &u, &k);
    queries[u - 1].emplace_back(k, i);
  }
  work(-1, 0);
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
}