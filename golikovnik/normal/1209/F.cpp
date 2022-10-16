#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  auto n_start = n;

  int const MOD = (int) 1e9 + 7;
  auto sum = [&](int x, int y) {
    x += y;
    if (x >= MOD) {
      x -= MOD;
    }
    return x;
  };
  auto prod = [&](i64 x, int y) -> int {
    return (int) (x * y % MOD);
  };
  vector<vector<vector<int>>> graph(n, vector<vector<int>>(10));
  auto create_node = [&] {
    auto i = (int) graph.size();
    graph.emplace_back(vector<vector<int>>(10));
    return i;
  };
  for (int ei = 0; ei < m; ++ei) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    string e = to_string(ei + 1);
    int len = (int) e.size();
    for (auto[st, fi] : vector<pair<int, int>>{{u, v}, {v, u}}) {
      int from = st;
      for (int i = 0; i < len; ++i) {
        int id = e[i] - '0';
        int to = i + 1 == len ? fi : create_node();
        graph[from][id].push_back(to);
        from = to;
      }
    }
  }
  n = (int) graph.size();
  vector<int> dist(n, -1);
  queue<vector<int>> q;
  q.push({0});
  dist[0] = 0;
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    for (int d = 0; d < 10; ++d) {
      vector<int> nxt;
      for (int who : v) {
        for (int to : graph[who][d]) {
          if (dist[to] >= 0) {
            continue;
          }
          dist[to] = sum(prod(dist[who], 10), d);
          nxt.push_back(to);
        }
      }
      if (!nxt.empty()) {
        q.push(nxt);
      }
    }
  }
  for (int i = 1; i < n_start; ++i) {
    cout << dist[i] << '\n';
  }
  return 0;
}