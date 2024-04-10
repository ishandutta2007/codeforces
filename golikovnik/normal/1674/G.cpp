//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

struct SCC {
  int nc;
  vector<int> id;
  vector<vector<int>> edges;
  vector<int> sz;

  SCC(vector<vector<int>> graph) {
    int n = int(graph.size());
    vector<vector<int>> rgraph(n);
    for (int i = 0; i < n; ++i) {
      for (int j : graph[i]) {
        rgraph[j].push_back(i);
      }
    }

    vector<int> ts;
    vector<bool> used(n);

    auto dfs = [&](auto&& self, int v) -> void {
      used[v] = true;
      for (int u : graph[v]) {
        if (!used[u]) {
          self(self, u);
        }
      }
      ts.push_back(v);
    };

    for (int v = 0; v < n; ++v) {
      if (!used[v]) {
        dfs(dfs, v);
      }
    }

    reverse(ts.begin(), ts.end());
    nc = 0;
    id.resize(n, -1);

    auto dfs2 = [&](auto&& self, int v) -> void {
      id[v] = nc;
      sz.back()++;
      for (int u : rgraph[v]) {
        if (id[u] < 0) {
          self(self, u);
        }
      }
    };

    for (int v : ts) {
      if (id[v] < 0) {
        sz.push_back(0);
        dfs2(dfs2, v);
        nc++;
      }
    }

    edges.resize(nc);
    for (int v = 0; v < n; ++v) {
      for (int u : graph[v]) {
        if (id[v] != id[u]) {
          edges[id[v]].push_back(id[u]);
        }
      }
    }

    vector<int> usedEdges(nc);
    int timer = 0;
    for (int v = 0; v < nc; ++v) {
      timer++;
      for (int i = 0; i < int(edges[v].size()); ) {
        int u = edges[v][i];
        if (usedEdges[u] == timer) {
          swap(edges[v][i], edges[v].back());
          edges[v].pop_back();
        } else {
          usedEdges[u] = timer;
          ++i;
        }
      }
    }
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  vector<int> in(n), out(n);
  for (auto& [u, v] : edges) {
    cin >> u >> v;
    --u, --v;
    ++out[u];
    ++in[v];
  }
  vector<vector<int>> graph(n);
  for (auto[u, v] : edges) {
    if (in[v] == 1 || out[u] == 1) {
      continue;
    }
    graph[u].push_back(v);
  }
  auto scc = SCC(graph);
  int nc = scc.nc;
  vector<int> dp(nc);
  for (int i = nc - 1; i >= 0; --i) {
    for (int j : scc.edges[i]) {
      smax(dp[i], dp[j]);
    }
    dp[i] += scc.sz[i];
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}