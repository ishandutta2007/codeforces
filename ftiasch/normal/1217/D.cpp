#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 5000;

int n, m, a[N], b[N];
bool visited[N], instk[N], cyc;
std::vector<int> graph[N];

void dfs(int u) {
  visited[u] = true;
  instk[u] = true;
  for (int v : graph[u]) {
    if (instk[v]) {
      cyc = true;
    } else if (!visited[v]) {
      dfs(v);
    }
  }
  instk[u] = false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", a + i, b + i);
    a[i]--;
    b[i]--;
    graph[a[i]].push_back(b[i]);
  }
  for (int u = 0; u < n; ++u) {
    if (!visited[u]) {
      dfs(u);
    }
  }
  if (cyc) {
    printf("%d\n", 2);
    for (int i = 0; i < m; ++i) {
      printf("%d%c", a[i] < b[i] ? 1 : 2, " \n"[i + 1 == m]);
    }
  } else {
    puts("1");
    for (int i = 0; i < m; ++i) {
      printf("1%c", " \n"[i + 1 == m]);
    }
  }
}