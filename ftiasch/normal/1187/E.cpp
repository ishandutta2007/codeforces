#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, size[N];
long long sum_of_depth, result;
std::vector<int> tree[N];

void prepare(int p, int u, int d) {
  sum_of_depth += d;
  size[u] = 1;
  for (int v : tree[u]) {
    if (v != p) {
      prepare(u, v, d + 1);
      size[u] += size[v];
    }
  }
}

void dfs(int p, int u, long long sd) {
  result = std::max(result, sd);
  for (int v : tree[u]) {
    if (v != p) {
      dfs(u, v, sd - (size[v]) + (n - size[v]));
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
  prepare(-1, 0, 0);
  dfs(-1, 0, sum_of_depth);
  printf("%lld\n", result + n);
}