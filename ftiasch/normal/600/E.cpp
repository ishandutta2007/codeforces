#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

int n, c[N], size[N], prefer[N], count[N + 1], max_count, order[N], now;
long long sum, result[N];
std::vector<int> tree[N];

void prepare(int p, int u) {
  size[u] = 1;
  std::pair<int, int> best{0, u};
  for (int v : tree[u]) {
    if (v != p) {
      prepare(u, v);
      size[u] += size[v];
      best = std::max(best, {size[v], v});
    }
  }
  prefer[u] = best.second;
}

void add(int u) {
  count[c[u]]++;
  if (max_count < count[c[u]]) {
    max_count = count[c[u]];
    sum = 0;
  }
  if (max_count == count[c[u]]) {
    sum += c[u];
  }
}

void dfs(int p, int u) {
  int begin = now;
  order[now++] = u;
  for (int v : tree[u]) {
    if (v != p && v != prefer[u]) {
      int sub_begin = now;
      dfs(u, v);
      max_count = sum = 0;
      for (int i = sub_begin; i < sub_begin + size[v]; ++i) {
        count[c[order[i]]]--;
      }
    }
  }
  int end = now;
  if (prefer[u] != u) {
    dfs(u, prefer[u]);
  }
  for (int i = begin; i < end; ++i) {
    add(order[i]);
  }
  result[u] = sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", c + i);
  }
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  prepare(-1, 0);
  dfs(-1, 0);
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", result[i], " \n"[i + 1 == n]);
  }
}