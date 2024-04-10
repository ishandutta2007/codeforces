#include <bits/stdc++.h>
 
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, m;
  cin >> n >> m;
 
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  set<int> not_used;
  for (int i = 0; i < n; ++i) {
    not_used.insert(i);
    sort(graph[i].begin(), graph[i].end());
  }

  vector<vector<int>> answer;
  vector<int> q(n);
  int qt = 0;
  int qh = 0;
  auto add_vertex = [&](int v) {
    q[qt++] = v;
    answer.back().push_back(v);
  };
  for (int i = 0; i < n; ++i) {
    if (!not_used.count(i)) {
      continue;
    }
    qt = qh = 0;
    answer.emplace_back();
    add_vertex(i);
    not_used.erase(i);
    while (qt != qh) {
      auto last_tail = qt;
      auto v = q[qh++];
      int prev = -1;
      for (int u : graph[v]) {
        auto it = not_used.lower_bound(prev + 1);
        auto upto = not_used.lower_bound(u);
        for (; it != upto; ++it) {
          add_vertex(*it);
        }
        prev = u;
      }
      auto it = not_used.lower_bound(prev + 1);
      auto upto = not_used.end();
      for (; it != upto; ++it) {
        add_vertex(*it);
      }
      for (auto t = last_tail; t != qt; ++t) {
        not_used.erase(q[t]);
      }
    }
  }
  cout << answer.size() << '\n';
  for (auto const& comp : answer) {
    cout << comp.size() << ' ';
    for (auto x : comp) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}