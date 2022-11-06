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

enum optype_t {
  INSERT,
  ERASE,
};

struct segtree_t {
  struct node_t {
    set<int> ids;
    int biggest_color_unmarked = -1;
    int smallest_color = -1;
  };
  vector<int> xs;
  int n;
  vector<bool> &marked;
  vector<node_t> tree;
  segtree_t(const vector<int> &_xs, vector<bool> &_marked)
    : xs(_xs), n(xs.size() - 1), marked(_marked), tree(4 * n) {}
  void update(optype_t optype, int a, int b, int id) {
    update(optype, a, b, id, 0, 0, n - 1);
    while (recalc(0, 0, n - 1), tree[0].biggest_color_unmarked >= 0)
      marked[tree[0].biggest_color_unmarked] = true;
  }
  void update(optype_t optype, int a, int b, int id, int v, int l, int r) {
    if (a >= xs[r + 1] || b <= xs[l]) {
    } else if (a <= xs[l] && xs[r + 1] <= b) {
      if (optype == INSERT) tree[v].ids.insert(id);
      else tree[v].ids.erase(id);
      recalc(v, l, r);
    } else {
      int m = l+(r-l)/2;
      update(optype, a, b, id, 2*v+1, l, m);
      update(optype, a, b, id, 2*v+2, m+1, r);
      recalc(v, l, r);
    }
  }
  void recalc(int v, int l, int r) {
    if (l != r) {
      int m = l+(r-l)/2;
      if (tree[2 * v + 1].biggest_color_unmarked >= 0 &&
          marked[tree[2 * v + 1].biggest_color_unmarked]) {
        recalc(2*v+1, l, m);
      }
      if (tree[2 * v + 2].biggest_color_unmarked >= 0 &&
          marked[tree[2 * v + 2].biggest_color_unmarked]) {
        recalc(2*v+2, m+1, r);
      }
      tree[v].smallest_color = min(tree[2 * v + 1].smallest_color,
                                   tree[2 * v + 2].smallest_color);
      tree[v].biggest_color_unmarked =
        max(tree[2 * v + 1].biggest_color_unmarked,
            tree[2 * v + 2].biggest_color_unmarked);
    } else {
      tree[v].smallest_color = -1;
      tree[v].biggest_color_unmarked = -1;
    }
    if (!tree[v].ids.empty()) {
      int top = *tree[v].ids.rbegin();
      tree[v].smallest_color = max(tree[v].smallest_color, top);
      if (tree[v].biggest_color_unmarked < top) {
        tree[v].biggest_color_unmarked = -1;
        if (!marked[top] && top == tree[v].smallest_color) {
          tree[v].biggest_color_unmarked = top;
        }
      }
    }
  }
};

int main() {
  int n;
  scanf("%d", &n);
  struct event_t {
    optype_t type;
    int y;
    int x0, x1, id;
    bool operator<(const event_t &o) const {
      if (y != o.y) return y < o.y;
      if (type != o.type) return type == INSERT;
      if (type == INSERT) return id > o.id;
      else return id < o.id;
    }
  };
  vector<event_t> events;
  vector<int> xs;
  for (int i = 0; i < n; ++i) {
    int x0, y0, x1, y1;
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    events.push_back({INSERT, y0, x0, x1, i});
    events.push_back({ERASE, y1, x0, x1, i});
    xs.push_back(x0);
    xs.push_back(x1);
  }
  sort(events.begin(), events.end());
  sort(xs.begin(), xs.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  vector<bool> marked(n, false);
  segtree_t seg(xs, marked);
  for (const event_t &ev : events)
    seg.update(ev.type, ev.x0, ev.x1, ev.id);
  int result = 1 + count(marked.begin(), marked.end(), true);
  printf("%d\n", result);
  return 0;
}