/*
 * author:  ADMathNoob
 * created: 05/24/21 10:34:36
 * problem: https://codeforces.com/contest/1528/problem/D
 */

/*
g++ 1528D.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1528D.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> from(m), to(m), cost(m);
  vector<vector<int>> out(n);
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i] >> cost[i];
    out[from[i]].push_back(i);
  }
  for (int start = 0; start < n; start++) {
    priority_queue<pair<long long, int>> q;
    vector<long long> dist(n, INF);
    for (int id : out[start]) {
      int u = to[id];
      dist[u] = cost[id];
      q.emplace(-dist[u], u);
    }
    // dist[start] = 0;
    vector<bool> done(n, false);
    while (!q.empty()) {
      long long _;
      int v;
      tie(_, v) = q.top();
      q.pop();
      if (done[v]) {
        continue;
      }
      done[v] = true;
      for (int id : out[v]) {
        int u = (to[id] + dist[v]) % n;
        if (dist[v] + cost[id] < dist[u]) {
          dist[u] = dist[v] + cost[id];
          q.emplace(-dist[u], u);
        }
      }
      int u = (v + 1) % n;
      if (dist[v] + 1 < dist[u]) {
        dist[u] = dist[v] + 1;
        q.emplace(-dist[u], u);
      }
    }
    dist[start] = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << dist[i];
    }
    cout << '\n';
  }
  return 0;
}