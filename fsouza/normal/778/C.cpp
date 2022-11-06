#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxn = 300000, nlet = 26;

struct edge_t {
  int other, let;
};

vector<vector<edge_t>> adj;
int child[maxn][nlet], depth[maxn], subsize[maxn];
int result[maxn], depthdiff[maxn];
vector<pair<int, int>> undo;

int merge(int to, int from) {
  int res = 0;
  for (int l = 0; l < nlet; ++l)
    if (child[from][l] != -1) {
      if (child[to][l] == -1) {
        res += subsize[child[from][l]];
        child[to][l] = child[from][l];
        undo.emplace_back(to, l);
      } else {
        res += merge(child[to][l], child[from][l]);
      }
    }
  return res;
}

void dfs2(int v, int p) {
  int biggest_let = -1, biggest_size = -1;

  for (edge_t &ed : adj[v])
    if (ed.other != p)
      dfs2(ed.other, v);

  for (int let = 0; let < nlet; ++let)
    if (child[v][let] != -1 &&
        subsize[child[v][let]] > biggest_size) {
      biggest_size = subsize[child[v][let]];
      biggest_let = let;
    }
  if (biggest_let == -1) {
    result[v] = 1;
  } else {
    result[v] = biggest_size;
    for (int let = 0; let < nlet; ++let)
      if (let != biggest_let && child[v][let] != -1)
        result[v] += merge(child[v][biggest_let], child[v][let]);
    for (pair<int, int> ed : undo) {
      child[ed.first][ed.second] = -1;
    }
    undo.clear();
  }

  depthdiff[depth[v]] += subsize[v] - result[v];
}

void dfs(int v, int p, int d) {
  depth[v] = d;
  subsize[v] = 1;
  for (edge_t &ed : adj[v])
    if (ed.other != p) {
      child[v][ed.let] = ed.other;
      dfs(ed.other, v, d + 1);
      subsize[v] += subsize[ed.other];
    }
}

int main() {
  int n;
  scanf("%d", &n);
  adj.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    char c;
    scanf(" %d %d %c", &a, &b, &c), --a, --b;
    adj[a].push_back(edge_t{b, c - 'a'});
    adj[b].push_back(edge_t{a, c - 'a'});
  }

  memset(depthdiff, 0, sizeof(depthdiff));
  memset(child, -1, sizeof(child));
  dfs(0, -1, 0);
  dfs2(0, -1);

  int best = -1, bestd = -1;
  for (int d = 0; d < n; ++d)
    if (depthdiff[d] > best) {
      best = depthdiff[d];
      bestd = d;
    }
  printf("%d\n", n - best);
  printf("%d\n", bestd + 1);

  return 0;
}