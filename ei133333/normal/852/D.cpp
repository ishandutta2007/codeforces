#include<bits/stdc++.h>

using namespace std;

struct Bipartite_Matching
{
  vector< vector< int > > graph;
  vector< int > dist, match;
  vector< bool > used, vv;

  Bipartite_Matching(int n, int m)
  {
    graph.resize(n);
    match.assign(m, -1);
    used.assign(n, false);
  }

  void add_edge(int u, int v)
  {
    graph[u].push_back(v);
  }

  void bfs()
  {
    dist.assign(graph.size(), -1);
    queue< int > que;
    for(int i = 0; i < graph.size(); i++) {
      if(!used[i]) {
        que.emplace(i);
        dist[i] = 0;
      }
    }

    while(!que.empty()) {
      int a = que.front();
      que.pop();
      for(auto &b : graph[a]) {
        int c = match[b];
        if(c >= 0 && dist[c] == -1) {
          dist[c] = dist[a] + 1;
          que.emplace(c);
        }
      }
    }
  }

  bool dfs(int a)
  {
    vv[a] = true;
    for(auto &b : graph[a]) {
      int c = match[b];
      if(c < 0 || (!vv[c] && dist[c] == dist[a] + 1 && dfs(c))) {
        match[b] = a;
        used[a] = true;
        return (true);
      }
    }
    return (false);
  }

  int bipartite_matching()
  {
    int ret = 0;
    while(true) {
      bfs();
      vv.assign(graph.size(), false);
      int flow = 0;
      for(int i = 0; i < graph.size(); i++) {
        if(!used[i] && dfs(i)) ++flow;
      }
      if(flow == 0) return (ret);
      ret += flow;
    }
  }
};

const int INF = 1 << 29;

int main()
{
  int V, E, N, K;
  int S[200];
  int g[600][600];
  fill_n(*g, 600 * 600, INF);

  cin >> V >> E >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    --S[i];
  }

  for(int i = 0; i < V; i++) {
    g[i][i] = 0;
  }
  for(int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    c = min(g[a][b], c);
    g[a][b] = g[b][a] = c;
  }

  for(int k = 0; k < V; k++) {
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }


  const int LIM = 1731311;
  int low = 0, high = LIM;

  auto check = [&](int x)
  {
    Bipartite_Matching bp(N, V);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < V; j++) {
        if(g[S[i]][j] <= x) bp.add_edge(i, j);
      }
    }
    return (bp.bipartite_matching() >= K);
  };


  if(!check(LIM)) {
    cout << -1 << endl;
    return (0);
  }

  while(high - low > 0) {
    int mid = (low + high) >> 1;
    if(check(mid)) high = mid;
    else low = mid + 1;
  }

  cout << low << endl;
}