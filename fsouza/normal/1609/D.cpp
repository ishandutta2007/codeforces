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
  int n, m;
  scanf("%d %d", &n, &m);

  vector<int> cnt_size(n, 1);

  multiset<int> sizes0, sizes1;
  int sum1 = 0;
  for (int i = 0; i < n; ++i)
    sizes0.insert(1);

  unionfind_t uf(n);
  int can_take = 1;

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;

    a = uf.find(a);
    b = uf.find(b);

    if (a == b) {
      ++can_take;
    } else {
      auto erase_size = [&](int size) {
        auto it = sizes0.find(size);
        if (it != sizes0.end()) {
          sizes0.erase(it);
        } else {
          it = sizes1.find(size);
          assert(it != sizes1.end());
          sum1 -= *it;
          sizes1.erase(it);
        }
      };

      int size_a = cnt_size[a], size_b = cnt_size[b];
      erase_size(size_a);
      erase_size(size_b);
      int v = uf.unite(a, b);
      cnt_size[v] = size_a + size_b;

      if (!sizes1.empty() && cnt_size[v] > *sizes1.begin()) {
        sizes1.insert(cnt_size[v]);
        sum1 += cnt_size[v];
      } else {
        sizes0.insert(cnt_size[v]);
      }
    }

    while ((int)sizes1.size() > can_take) {
      auto it = sizes1.begin();
      int size = *it;
      sizes1.erase(it);
      sum1 -= size;
      sizes0.insert(size);
    }

    while ((int)sizes1.size() < can_take && !sizes0.empty()) {
      auto it = sizes0.end(); --it;
      int size = *it;
      sizes0.erase(it);
      sizes1.insert(size);
      sum1 += size;
    }

    int result = sum1 - 1;

    printf("%d\n", result);
  }

  return 0;
}