// July 10, 2019
// https://codeforces.com/contest/1189/problem/D2

/*
I should probably stop writing const, other than the constants given in the
problem. For example, stop writing const Edge &e, just write Edge &e.
*/


#include <bits/stdc++.h>

using namespace std;


struct Edge {
  int from;
  int to;
  int add;
};

const int MAXN = 1000;

int N;
vector<int> g[MAXN];
vector<Edge> edges;
vector<int> path[MAXN];
vector<int> cur_path;
int root;
int add[MAXN][MAXN];
vector<int> leaf[MAXN];

void dfs(int v, int pv = -1) {
  path[v] = cur_path;
  int peid = -1; // id of edge leading to parent
  for (int id : g[v]) {
    Edge &e = edges[id];
    int to = e.from ^ e.to ^ v;
    if (to == pv) {
      peid = id;
      continue;
    }
    cur_path.push_back(id);
    dfs(to, v);
    cur_path.pop_back();
    if (leaf[v].size() < 2) {
      leaf[v].push_back(leaf[to][0]);
    }
  }
  if (pv == -1) {
    return;
  }
  int val = edges[peid].add;
  assert(val % 2 == 0);
  if (leaf[v][0] == v) {
    add[root][v] += val;
  } else {
    int a = leaf[v][0], b = leaf[v][1];
    add[root][a] += val / 2;
    add[root][b] += val / 2;
    add[a][b] -= val / 2;
  }
  for (int id : path[pv]) {
    edges[id].add -= val;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int u, v, val;
    cin >> u >> v >> val;
    u--;
    v--;
    int id = (int) edges.size();
    g[u].push_back(id);
    g[v].push_back(id);
    edges.push_back({u, v, val});
  }
  for (int i = 0; i < N; i++) {
    int d = (int) g[i].size();
    if (d == 2) {
      cout << "NO\n";
      return 0;
    }
    if (d == 1) {
      leaf[i].push_back(i);
      root = i;
    }
  }
  dfs(root);
  vector<Edge> changes; // not actually edges
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (add[i][j] != 0) {
        changes.push_back({i + 1, j + 1, add[i][j]});
      }
    }
  }
  cout << "YES\n";
  cout << changes.size() << '\n';
  for (Edge &c : changes) {
    cout << c.from << ' ' << c.to << ' ' << c.add << '\n';
  }



  return 0;
}