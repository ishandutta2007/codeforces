#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

class UnionFindSet {
public:
  UnionFindSet(int n) : parent(n, -1) {}

  int find(int u) {
    if (!~parent[u]) {
      return u;
    }
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  bool merge(int a, int b) {
    if (find(a) == find(b)) {
      return false;
    }
    parent[find(a)] = find(b);
    return true;
  }

private:
  std::vector<int> parent;
};

using UFS = UnionFindSet;

int main() {
  int n, m;
  while (scanf("%d%d", &m, &n) == 2) {
    UFS ufs(n + 1);
    int ways = 1;
    std::vector<int> solution;
    for (int i = 0; i < m; ++i) {
      int k, x, y = 0;
      scanf("%d%d", &k, &x);
      if (k == 2) {
        scanf("%d", &y);
      }
      if (ufs.merge(x, y)) {
        ways = 2 * ways % MOD;
        solution.push_back(i + 1);
      }
    }
    printf("%d %d\n", ways, static_cast<int>(solution.size()));
    for (int i = 0; i < static_cast<int>(solution.size()); ++i) {
      printf("%d%c", solution[i],
             " \n"[i + 1 == static_cast<int>(solution.size())]);
    }
  }
}