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
  int n, nq, limit;
  scanf("%d %d %d", &n, &nq, &limit);

  vector<int> size(n, 0);
  unionfind_t uf(n);
  int result = 0;

  auto increase = [&](int i, int delta) {
    if (size[i] > limit)
      return;
    size[i] += delta;
    if (size[i] > limit) {
      result += 1;

      if (i - 1 >= 0 && size[i - 1] > limit && uf.find(i) != uf.find(i - 1)) {
        uf.unite(i, i - 1);
        result -= 1;
      }
      if (i + 1 < n && size[i + 1] > limit && uf.find(i) != uf.find(i + 1)) {
        uf.unite(i, i + 1);
        result -= 1;
      }
    }
  };

  for (int i = 0; i < n; ++i) {
    int len;
    scanf("%d", &len);
    increase(i, len);
  }

  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 0) {
      printf("%d\n", result);
    } else {
      int i, delta;
      scanf("%d %d", &i, &delta), --i;
      increase(i, delta);
    }
  }

  return 0;
}