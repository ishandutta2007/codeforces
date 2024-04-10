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
  int n;
  vector<int> parent, rank;
  unionfind_t(int _n): n(_n), parent(n), rank(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
  }
  int unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return a;
    if (rank[a] > rank[b]) swap(a, b);
    parent[a] = b;
    if (rank[a] == rank[b]) ++rank[b];
    return b;
  }
};

int main() {
  int n, m, nq;
  scanf("%d %d %d", &n, &m, &nq);
  unionfind_t uf(n + m);
  for (int q = 0; q < nq; ++q) {
    int y, x;
    scanf("%d %d", &y, &x), --y, --x;
    uf.unite(y, n + x);
  }
  int ncnt = 0;
  for (int i = 0; i < n + m; ++i)
    if (uf.parent[i] == i)
      ++ncnt;
  printf("%d\n", ncnt - 1);
  return 0;
}