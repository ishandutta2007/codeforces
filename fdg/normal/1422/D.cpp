#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

vector<pair<int, int>> p;

vector<pair<int, int>> allX, allY;

vector<pair<int, int>> g[100005];

long long dist[100005];

int main() {
  int n, m;
  int fx, fy;
  cin >> n >> m;
  p.resize(m + 1);
  cin >> p[0].first >> p[0].second >> fx >> fy;
  for (int i = 1; i <= m; ++i)
    cin >> p[i].first >> p[i].second;

  for (int i = 0; i < p.size(); ++i) {
    allX.push_back({p[i].first, i});
    allY.push_back({p[i].second, i});
  }
  sort(allX.begin(), allX.end());
  sort(allY.begin(), allY.end());

  for (int i = 0; i < allX.size(); ++i) {
    if (i) {
      int i1 = allX[i - 1].second, i2 = allX[i].second;
      int d = min(abs(p[i1].first - p[i2].first), abs(p[i1].second - p[i2].second));
      g[i1].push_back({i2, d});
      g[i2].push_back({i1, d});
    }
    if (i + 1 < allX.size()) {
      int i1 = allX[i + 1].second, i2 = allX[i].second;
      int d = min(abs(p[i1].first - p[i2].first), abs(p[i1].second - p[i2].second));
      g[i1].push_back({i2, d});
      g[i2].push_back({i1, d});
    }
  }
  for (int i = 0; i < allY.size(); ++i) {
    if (i) {
      int i1 = allY[i - 1].second, i2 = allY[i].second;
      int d = min(abs(p[i1].first - p[i2].first), abs(p[i1].second - p[i2].second));
      g[i1].push_back({i2, d});
      g[i2].push_back({i1, d});
    }
    if (i + 1 < allY.size()) {
      int i1 = allY[i + 1].second, i2 = allY[i].second;
      int d = min(abs(p[i1].first - p[i2].first), abs(p[i1].second - p[i2].second));
      g[i1].push_back({i2, d});
      g[i2].push_back({i1, d});
    }
  }

  memset(dist, -1, sizeof(dist));
  dist[0] = 0;
  priority_queue<pair<long long, int>> q;
  q.push({0, 0});

  while (q.size()) {
    long long d = -q.top().first, x = q.top().second;
    q.pop();

    if (dist[x] != d) continue;

    for (pair<int, int> p : g[x]) {
      long long nd = d + p.second;
      if (dist[p.first] == -1 || dist[p.first] > nd) {
        dist[p.first] = nd;
        q.push({-nd, p.first});
      }
    }
  }

  long long ans = 2e+15;
  for (int i = 0; i < p.size(); ++i) {
    if (dist[i] != -1) {
      ans = min(ans, 0LL + dist[i] + abs(fx - p[i].first) + abs(fy - p[i].second));
    }
  }
  cout << ans << endl;

  return 0;
}