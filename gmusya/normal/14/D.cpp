#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

const int INF = 1e9;

void dfs(int v, vector <bool> &used, vector <vector <int>> &g, vector <pair <int, int>> &ans) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u]) {
      dfs(u, used, g, ans);
      ans.push_back({u, v});
    }
}

vector <int> d(int s, vector <vector <int>> &g) {
  int n = g.size();
  vector <int> d(n, INF);
  queue <int> q;
  d[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v])
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        q.push(u);
      }
  }
  return d;
}

ll diameter(int s, vector <vector <int>> &g) {
  int n = g.size();
  vector <int> d0 = d(s, g);
  int id = s;
  for (int i = 0; i < n; i++)
    if (d0[i] > d0[id] && d0[i] != INF)
      id = i;
  vector <int> d1 = d(id, g);
  for (int i = 0; i < n; i++)
    if (d1[i] > d1[id] && d1[i] != INF)
      id = i;
  return (ll)d1[id];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <vector <int>> g(n);
  vector <pair <int, int>> edges(n - 1);
  for (int i = 0; i + 1 < n; i++) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--, edges[i].second--;
    g[edges[i].first].push_back(edges[i].second);
    g[edges[i].second].push_back(edges[i].first);
  }
  ll ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    int u = edges[i].first, v = edges[i].second;
    vector <vector <int>> g1(n), g2(n);
    {
      vector <bool> used(n);
      used[v] = true;
      vector <pair <int, int>> ans;
      dfs(u, used, g, ans);
      for (auto &now : ans) {
        g1[now.first].push_back(now.second);
        g1[now.second].push_back(now.first);
      }
    }
    {
      vector <bool> used(n);
      used[u] = true;
      vector <pair <int, int>> ans;
      dfs(v, used, g, ans);
      for (auto &now : ans) {
        g2[now.first].push_back(now.second);
        g2[now.second].push_back(now.first);
      }
    }
    ans = max(ans, diameter(u, g1) * diameter(v, g2));
  }
  cout << ans;
  return 0;
}