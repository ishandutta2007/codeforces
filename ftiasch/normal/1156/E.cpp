#line 1 "/home/ftiasch/Documents/shoka/dsu.h"
#include <vector>

class DSU {
public:
  DSU(int n) : parent(n, -1) {}

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
#line 2 "sol.cpp"

#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> p(n + 1), q(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    q[p[i]] = i;
  }
  DSU left(n + 2), right(n + 2);
  int result = 0;
  for (int max = 1; max <= n; ++max) {
    int i = q[max];
    int l = left.find(i - 1);
    int r = right.find(i + 1);
    // (l, i - 1]
    // [i + 1, r)
    if (i - l < r - i) {
      for (int j = i - 1; j > l; --j) {
        result += i + 1 <= q[max - p[j]] && q[max - p[j]] < r;
      }
    } else {
      for (int j = i + 1; j < r; ++j) {
        result += l < q[max - p[j]] && q[max - p[j]] <= i - 1;
      }
    }
    left.merge(i, i - 1);
    right.merge(i, i + 1);
  }
  printf("%d\n", result);
}