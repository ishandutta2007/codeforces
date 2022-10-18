#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef vector<pair<int, int>> graph;
typedef long long llint;

graph canonizeIndices(graph e) {
  map<int, int> M;
  for (auto& p: e) {
    for (int x: {p.first, p.second}) {
      if (!M.count(x)) {
        int idx = M.size();
        M[x] = idx;
      }
    }
    p.first = M[p.first];
    p.second = M[p.second];
  }
  return e;
}

map<vector<int>, int> M;

int mapT(vector<int>& c) {
  if (!M.count(c)) {
    int x = M.size();
    M[c] = x;
  }
  return M[c];
}

int go(int x, int dad, vector<vector<int>>& E) {
  vector<int> ch;
  for (int y: E[x]) {
    if (y != dad) ch.push_back(go(y, x, E));
  }
  sort(ch.begin(), ch.end());
  return mapT(ch);
}

void dfsC(int x, int dad, vector<vector<int>>& E, vector<int>& sz, vector<int>& bal) {
  sz[x] = 1;
  bal[x] = 0;
  for (int y: E[x])
    if (y != dad) {
      dfsC(y, x, E, sz, bal);
      bal[x] = max(bal[x], sz[y]);
      sz[x] += sz[y];
    }
}

int canonizeTree(graph e) {
  e = canonizeIndices(e);
  int n = 0;
  for (auto& p: e) n = max(n, max(p.first, p.second) + 1);

  vector<vector<int>> E(n);
  for (auto& p: e) {
    E[p.first].push_back(p.second);
    E[p.second].push_back(p.first);
  }

  vector<int> sz(n, 0), bal(n, 0);
  dfsC(0, -1, E, sz, bal);

  int ans = -1;
  REP(x, n) {
    bal[x] = max(bal[x], n-sz[x]);
    if (2*bal[x] <= n) {
      int h = go(x, -1, E);
      if (ans == -1 || h < ans) ans = h;
    }
  }

  return ans;
}

void dfs(int x, vector<int>& bio, vector<vector<int>>& E, int t) {
  bio[x] = t;
  for (int y: E[x])
    if (!bio[y]) dfs(y, bio, E, t);
}

int canonizeForest(graph e) {
  e = canonizeIndices(e);
  int n = 0;
  for (auto& p: e) n = max(n, max(p.first, p.second) + 1);
  vector<int> bio(n, 0);
  vector<vector<int>> E(n);
  for (auto& p: e) {
    E[p.first].push_back(p.second);
    E[p.second].push_back(p.first);
  }
  
  vector<int> all;
  REP(i, n)
    if (!bio[i]) {
      dfs(i, bio, E, i+1);
      graph ne;
      for (auto& p: e)
        if (bio[p.first] == i+1 && bio[p.second] == i+1) ne.push_back(p);
      all.push_back(canonizeTree(ne));
    }
  sort(all.begin(), all.end());
  return mapT(all);
}

graph solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  assert(k == n);

  vector<graph> v;
  REP(i, n) {
    int m;
    scanf("%d", &m);
    graph w(m);
    REP(j, m) scanf("%d %d", &w[j].first, &w[j].second);
    v.push_back(canonizeIndices(w));
  }

  int p = 0;
  while (p < n && (int)v[p].size() != n-2) p++;
  if (p == n) return {};
  
  vector<int> all;
  REP(i, n) all.push_back(canonizeForest(v[i]));
  sort(all.begin(), all.end());
  
  
  graph g = v[p];
  REP(i, n-1) {
    g.push_back({i, n-1});

    multiset<int> S(all.begin(), all.end());
    REP(j, n) {
      graph ng;
      for (auto& p: g)
        if (p.first != j && p.second != j) ng.push_back(p);
      int h = canonizeForest(ng);
      if (S.count(h)) {
        S.erase(S.find(h));
      } else break;
    }

    if (!S.size()) return g;
    
    g.pop_back();
  }
  
  return {};
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    graph ans = solve();
    if (ans.size()) {
      puts("YES");
      for (auto& p: ans) printf("%d %d\n", p.first+1, p.second+1);
    } else {
      puts("NO");
    }
  }
  return 0;
}