#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int d[2002][2002];

vector<pair<int, int>> g[2002];

int st;

void go(int v, int par = -1, long long ds = 0) {
  if (d[st][v] != ds) {
    puts("NO");
    exit(0);
  }
  for (auto u : g[v]) {
    if (u.first != par)
      go(u.first, v, ds + u.second);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int dist[2002];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &d[i][j]);
    }
    dist[i] = d[0][i];
  }
  bool used[2002] = {0};
  used[0] = true;
  for (int i = 1; i < n; ++i) {
    int ind = -1;
    for (int j = 0; j < n; ++j) {
      if (!used[j] && (ind == -1 || dist[j] < dist[ind]))
        ind = j;
    } 
    int x;
    for (int j = 0; j < n; ++j)
      if (used[j] && d[j][ind] == dist[ind])
        x = j;
    if (dist[ind] == 0) {
      puts("NO");
      return 0;
    }
    g[x].push_back(make_pair(ind, dist[ind]));
    g[ind].push_back(make_pair(x, dist[ind]));
    used[ind] = true;
    for (int j = 0; j < n; ++j)
      dist[j] = min(dist[j], d[ind][j]);
  }
  for (int i = 0; i < n; ++i) {
    st = i;
    go(i);
  }
  puts("YES");
  return 0;
}