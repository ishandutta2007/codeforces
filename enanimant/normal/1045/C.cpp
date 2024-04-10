/*
 * author:  ADMathNoob
 * created: 02/25/21 11:19:50
 * problem: https://codeforces.com/contest/1045/problem/C
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1045C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1045C.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1045C.cpp && a


*/

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int M = 500005;

const int N2 = 2 * N;
const int H = 18;

int n, m, tt;
vector<int> g[N];
int from[M], to[M];

int pv[N];
vector<int> order;
int depth[N];
int min_depth[N];

int node_comp[N];
int edge_comp[M];

void Dfs(int v, int p) {
  pv[v] = p;
  order.push_back(v);
  min_depth[v] = depth[v];
  for (int id : g[v]) {
    int u = from[id] ^ to[id] ^ v;
    if (u == p) {
      continue;
    }
    if (depth[u] != -1) {
      min_depth[v] = min(min_depth[v], depth[u]);
      continue;
    }
    depth[u] = depth[v] + 1;
    Dfs(u, v);
    min_depth[v] = min(min_depth[v], min_depth[u]);
  }
}

int n2;
vector<int> g2[N2];
int pv2[N2];
int depth2[N2];

int pr[N2][H];

void Dfs2(int v, int p) {
  pv2[v] = p;
  for (int u : g2[v]) {
    if (u == p) {
      continue;
    }
    pv2[u] = pv2[v];
    depth2[u] = depth2[v] + 1;
    Dfs2(u, v);
  }
}

int Lca(int x, int y) {
  if (depth2[x] < depth2[y]) {
    swap(x, y);
  }
  for (int j = H - 1; j >= 0; j--) {
    if (pr[x][j] != -1 && depth2[pr[x][j]] >= depth2[y]) {
      x = pr[x][j];
    }
  }
  if (x == y) {
    return x;
  }
  for (int j = H - 1; j >= 0; j--) {
    if (pr[x][j] != pr[y][j]) {
      x = pr[x][j];
      y = pr[y][j];
    }
  }
  return pv2[x];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  cin >> n >> m >> tt;
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i];
    --from[i];
    --to[i];
    g[from[i]].push_back(i);
    g[to[i]].push_back(i);
  }
  fill(depth, depth + n, -1);
  depth[0] = 0;
  Dfs(0, -1);

  int cnt = 0;
  for (int i : order) {
    if (pv[i] == -1) {
      // node_comp[i] = -1;
      continue;
    }
    if (min_depth[i] >= depth[pv[i]]) {
      node_comp[i] = cnt++;
    } else {
      node_comp[i] = node_comp[pv[i]];
    }
  }
  for (int id = 0; id < m; id++) {
    int v = (depth[from[id]] > depth[to[id]] ? from[id] : to[id]);
    edge_comp[id] = node_comp[v];
    // cerr << from[id] + 1 << ' ' << to[id] + 1 << ' ' << edge_comp[id] << '\n';
  }

  n2 = n + cnt;
  vector<pair<int, int>> edges;
  for (int id = 0; id < m; id++) {
    int x = n + edge_comp[id];
    edges.emplace_back(from[id], x);
    edges.emplace_back(to[id], x);
  }
  sort(edges.begin(), edges.end());
  edges.resize(unique(edges.begin(), edges.end()) - edges.begin());
  assert((int) edges.size() == n2 - 1);
  for (const auto& e : edges) {
    // cerr << e.first << ' ' << e.second << '\n';
    g2[e.first].push_back(e.second);
    g2[e.second].push_back(e.first);
  }

  Dfs2(0, -1);
  for (int i = 0; i < n2; i++) {
    pr[i][0] = pv2[i];
  }
  for (int j = 1; j < H; j++) {
    for (int i = 0; i < n2; i++) {
      if (pr[i][j - 1] == -1) {
        pr[i][j] = -1;
      } else {
        pr[i][j] = pr[pr[i][j - 1]][j - 1];
      }
    }
  }

  while (tt--) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    assert((depth2[u] + depth2[v]) % 2 == 0);
    int ans = (depth2[u] + depth2[v] - 2 * depth2[Lca(u, v)]) / 2;
    cout << ans << '\n';
  }

  return 0;
}