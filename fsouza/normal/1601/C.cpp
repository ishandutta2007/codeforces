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

struct segtree_t {
  struct node_t {
    int min_value = 0;
    int delta = 0;
    int value = 0;
  };

  int n;
  vector<node_t> tree;
  segtree_t(int _n): n(_n), tree(4 * n) {}
  void update(int a, int b, int delta) {
    if (a > b) return;
    update(a, b, delta, 0, 0, n - 1);
  }
  void update(int a, int b, int delta, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      tree[v].delta += delta;
      propag(v, l, r);
    } else {
      int m = l + (r - l) / 2;
      update(a, b, delta, 2*v+1, l, m);
      update(a, b, delta, 2*v+2, m+1, r);
      tree[v].min_value = min(tree[2 * v + 1].min_value,
                              tree[2 * v + 2].min_value);
      tree[v].delta = 0;
      tree[v].value = -1;
    }
  }
  void propag(int v, int l, int r) {
    if (tree[v].delta == 0) return;
    if (l == r) {
      tree[v].value += tree[v].delta;
      tree[v].min_value += tree[v].delta;
      tree[v].delta = 0;
    } else {
      tree[2*v+1].delta += tree[v].delta;
      tree[2*v+2].delta += tree[v].delta;
      tree[v].min_value += tree[v].delta;
      tree[v].delta = 0;
    }
  }
};

struct bit_t {
  int n;
  vector<int> tree;
  bit_t(int _n): n(_n + 2), tree(n + 4) {}
  void update(int v, int delta) {
    for (++v; v < n; v += v&-v)
      tree[v] += delta;
  }
  int query(int v) {
    int res = 0;
    for (++v; v > 0; v -= v&-v)
      res += tree[v];
    return res;
  }
};

lint compute_inversions(vector<int> a) {
  int n = a.size();
  vector<int> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());
  for (int i = 0; i < n; ++i)
    a[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin();

  lint result = 0LL;
  bit_t bit(n + 2);
  for (int i = n - 1; i >= 0; --i) {
    result += bit.query(a[i] - 1);
    bit.update(a[i], +1);
  }
  return result;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
      scanf("%d", &b[i]);
    {
      int max_v = max(*max_element(b.begin(), b.end()),
                      *max_element(a.begin(), a.end()));
      a.push_back(max_v + 1);
      ++n;
    }
    lint result = compute_inversions(a);

    segtree_t seg(n);
    for (int i = 0; i < n; ++i)
      seg.update(i + 1, n - 1, +1);

    vector<pair<int, int>> sorted_a(n);
    for (int i = 0; i < n; ++i)
      sorted_a[i] = {a[i], i};
    sort(sorted_a.begin(), sorted_a.end());

    sort(b.begin(), b.end());

    int next_a = 0;
    int next_a2 = 0;
    for (int i = 0; i < m; ++i) {
      while (next_a < n && sorted_a[next_a].first <= b[i]) {
        int pos = sorted_a[next_a].second;
        seg.update(pos + 1, n - 1, -1);
        ++next_a;
      }
      while (next_a2 < n && sorted_a[next_a2].first < b[i]) {
        int pos = sorted_a[next_a2].second;
        seg.update(0, pos, +1);
        ++next_a2;
      }
      result += seg.tree[0].min_value;
    }

    printf("%lld\n", result);
  }
  return 0;
}