#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

struct segment_tree {
  int n;
  vi cnt0, cnt1, mod, sz;
  segment_tree(int _n) {
    n = _n;
    cnt0.resize(n << 2);
    cnt1.resize(n << 2);
    mod.resize(n << 2);
    sz.resize(n << 2);
  }
  void push(int v) {
    if (mod[v] == 1) {
      mod[v * 2] = 1;
      cnt0[v * 2] = 0;
      cnt1[v * 2] = sz[v * 2];
      mod[v * 2 + 1] = 1;
      cnt0[v * 2 + 1] = 0;
      cnt1[v * 2 + 1] = sz[v * 2 + 1];
    }
    if (mod[v] == 0) {
      mod[v * 2] = 0;
      cnt0[v * 2] = sz[v * 2];
      cnt1[v * 2] = 0;
      mod[v * 2 + 1] = 0;
      cnt0[v * 2 + 1] = sz[v * 2 + 1];
      cnt1[v * 2 + 1] = 0;
    }
    mod[v] = -1;
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      sz[v] = a[tl];
      cnt0[v] = 0;
      cnt1[v] = sz[v];
      mod[v] = -1;
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    cnt0[v] = cnt0[v * 2] + cnt0[v * 2 + 1];
    cnt1[v] = cnt1[v * 2] + cnt1[v * 2 + 1];
    sz[v] = sz[v * 2] + sz[v * 2 + 1];
    mod[v] = -1;
  }
  void upd(int v, int tl, int tr, int l, int r, int val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      if (val == 0) {
        mod[v] = 0;
        cnt0[v] = sz[v];
        cnt1[v] = 0;
      } else {
        mod[v] = 1;
        cnt0[v] = 0;
        cnt1[v] = sz[v];
      }
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    cnt0[v] = cnt0[v * 2] + cnt0[v * 2 + 1];
    cnt1[v] = cnt1[v * 2] + cnt1[v * 2 + 1];
  }
  int get() {
    return cnt1[1];
  }
  void upd(int l, int r, int val) {
    return upd(1, 0, n - 1, l, r, val);
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi l(q), r(q), k(q);
  vi x;
  x.push_back(n + 1);
  x.push_back(1);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i] >> k[i];
    k[i]--;
    x.push_back(l[i]);
    x.push_back(r[i]);
    x.push_back(r[i] + 1);
  }
  sort(x.begin(), x.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  int m = (int) x.size();
  vi sz(m);
  for (int i = 0; i + 1 < m; i++)
    sz[i] = x[i + 1] - x[i];
  segment_tree st(m);
  st.build(sz);
  for (int i = 0; i < q; i++) {
    int curl = lower_bound(x.begin(), x.end(), l[i]) - x.begin();
    int curr = lower_bound(x.begin(), x.end(), r[i]) - x.begin();
    st.upd(curl, curr, k[i]);
    cout << st.get() << '\n';
  }
  return 0;
}