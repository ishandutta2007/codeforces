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
      result.insert(result.end(),
        not_used.lower_bound(l), not_used.lower_bound(r));
    }
    return result;
  };
 
  vector<int> answer;
  vector<int> q(n);
  for (int i = 0; i < n; ++i) {
    if (!not_used.count(i)) {
      continue;
    }
    not_used.erase(i);
    int result = 1;
    int qt = 0;
    int qh = 0;
    q[qt++] = i;
    while (qt != qh) {
      auto v = q[qh++];
      for (auto u : fetch_neighbors(v)) {
        not_used.erase(u);
        q[qt++] = u;
        result += 1;
      }
    }
    answer.push_back(result);
  }
  sort(answer.begin(), answer.end());
  cout << answer.size() << '\n';
  for (auto s : answer) {
    cout << s << ' ';
  }
  cout << '\n';
  return 0;
}