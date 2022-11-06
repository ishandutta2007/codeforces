#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct UnionFind {
  vector<int> parent, rank;
  UnionFind(int n): parent(n), rank(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
  void join(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rank[a] > rank[b]) swap(a, b);
    parent[a] = b;
    if (rank[a] == rank[b]) ++rank[b];
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> table(n, vector<int>(m));
  for (int y = 0; y < n; ++y)
    for (int &v : table[y])
      scanf("%d", &v);

  UnionFind uf(n*m);
  vector<vector<int>> rawmorethan(n*m);
  auto parse = [&](vector<pair<int, int>> &vids) {
    sort(vids.begin(), vids.end());
    for (int i = 0; i+1 < (int)vids.size(); ++i)
      if (vids[i].first < vids[i+1].first)
	rawmorethan[vids[i+1].second].push_back(vids[i].second);
      else
	uf.join(vids[i+1].second, vids[i].second);
  };
  for (int y = 0; y < n; ++y) {
    vector<pair<int, int>> vids(m);
    for (int x = 0; x < m; ++x)
      vids[x] = make_pair(table[y][x], y*m + x);
    parse(vids);
  }
  for (int x = 0; x < m; ++x) {
    vector<pair<int, int>> vids(n);
    for (int y = 0; y < n; ++y)
      vids[y] = make_pair(table[y][x], y*m + x);
    parse(vids);
  }
  vector<vector<int>> morethan(n*m);
  for (int i = 0; i < n*m; ++i)
    for (int j : rawmorethan[i])
      morethan[uf.find(i)].push_back(uf.find(j));

  vector<int> result(n*m, -1);
  function<int(int)> solve = [&](int i) {
    if (result[i] != -1) return result[i];
    if (uf.find(i) != i) return result[i] = solve(uf.find(i));
    result[i] = 1;
    for (int j : morethan[i])
      result[i] = max(result[i], 1 + solve(j));
    return result[i];
  };
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (x > 0) printf(" ");
      printf("%d", solve(y*m + x));
    }
    printf("\n");
  }

  return 0;
}