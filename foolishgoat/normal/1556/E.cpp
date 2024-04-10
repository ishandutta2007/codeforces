#include <bits/stdc++.h>

using namespace std;

struct Node {
  long long ans;
  long long sum;
  long long lef_min;
  long long lef_max;
  long long rig_min;
  long long rig_max;
  Node(int x = 0) : ans(x), sum(x), lef_min(x), lef_max(x), rig_min(x), rig_max(x) {}
};

Node operator+(const Node &l, const Node &r) {
  Node ret;
  ret.sum = l.sum + r.sum;
  ret.ans = max(max(l.ans, r.ans), max(- l.rig_min - r.lef_min, l.rig_max + r.lef_max));
  ret.lef_min = min(l.lef_min, l.sum + r.lef_min);
  ret.lef_max = max(l.lef_max, l.sum + r.lef_max);
  ret.rig_min = min(l.rig_min + r.sum, r.rig_min);
  ret.rig_max = max(l.rig_max + r.sum, r.rig_max);
  return ret;
}

struct SegTree {
  int n;
  vector<Node> seg;
  SegTree(const vector<int> & a) {
    n = a.size();
    seg.resize(n * 2);
    build(a, 0, 0, n);
  }

  void build(const vector<int> & a, int id, int l, int r) {
    if (r-l < 2) {
      seg[id] = Node(a[l]);
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    build(a, il, l, mid);
    build(a, ir, mid, r);
    seg[id] = seg[il] + seg[ir];
  }

  Node get(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) {
      assert(false);
      return Node();
    }
    if (x <= l && r <= y) return seg[id];
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    if (y <= mid)
      return get(x, y, il, l, mid);
    if (x >= mid)
      return get(x, y, ir, mid, r);
    return get(x, y, il, l, mid) + get(x, y, ir, mid, r);
  }

  Node get(int x, int y) {
    return get(x, y, 0, 0, n);
  }
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = x - a[i];
  }
  SegTree s(a);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    Node res = s.get(l, r);
    long long ans = -1;
    if (res.lef_min >= 0 && res.sum == 0) {
      ans = res.ans;
    }
    printf("%lld\n", ans);
  }
  return 0;
}