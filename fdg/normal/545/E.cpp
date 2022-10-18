#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int N = 300005;

vector<pair<int, int>> g[N];
long long dist[N];

vector<pair<int, pair<int, int>>> e;
map<pair<int, pair<int, int>>, int> f;

int color[N];

int repr(int x) {
  return color[x] = ((x == color[x]) ? x : repr(color[x]));
}

void join(int x, int y) {
  color[repr(x)] = repr(y);
}

int used[N];
set<pair<int, pair<int, int>>> all;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
    f[{c, {a, b}}] = i + 1;
    f[{c, {b, a}}] = i + 1;
  }
  int s;
  scanf("%d", &s); --s;

  memset(dist, -1, sizeof(dist));
  dist[s] = 0;
  priority_queue<pair<long long, int>> q;
  q.push({0, s});
  while (q.size()) {
    auto top = q.top(); q.pop();
    top.first *= -1;
    if (dist[top.second] != top.first) continue;
    for (auto p : g[top.second]) {
      long long ndist = top.first + p.second;
      if (dist[p.first] == -1 || dist[p.first] > ndist) {
        dist[p.first] = ndist;
        q.push({-ndist, p.first});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (auto p : g[i]) {
      if (dist[i] + p.second == dist[p.first]) {
        e.push_back({p.second, {i, p.first}});
      }
    }
  }
  sort(e.begin(), e.end());
  for (int i = 0; i < n; ++i)
    color[i] = i;
  vector<int> ans;
  long long len = 0;
  // for (auto edge : e) {
  //   if (repr(edge.second.second) != repr(edge.second.first)) {
  //     join(edge.second.first, edge.second.second);
  //     ans.push_back(f[edge]);
  //     len += edge.first;
  //   }
  // }

/*  used[s] = true;
  for (auto p : g[s])
    if (dist[s] + p.second == dist[p.first])
      all.insert({p.second, {s, p.first}});

  while (all.size()) {
    auto ed = *all.begin();
    all.erase(all.begin());
    if (!used[ed.second.second]) {
      used[ed.second.second] = true;
      len += ed.first;
      ans.push_back(f[ed]);
      for (auto p : g[ed.second.second])
        if (dist[ed.second.second] + p.second == dist[p.first] && !used[p.first])
          all.insert({p.second, {ed.second.second, p.first}});
    }
  }*/

  vector<pair<long long, int>> qq;
  for (int i = 0; i < n; ++i)
    qq.push_back({dist[i], i});
  sort(qq.begin(), qq.end());

  used[s] = true;
  for (auto top : qq) {
    if (!used[top.second]) {
      int mnlen = 2e+9;
      for (auto p : g[top.second]) {
        if (used[p.first] && dist[p.first] + p.second == dist[top.second]) {
          mnlen = min(mnlen, p.second);
        }
      }
      for (auto p : g[top.second]) {
        if (used[p.first] && dist[p.first] + p.second == dist[top.second] && p.second == mnlen) {
          used[top.second] = true;
          len += p.second;
          ans.push_back(f[{p.second, {top.second, p.first}}]);
          break;
        }
      }
    }
  }

  printf("%lld\n", len);
  for (int x : ans) {
    printf("%d ", x);
  }
  if (ans.size())
    printf("\n");
  return 0;
}