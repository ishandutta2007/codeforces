// July 24, 2019
// https://codeforces.com/contest/1196/problem/F

/*

*/


#include <bits/stdc++.h>

using namespace std;


struct Edge {
  int from;
  int to;
  int cost;
};


class Undigraph {
public:
  int n;
  vector< vector<int> > g;
  vector<Edge> edges;

  Undigraph(int _n) : n(_n) {
    g.resize(n);
  }

  void add(int from, int to, int cost) {
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
  }
};


const long long INF = 1e18;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, m, k;
  cin >> n >> m >> k;
  vector<Edge> edges;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edges.push_back({u, v, w});
  }
  sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
    return a.cost < b.cost;
  });
  Undigraph g(n);
  for (int i = 0; i < min(k, (int) edges.size()); i++) {
    const Edge &e = edges[i];
    g.add(e.from, e.to, e.cost);
  }
  vector<long long> dists;
  unordered_map<int, long long> dist;
  for (int i = 0; i < n; i++) {
    dist.clear();
    priority_queue< pair<long long, int> > q;
    dist[i] = 0;
    q.push({0, i});
    while (!q.empty()) {
      long long expected;
      int v;
      tie(expected, v) = q.top();
      q.pop();
      expected = -expected;
      if (expected != dist[v]) {
        continue;
      }
      for (int id : g.g[v]) {
        const auto &e = g.edges[id];
        int to = e.from ^ e.to ^ v;
        if (!dist.count(to) || dist[v] + e.cost < dist[to]) {
          dist[to] = dist[v] + e.cost;
          q.push({-dist[to], to});
        }
      }
    }
    for (const auto &p : dist) {
      if (p.second != 0) {
        dists.push_back(p.second);
      }
    }
  }
  sort(dists.begin(), dists.end());
  cout << dists[2 * (k - 1)] << '\n';


  return 0;
}