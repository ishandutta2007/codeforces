#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct segment_tree {
  int n;
  vector <ll> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
  }
  ll get(int v, int tl, int tr, int pos) {
    if (tl == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    t[v * 2] += t[v];
    t[v * 2 + 1] += t[v];
    t[v] = 0;
    if (pos <= tm)
      return get(v * 2, tl, tm, pos);
    else
      return get(v * 2 + 1, tm + 1, tr, pos);
  }
  void upd(int v, int tl, int tr, int l, int r, int val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] += val;
      return;
    }
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  ll get(int pos) {
    return get(1, 0, n - 1, pos);
  }
  void upd(int l, int r, int val) {
    upd(1, 0, n - 1, l, r, val);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll sum = 0;
  segment_tree st(n);
  st.build(a);
  for (int i = 0; i + 1 < n; i++)
    sum += max(0, a[i + 1] - a[i]);
  ll a0 = st.get(0);
  cout << max((a0 + sum) / 2, a0 - (a0 + sum) / 2 + sum) << '\n';
  int q;
  cin >> q;
  while (q--) {
    int l, r, val;
    cin >> l >> r >> val;
    l--, r--;
    if (l != 0)
      sum -= max(0ll, st.get(l) - st.get(l - 1));
    if (r != n - 1)
      sum -= max(0ll, st.get(r + 1) - st.get(r));
    st.upd(l, r, val);
    if (l != 0)
      sum += max(0ll, st.get(l) - st.get(l - 1));
    if (r != n - 1)
      sum += max(0ll, st.get(r + 1) - st.get(r));
    ll a0 = st.get(0);
    cout << max((a0 + sum) / 2, a0 - (a0 + sum) / 2 + sum) << '\n';
  }
  return 0;
}