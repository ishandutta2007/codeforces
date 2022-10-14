#include <bits/stdc++.h>

const int N = 200001;

std::set<int> graph[N];

int get(int u) { return graph[u].empty() || *graph[u].rbegin() < u; }

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    graph[a].insert(b);
    graph[b].insert(a);
  }
  int result = 0;
  for (int i = 1; i <= n; ++i) {
    result += get(i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, a, b;
    scanf("%d", &op);
    if (op == 3) {
      printf("%d\n", result);
    } else {
      scanf("%d%d", &a, &b);
      result -= get(a) + get(b);
      if (op == 1) {
        graph[a].insert(b);
        graph[b].insert(a);
      } else {
        graph[a].erase(b);
        graph[b].erase(a);
      }
      result += get(a) + get(b);
    }
  }
}