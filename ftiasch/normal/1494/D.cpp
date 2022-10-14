// #include "debug.h"

#include <bits/stdc++.h>

const int N = 500;

int n, a[N][N], k, salary[N + N], parent[N + N];

void work(int rp, const std::vector<int> &leaves) {
  // std::cerr << KV(rp) << " " << KV(leaves) << std::endl;
  if (leaves.size() == 1) {
    int u = leaves[0];
    salary[u] = a[u][u];
    parent[u] = rp;
  } else {
    int root = k++;
    int n = leaves.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        salary[root] = std::max(salary[root], a[leaves[i]][leaves[j]]);
      }
    }
    parent[root] = rp;
    std::vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        std::vector<int> group;
        for (int j = i; j < n; ++j) {
          if (!used[j] && a[leaves[i]][leaves[j]] < salary[root]) {
            used[j] = true;
            group.push_back(leaves[j]);
          }
        }
        work(root, group);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  std::vector<int> leaves(n);
  std::iota(leaves.begin(), leaves.end(), 0);
  k = n;
  work(-1, leaves);
  printf("%d\n", k);
  for (int i = 0; i < k; ++i) {
    printf("%d%c", salary[i], " \n"[i + 1 == k]);
  }
  printf("%d\n", n + 1);
//   std::cerr << "digraph {" << std::endl;
  for (int i = 0; i < k; ++i) {
    if (~parent[i]) {
      printf("%d %d\n", i + 1, parent[i] + 1);
    //   std::cerr << parent[i] << "->" << i << std::endl;
    }
  }
//   std::cerr << "}" << std::endl;
}