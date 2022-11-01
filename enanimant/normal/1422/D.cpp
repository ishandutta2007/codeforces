// October 4, 2020
//

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1422D.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1422D.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int sz, n;
  cin >> sz >> n;
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  vector<vector<pair<int, int>>> g(n + 2);
  g[n].emplace_back(n + 1, abs(tx - sx) + abs(ty - sy));
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    g[n].emplace_back(i, min(abs(x[i] - sx), abs(y[i] - sy)));
    g[i].emplace_back(n + 1, abs(tx - x[i]) + abs(ty - y[i]));
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  for (int rot = 0; rot < 2; rot++) {
    sort(order.begin(), order.end(), [&](int i, int j) { return x[i] < x[j]; });
    for (int z = 0; z < n - 1; z++) {
      int i = order[z];
      int j = order[z + 1];
      g[i].emplace_back(j, x[j] - x[i]);
      g[j].emplace_back(i, x[j] - x[i]);
    }
    swap(x, y);
  }
  priority_queue<pair<int, int>> q;
  vector<int> dist(n + 2, (int) 2e9);
  dist[n] = 0;
  q.emplace(0, n);
  while (!q.empty()) {
    auto pr = q.top();
    q.pop();
    int expected = -pr.first;
    int v = pr.second;
    if (dist[v] != expected) {
      continue;
    }
    for (const auto& pr : g[v]) {
      int to = pr.first;
      int cost = pr.second;
      if (dist[v] + cost < dist[to]) {
        dist[to] = dist[v] + cost;
        q.emplace(-dist[to], to);
      }
    }
  }
  cout << dist[n + 1] << '\n';


  return 0;
}