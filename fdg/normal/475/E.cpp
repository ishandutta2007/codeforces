#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[2002], gt[2002];

int color[2002];

int repr(int x) {
  return color[x] == x ? x : color[x] = repr(color[x]);
}

void join(int x, int y) {
  color[repr(x)] = repr(y);
}

int used[2002];
vector<int> st;

void go(int v, int par = -1) {
  used[v] = 1;
  st.push_back(v);
  for (int u : g[v]) {
    if (u == par) continue;
    if (used[u] == 1) {
      join(u, v);
      for (int i = st.size() - 1; i >= 0; --i) {
        join(v, st[i]);
        if (st[i] == u) break;
      }
    }
    if (used[u] == 0) go(u, v);
  }
  st.pop_back();
  used[v] = 2;
}

int total = 0, ans = 0;
int sz[2002];
int cnt[2002] = {0};

int dfs(int v, int par = -1) {
  // cout << "DFS: " << v << endl;
  int ret = cnt[v];
  for (int u : gt[v]) {
    if (u != par) {
      ret += dfs(u, v);
    }
  }
  return sz[v] = ret;
} 

pair<int, int> dfs2(int v, int par = -1) {
  pair<int, int> ret = make_pair(0, cnt[v]);
  for (int u : gt[v]) {
    if (u == par) continue;
    auto p = dfs2(u, v);
    ret.second += p.second;
    ret.first += p.first + cnt[v] * p.second;
  }
  return ret;
}

set<pair<int, int>> ff;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i)
    color[i] = i;

  go(0, -1);
  for (int i = 0; i < n; ++i) {
    cnt[repr(i)]++;
  }
  
  total = n;
  for (int i = 0; i < n; ++i) {
    for (int v : g[i])
      if (repr(i) != repr(v) && !ff.count(make_pair(repr(i), repr(v)))) {
        gt[repr(i)].push_back(repr(v));
        ff.insert(make_pair(repr(i), repr(v)));
        // cout << repr(i) << "  " << repr(v) << endl;
      }
  }

  // for (int i = 0; i < n; ++i)
  //   cout << sz[i] << "  ";
  // cout << endl;

  for (int i = 0; i < n; ++i) {
    if (repr(i) != i) continue;
    memset(sz, 0, sizeof(sz));
    dfs(i, -1);
    int add = 0;
    for (int u : gt[i]) {
      auto p = dfs2(u, i);
      add += p.first;
      // cout << i << "  " << u << " " << p.first << " " << p.second << endl;
    }
    // cout << add << endl;
    int cur = 0;
    vector<int> v;
    for (int u : gt[i]) {
      v.push_back(sz[u]);
    }
    bool can[2002] = {0};
    can[0] = true;
    for (int a : v) {
      for (int j = n; j >= 0; --j)
        if (can[j]) can[j + a] = true;
    }
    for (int a = 0; a <= n; ++a) {
      if (can[a]) {
        cur = max(cur, a * (total - a) + cnt[i] * (total - cnt[i] - a));
      }
    }
    // cout << i << "  " << can[2] <<  " " << sz[i] << endl;
    ans = max(ans, cur + add);
  }
  // cout << sz[1] << "  " << sz[4] << endl;

  for (int i = 0; i < n; ++i)
    ans += cnt[i] * cnt[i];
  printf("%d\n", ans);
  return 0;
}