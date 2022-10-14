#include <bits/stdc++.h>

const int N = 2000;

int n, rank[N], value[N];
std::vector<int> candidates, children[N];

int dfs(int u) {
  if (rank[u] >= candidates.size()) {
    return 0;
  }
  value[u] = candidates[rank[u]];
  candidates.erase(candidates.begin() + rank[u]);
  int size = 1;
  for (int v : children[u]) {
    int ret = dfs(v);
    if (!ret) {
      return 0;
    }
    size += ret;
  }
  if (rank[u] >= size) {
    return 0;
  }
  return size;
}

int main() {
  scanf("%d", &n);
  int root = 0;
  for (int i = 0, p; i < n; ++i) {
    scanf("%d%d", &p, rank + i);
    if (p) {
      children[p - 1].push_back(i);
    } else {
      root = i;
    }
  }
  candidates.resize(n);
  std::iota(candidates.begin(), candidates.end(), 1);
  if (dfs(root)) {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      printf("%d%c", value[i], " \n"[i == n - 1]);
    }
  } else {
    puts("NO");
  }
}