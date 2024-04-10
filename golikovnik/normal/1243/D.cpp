#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<set<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].insert(v);
    graph[v].insert(u);
  }
  set<int> not_used;
  for (int i = 0; i < n; ++i) {
    not_used.insert(i);
  }

  auto fetch_neighbors = [&](int v) {
    vector<int> result;
    vector<pair<int, int>> segments;
    int prev = -1;
    for (auto u : graph[v]) {
      segments.emplace_back(prev + 1, u);
      prev = u;
    }
    segments.emplace_back(prev + 1, n);
    for (auto[l, r] : segments) {
      for (auto it = not_used.lower_bound(l); it != not_used.end(); ++it) {
        if (*it >= r) {
          break;
        }
        result.push_back(*it);
      }
    }
    return result;
  };

  int answer = 0;
  for (int i = 0; i < n; ++i) {
    if (!not_used.count(i)) {
      continue;
    }
    not_used.erase(i);
    answer++;
    queue<int> q({i});
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (auto u : fetch_neighbors(v)) {
        not_used.erase(u);
        q.push(u);
      }
    }
  }
  cout << answer - 1 << '\n';
  return 0;
}