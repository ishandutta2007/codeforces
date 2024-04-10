#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int inf = 1000000000;
vector<int> g[3002];

void go(int n, int s, int dist[3002]) {
  for (int i = 0; i < n; ++i)
    dist[i] = inf;
  dist[s] = 0;
  vector<int> q(1, s);
  for (int i = 0; i < q.size(); ++i) {
    for (int x : g[q[i]])
      if (dist[x] == inf) {
        dist[x] = dist[q[i]] + 1;
        q.push_back(x);
      }
  }
}

int dist[3002][3002];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int s1, t1, l1;
  scanf("%d%d%d", &s1, &t1, &l1); --s1, --t1;
  int s2, t2, l2;
  scanf("%d%d%d", &s2, &t2, &l2); --s2, --t2;

  for (int i = 0; i < n; ++i)
    go(n, i, dist[i]);

  if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
    puts("-1");
    return 0;
  }

  int ans = dist[s1][t1] + dist[s2][t2];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int d = dist[i][j];
      int d1 = min(dist[s1][i] + d + dist[t1][j], dist[s1][j] + d + dist[t1][i]);
      int d2 = min(dist[s2][i] + d + dist[t2][j], dist[s2][j] + d + dist[t2][i]);
      if (d1 <= l1 && d2 <= l2)
        ans = min(ans, d1 + d2 - d);
    }
  }
  printf("%d\n", m - ans);
  return 0;
}