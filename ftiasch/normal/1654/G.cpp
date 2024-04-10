#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> is_base(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &is_base[i]);
  }
  std::vector<std::vector<int>> tree(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  std::vector<int> height(n, -1);
  {
    std::queue<int> queue;
    for (int u = 0; u < n; ++u) {
      if (is_base[u]) {
        queue.push(u);
        height[u] = 0;
      }
    }
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      for (int v : tree[u]) {
        if (!~height[v]) {
          height[v] = height[u] + 1;
          queue.push(v);
        }
      }
    }
  }
  std::vector<std::vector<int>> group(n);
  for (int u = 0; u < n; ++u) {
    bool is_flippable = false;
    for (int v : tree[u]) {
      is_flippable |= height[u] == height[v];
    }
    if (is_flippable) {
      group[height[u]].push_back(u);
    }
  }
  std::vector<int> min_waste(height);
  for (int fh = 0; fh < n; ++fh) {
    if (!group[fh].empty()) {
      std::vector<int> extra(n, -1);
      std::vector<int> queue;
      for (int s : group[fh]) {
        extra[s] = 0;
        queue.push_back(s);
      }
      // for (int i = 1; i < queue[0].size(); ++i) {
      //   assert(extra[queue[0][i - 1]] <= extra[queue[0][i]]);
      // }
      for (int head = 0; head < queue.size(); ++head) {
        int u = queue[head];
        for (int v : tree[u]) {
          if (height[v] >= height[u]) {
            int ne = height[v] == height[u] ? extra[u] + 1
                                            : std::max(extra[u] - 1, 0);
            if (!~extra[v] || ne < extra[v]) {
              extra[v] = ne;
              queue.push_back(v);
            }
          }
        }
      }
      // std::cout << KV(fh) << group[fh] << KV(extra) << std::endl;
      for (int u = 0; u < n; ++u) {
        if (extra[u] == 0) {
          min_waste[u] = std::min(min_waste[u], fh);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", (height[i] << 1) - min_waste[i], " \n"[i + 1 == n]);
  }
}