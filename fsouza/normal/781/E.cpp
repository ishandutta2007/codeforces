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

const int mod = 1e9 + 7;

struct barrier_t {
  int y, l, r, max_y, id;
};

barrier_t better(const barrier_t &a, const barrier_t &b) {
  if (a.id == -1) return b;
  if (b.id == -1) return a;
  if (a.y > b.y) return a;
  else return b;
}

struct segtree_t {
  int n;
  struct node_t {
    stack<barrier_t> values;
    void update(const barrier_t &barrier) {
      while (!values.empty() && values.top().max_y <= barrier.max_y)
        values.pop();
      values.push(barrier);
    }
    barrier_t query(int from_y) {
      while (!values.empty() && values.top().max_y < from_y)
        values.pop();
      if (values.empty()) return barrier_t({-1, -1, -1, -1, -1});
      else return values.top();
    }
  };
  vector<node_t> nodes;
  segtree_t(int _n): n(_n), nodes(4 * n) {}
  void update(int a, int b, const barrier_t &barrier, int v, int l, int r) {
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      nodes[v].update(barrier);
    } else {
      int m = l + (r - l) / 2;
      update(a, b, barrier, 2*v+1, l, m);
      update(a, b, barrier, 2*v+2, m+1, r);
    }
  }
  void update(int a, int b, const barrier_t &barrier) {
    update(a, b, barrier, 0, 0, n-1);
  }
  barrier_t query(int x, int from_y, int v, int l, int r) {
    barrier_t result = nodes[v].query(from_y);
    if (l != r) {
      int m = l + (r - l) / 2;
      if (x <= m) result = better(result, query(x, from_y, 2*v+1, l, m));
      else result = better(result, query(x, from_y, 2*v+2, m+1, r));
    }
    return result;
  }
  barrier_t query(int x, int from_y) { return query(x, from_y, 0, 0, n-1); }
};

int main() {
  int height, width, n;
  scanf("%d %d %d", &height, &width, &n);

  vector<barrier_t> barriers(n);
  for (int i = 0; i < n; ++i) {
    int max_fall;
    scanf("%d %d %d %d", &barriers[i].y, &barriers[i].l, &barriers[i].r,
          &max_fall);
    --barriers[i].y, --barriers[i].l, --barriers[i].r;
    barriers[i].max_y = barriers[i].y + max_fall;
    barriers[i].id = i;
  }

  segtree_t seg(width);
  vector<int> dp(n);

  sort(barriers.begin(), barriers.end(),
       [](const barrier_t &a, const barrier_t &b) {
         return a.y < b.y;
       });
  for (const barrier_t &barrier : barriers) {
    int leftres = -1, rightres = -1;
    if (barrier.l - 1 >= 0) {
      barrier_t left_hit = seg.query(barrier.l - 1, barrier.y);
      if (left_hit.id == -1) leftres = 1;
      else leftres = dp[left_hit.id];
    }
    if (barrier.r + 1 < width) {
      barrier_t right_hit = seg.query(barrier.r + 1, barrier.y);
      if (right_hit.id == -1) rightres = 1;
      else rightres = dp[right_hit.id];
    }
    int res;
    if (leftres == -1) res = 2 * rightres;
    else if (rightres == -1) res = 2 * leftres;
    else res = leftres + rightres;
    if (res >= mod) res -= mod;
    dp[barrier.id] = res;
    seg.update(barrier.l, barrier.r, barrier);
  }

  int result = 0;
  for (int x = 0; x < width; ++x) {
    barrier_t hit = seg.query(x, height);
    if (hit.id == -1) result = result + 1;
    else result = result + dp[hit.id];
    if (result >= mod) result -= mod;
  }

  printf("%d\n", result);

  return 0;
}