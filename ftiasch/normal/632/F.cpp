#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 2500;

int n, a[N][N], pmax[N][N];
std::pair<int, int> dist[N];
bool visited[N];

bool check() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] != a[j][i]) {
        return false;
      }
    }
  }
  visited[0] = true;
  for (int i = 1; i < n; ++i) {
    dist[i] = {a[0][i], 0};
  }
  for (int _ = 1; _ < n; ++_) {
    std::pair<int, int> best{INT_MAX, 0};
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        best = std::min(best, {dist[i].first, i});
      }
    }
    int v = best.second;
    int u = dist[v].second;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        pmax[i][v] = pmax[v][i] = std::max(pmax[i][u], a[u][v]);
      }
    }
    visited[v] = true;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        dist[i] = std::min(dist[i], {a[v][i], v});
      }
    }
  }
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < n; ++j) {
//       printf("%d ", pmax[i][j]);
//     }
//     puts("");
//   }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] > pmax[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  puts(check() ? "MAGIC" : "NOT MAGIC");
}