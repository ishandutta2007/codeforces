#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int M = 32768;

int dist[M];
std::vector<int> graph[M];

int main() {
  for (int i = 0; i < M; ++i) {
    graph[(i + 1) % M].push_back(i);
    graph[(i * 2) % M].push_back(i);
  }
  memset(dist, -1, sizeof(dist));
  std::queue<int> queue;
  dist[0] = 0;
  queue.emplace(0);
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();
    for (int v : graph[u]) {
      if (!~dist[v]) {
        dist[v] = dist[u] + 1;
        queue.push(v);
      }
    }
  }
  int T;
  scanf("%d", &T);
  for (int i = 0, a; i < T; ++i) {
    scanf("%d", &a);
    printf("%d%c", dist[a], " \n"[i + 1 == T]);
  }
}