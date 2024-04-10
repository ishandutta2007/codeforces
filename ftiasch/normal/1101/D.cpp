#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'001;

int n, a[N], result, mark[N], visited[N], queue[N], dist_clock;
bool is_prime[N];
std::vector<int> buckets[N], tree[N];
std::pair<int, int> dist[N];

std::pair<int, int> bfs(int p, int source) {
  dist_clock++;
  int head = 0;
  int rear = 0;
  queue[rear++] = source;
  dist[source] = {1, dist_clock};
  std::pair<int, int> result{0, -1};
  while (head < rear) {
    int u = queue[head++];
    visited[u] = p;
    result = std::max(result, {dist[u].first, u});
    for (int v : tree[u]) {
      if (mark[v] == p) {
        if (dist[v].second != dist_clock) {
          dist[v] = {dist[u].first + 1, dist_clock};
          queue[rear++] = v;
        }
      }
    }
  }
  return result;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    buckets[a[i]].push_back(i);
  }
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  memset(is_prime, true, sizeof(is_prime));
  for (int p = 2; p < N; ++p) {
    if (is_prime[p]) {
      for (int d = p; d < N; d += p) {
        for (int v : buckets[d]) {
          mark[v] = p;
        }
      }
      for (int d = p; d < N; d += p) {
        for (int v : buckets[d]) {
            if (visited[v] != p) {
                int vv = bfs(p, v).second;
                result = std::max(result, bfs(p, vv).first);
            }
        }
      }
      for (int d = p + p; d < N; d += p) {
        is_prime[d] = false;
      }
    }
  }
  printf("%d\n", result);
}