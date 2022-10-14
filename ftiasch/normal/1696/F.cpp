#line 1 "/tmp/tmp-144689CllXD944JeAc.cpp"
#include <bits/stdc++.h>

const int N = 100;

int n, parent[N], d[N][N];
bool same[N][N][N], visited[N];
char buffer[N + 1];
std::vector<int> order;

bool find_tree(int p, int u) {
  if (visited[u]) {
    return false;
  }
  visited[u] = true;
  parent[u] = p;
  order.push_back(u);
  for (int v = 0; v < n; ++v) {
    if (v != u && v != p) {
      if (same[u][p][v]) {
        // (u, p) == (u, v)
        if (!find_tree(u, v)) {
          return false;
        }
      }
    }
  }
  return true;
}

bool check(int v0) {
  memset(visited, 0, sizeof(*visited) * n);
  visited[0] = true;
  order.clear();
  order.push_back(0);
  for (int v = 1; v < n; ++v) {
    if (same[0][v][v0]) {
      // (0, v) == (0, v0)
      if (!find_tree(0, v)) {
        return false;
      }
    }
  }
  if (order.size() < n) {
    return false;
  }
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      d[order[i]][order[j]] = d[order[j]][order[i]] =
          d[order[i]][parent[order[j]]] + 1;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((d[k][i] == d[k][j]) != same[k][i][j]) {
          return false;
        }
      }
    }
  }
  puts("Yes");
  for (int i = 1; i < n; ++i) {
    printf("%d %d\n", parent[i] + 1, i + 1);
  }
  return true;
}

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      same[k][i][i] = true;
    }
    for (int j = i + 1; j < n; ++j) {
      scanf("%s", buffer);
      for (int k = 0; k < n; ++k) {
        same[k][i][j] = same[k][j][i] = buffer[k] == '1';
      }
    }
  }
  order.reserve(n);
  for (int v0 = 1; v0 < n; ++v0) {
    // assume that the edge (0, v0) presents
    if (check(v0)) {
      return;
    }
  }
  puts("No");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
}