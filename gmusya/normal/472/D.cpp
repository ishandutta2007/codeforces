#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <queue>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

mt19937 gen;

vector <int> dsu;

int get(int v) {
  if (dsu[v] == v) return v;
  return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
  if (gen() % 2)
    swap(u, v);
  dsu[u] = v;
}

vector <ll> d(int s, vector <vector <pair <int, int>>> &g) {
  int n = g.size();
  vector <ll> d(n, INF);
  d[s] = 0;
  queue <int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto &now : g[v]) {
      int u = now.first, w = now.second;
      if (d[v] + w < d[u]) {
        d[u] = d[v] + w;
        q.push(u);
      }
    }
  }
  return d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  gen.seed(time(0));
  int n;
  cin >> n;
  dsu.resize(n);
  iota(dsu.begin(), dsu.end(), 0);
  vector <vector <int>> mat(n, vector <int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> mat[i][j];
  vector <pair <int, pair <int, int>>> ed;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ed.push_back({mat[i][j], {i, j}});
  sort(ed.begin(), ed.end());
  vector <vector <pair <int, int>>> g(n);
  for (auto &now : ed) {
    int w = now.first, u = now.second.first, v = now.second.second;
    int nu = get(u), nv = get(v);
    if (nu == nv) continue;
    merge(nu, nv);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 0; i < n; i++) {
    vector <ll> dis = d(i, g);
    for (int j = 0; j < n; j++)
      if (dis[j] != mat[i][j] || (i != j && mat[i][j] == 0)) {
        cout << "NO";
        return 0;
      }
  }
  cout << "YES";
  return 0;
}