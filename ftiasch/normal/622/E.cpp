#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::vector<int>> tree(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  int result = 0;
  for (int subtree : tree[0]) {
    std::vector<int> leaf_depths;
    std::vector<std::tuple<int, int, int>> queue;
    queue.emplace_back(0, subtree, 0);
    for (int head = 0; head < queue.size(); ++head) {
      auto [pu, u, du] = queue[head];
      for (int v : tree[u]) {
        if (v != pu) {
          queue.emplace_back(u, v, du + 1);
        }
      }
      if (tree[u].size() == 1) {
        leaf_depths.push_back(du);
      }
    }
    int z = -1;
    for (int d : leaf_depths) {
        z = std::max(z + 1, d);
    }
    result = std::max(result, z + 1);
  }
  printf("%d\n", result);
}