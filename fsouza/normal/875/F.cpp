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

struct unionfind_t {
  vector<int> parent, rank;
  unionfind_t(int n): parent(n), rank(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
  }
  int join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return a;
    if (rank[a] > rank[b]) swap(a, b);
    parent[a] = b;
    if (rank[a] == rank[b]) ++rank[b];
    return b;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  struct edge_t {
    int a, b, value;
  };
  vector<edge_t> edges(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].value);
    --edges[i].a, --edges[i].b;
  }
  unionfind_t uf(n);
  vector<int> node_count(n, 1);
  vector<int> edge_count(n, 0);
  sort(edges.rbegin(), edges.rend(),
       [](const edge_t &a, const edge_t &b) { return a.value < b.value; });
  int result = 0;
  for (const edge_t &ed : edges) {
    int a = uf.find(ed.a), b = uf.find(ed.b);
    bool should_add;
    if (a == b) {
      should_add = (edge_count[a] + 1 <= node_count[a]);
    } else {
      should_add =
        (edge_count[a] + 1 + edge_count[b] <= node_count[a] + node_count[b]);
    }
    if (should_add) {
      int id;
      if (a != b) {
        id = uf.join(a, b);
        edge_count[id] = edge_count[a] + edge_count[b];
        node_count[id] = node_count[a] + node_count[b];
      } else {
        id = a;
      }
      ++edge_count[id];
      result += ed.value;
    }
  }
  printf("%d\n", result);
  return 0;
}