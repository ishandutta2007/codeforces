#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segment_tree {
  int n;
  vector <int> t;
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
    t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
  }
  void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(v * 2, tl, tm, pos, val);
    else
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
  }
  int check(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
      return 0;
    if (t[v] % x == 0)
      return 0;
    if (tl == tr)
      return 1;
    int tm = (tl + tr) / 2;
    int left = check(v * 2, tl, tm, l, min(r, tm), x);
    if (left > 1)
      return 2;
    int right = check(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    return left + right;
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  void upd(int pos, int val) {
    upd(1, 0, n - 1, pos, val);
  }
  bool check(int l, int r, int x) {
    return check(1, 0, n - 1, l, r, x) < 2;
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
  segment_tree st(n);
  st.build(a);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l--, r--;
      if (st.check(l, r, x))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (t == 2) {
      int pos, val;
      cin >> pos >> val;
      pos--;
      st.upd(pos, val);
    }
  }
  return 0;
}