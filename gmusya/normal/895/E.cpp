#include <iostream>
#include <vector>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long double ld;

struct segment_tree {
  int n;
  vector <ld> sum, mult, add;
  segment_tree(int _n) {
    n = _n;
    sum.resize(n << 2);
    mult.resize(n << 2);
    add.resize(n << 2);
  }
  void build(int v, int tl, int tr, vector <ld> &a) {
    if (tl == tr) {
      sum[v] = a[tl];
      mult[v] = 1;
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
    mult[v] = 1;
  }
  void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    sum[v * 2] *= mult[v];
    sum[v * 2 + 1] *= mult[v];
    mult[v * 2] *= mult[v];
    mult[v * 2 + 1] *= mult[v];
    add[v * 2] *= mult[v];
    add[v * 2 + 1] *= mult[v];
    mult[v] = 1;
    sum[v * 2] += (ld)(tm - tl + 1) * add[v];
    sum[v * 2 + 1] += (ld)(tr - tm) * add[v];
    add[v * 2] += add[v];
    add[v * 2 + 1] += add[v];
    add[v] = 0;
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
  }
  ld get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return sum[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    ld x = get(v * 2, tl, tm, l, min(r, tm));
    ld y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return x + y;
  }
  void upd(int v, int tl, int tr, int l, int r, ld mval, ld aval) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      sum[v] *= mval;
      sum[v] += (ld)(tr - tl + 1) * aval;
      mult[v] *= mval;
      add[v] *= mval;
      add[v] += aval;
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), mval, aval);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, mval, aval);
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
  }
  ld get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
  void upd(int l, int r, ld mval, ld aval) {
    upd(1, 0, n - 1, l, r, mval, aval);
  }
  void build(vector <ld> &a) {
    build(1, 0, n - 1, a);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <ld> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  segment_tree st(n);
  st.build(a);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      l1--, r1--, l2--, r2--;
      ld sum1 = st.get(l1, r1);
      ld sum2 = st.get(l2, r2);
      st.upd(l1, r1, (ld)(r1 - l1) / (ld)(r1 - l1 + 1), sum2 / (ld)(r2 - l2 + 1) / (ld)(r1 - l1 + 1));
      st.upd(l2, r2, (ld)(r2 - l2) / (ld)(r2 - l2 + 1), sum1 / (ld)(r1 - l1 + 1) / (ld)(r2 - l2 + 1));
    }
    if (t == 2) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << fsp(15) << st.get(l, r) << '\n';
    }
  }
  return 0;
}