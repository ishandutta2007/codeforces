#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::vector<int>> graph(n);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::set<int> unvisits;
  for (int u = 0; u < n; ++u) {
    unvisits.insert(u);
  }
  std::vector<int> mark(n, -1), sizes, queue;
  while (!unvisits.empty()) {
    {
      queue.clear();
      queue.push_back(*unvisits.begin());
      unvisits.erase(unvisits.begin());
    }
    for (int head = 0; head < static_cast<int>(queue.size()); ++head) {
      int u = queue[head];
      for (int v : graph[u]) {
        mark[v] = u;
      }
      auto iterator = unvisits.begin();
      while (iterator != unvisits.end()) {
        auto backup = iterator;
        iterator++;
        int v = *backup;
        if (mark[v] != u) {
          unvisits.erase(backup);
          queue.push_back(v);
        }
      }
    }
    sizes.push_back(queue.size());
  }
  std::sort(sizes.begin(), sizes.end());
  printf("%d\n", static_cast<int>(sizes.size()));
  for (size_t i = 0; i < sizes.size(); ++i) {
    printf("%d%c", sizes[i], " \n"[i + 1 == sizes.size()]);
  }
}