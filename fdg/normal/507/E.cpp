#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <sstream>

using namespace std;

const int inf = 1000000007;

vector<pair<int, int>> g[100005];
int dist[100005], dp[100005], pr[100005];
vector<pair<int, int>> v;

set<pair<int, int>> f;
vector<string> ans;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z); --x; --y;
    g[x].push_back(make_pair(y, z));
    g[y].push_back(make_pair(x, z));
  }
  for (int i = 0; i < n; ++i)
    dist[i] = dp[i] = inf;
  priority_queue<pair<int, int>> q;
  dist[0] = 0;
  q.push({0, 0});
  while (q.size()) {
    pair<int, int> top = q.top(); q.pop();
    if (dist[top.second] != -top.first) continue;
    for (auto p : g[top.second]) {
      if (dist[p.first] > -top.first + 1) {
        dist[p.first] = -top.first + 1;
        q.push({-dist[p.first], p.first});
      }
    }
  }
  for (int i = 0; i < n; ++i)
    v.push_back({dist[i], i});
  sort(v.begin(), v.end());
  // cout << dist[n - 1] << endl;
  memset(pr, -1, sizeof(pr));
  dp[0] = 0;
  for (auto u : v) {
    for (auto p : g[u.second]) {
      if (dist[u.second] + 1 != dist[p.first]) continue;
      if (dp[p.first] > dp[u.second] + 1 - p.second) {
        dp[p.first] = dp[u.second] + 1 - p.second;
        pr[p.first] = 2 * u.second + p.second;
      }
    }
  }
  int cur = n - 1;
  while (cur != 0) {
    int u = pr[cur] / 2;
    if (pr[cur] % 2 == 0) {
      ostringstream ss;
      ss << u + 1 << " " << cur + 1 << " " << 1;
      ans.push_back(ss.str());
    }
    f.insert({u, cur});
    f.insert({cur, u});
    cur = u;
  }
  for (int i = 0; i < n; ++i) {
    for (auto p : g[i]) {
      if (p.second && !f.count({i, p.first})) {
        ostringstream ss;
        ss << i + 1 << " " << p.first + 1 << " " << 0;
        ans.push_back(ss.str());
        f.insert({i, p.first});
        f.insert({p.first, i});
      }
    }
  }
  printf("%d\n", (int) ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%s\n", ans[i].c_str());
  return 0;
}