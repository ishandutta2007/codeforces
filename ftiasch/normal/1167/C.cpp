#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

int n, m, parent[N], size[N];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

void merge(int a, int b) {
  if (find(a) != find(b)) {
    parent[find(a)] = find(b);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  std::iota(parent, parent + (n + m), 0);
  for (int i = 0, k; i < m; ++i) {
    scanf("%d", &k);
    for (int j = 0, member; j < k; ++j) {
      scanf("%d", &member);
      member--;
      merge(member, n + i);
    }
  }
  for (int i = 0; i < n; ++i) {
    size[find(i)]++;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", size[find(i)], " \n"[i + 1 == n]);
  }
}