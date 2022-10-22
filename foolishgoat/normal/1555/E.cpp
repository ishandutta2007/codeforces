#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  int n;
  vector<int> val, lazy;
  SegTree(int _n) : n(_n), val(n * 2, 0), lazy(n * 2, 0) {}

  inline void upd(int id, int v) {
    val[id] += v;
    lazy[id] += v;
  }

  inline void pushdown(int id, int il, int ir) {
    if (lazy[id] == 0) return;
    upd(il, lazy[id]);
    upd(ir, lazy[id]);
    lazy[id] = 0;
  }

  inline void combine(int id, int il, int ir) {
    val[id] = min(val[il], val[ir]);
  }

  void update(int x, int y, int v, int id, int l, int r) {
    if (l >= y || x >= r) return;
    if (x <= l && r <= y) {
      upd(id, v);
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + (mid - l) * 2;
    pushdown(id, il, ir);
    update(x, y, v, il, l, mid);
    update(x, y, v, ir, mid, r);
    combine(id, il, ir);
  }

  void update(int x, int y, int v) {
    update(x, y, v, 0, 0, n);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector<tuple<int, int, int>> segments(m);
  for (int i = 0; i < m; ++i) {
    int l, r, w;
    cin >> l >> r >> w;
    --l, --r;
    segments[i] = {w, l, r};
  }
  SegTree segtree(n-1);
  sort(segments.begin(), segments.end());
  int ans = 1e9;
  for (int i = 0, j = 0; i < m; ++i) {
    while (j < m && segtree.val[0] <= 0) {
      int l, r, w;
      tie(w, l, r) = segments[j++];
      segtree.update(l, r, +1);
    }
    if (segtree.val[0] <= 0) {
      break;
    }
    int l, r, w;
    tie(w, l, r) = segments[i];
    ans = min(ans, get<0>(segments[j-1]) - w);
    segtree.update(l, r, -1);
  }
  cout << ans << '\n';
  return 0;
}