#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

struct merge_sort_tree {
  int n;
  vvi t;
  merge_sort_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void build(int v, int tl, int tr, vi &a) {
    if (tl == tr) {
      t[v] = {a[tl]};
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), back_inserter(t[v]));
  }
  int get(int v, int tl, int tr, int l, int r, int lval, int rval) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return upper_bound(t[v].begin(), t[v].end(), rval) - lower_bound(t[v].begin(), t[v].end(), lval);
    int tm = (tl + tr) / 2;
    int x = get(v * 2, tl, tm, l, min(r, tm), lval, rval);
    int y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, lval, rval);
    return x + y;
  }
  int get(int l, int r, int lval, int rval) {
    return get(1, 0, n - 1, l, r, lval, rval);
  }
  int diff(int l, int r) {
    return (r - l + 1) - get(l, r, l, r);
  }
  void build(vi &a) {
    build(1, 0, n - 1, a);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i];
    a[i]--;
  }
  vi firstchange(n, q);
  for (int i = q - 1; i >= 0; i--)
    firstchange[a[i]] = i;
  vi ans_min(n), ans_max(n);
  for (int i = 0; i < n; i++) {
    if (firstchange[i] == q)
      ans_min[i] = i;
    else
      ans_min[i] = 0;
  }
  merge_sort_tree fst(n);
  fst.build(firstchange);
  for (int i = 0; i < n; i++)
    ans_max[i] = i + fst.get(i + 1, n - 1, 0, firstchange[i] - 1);
  vvi vhod(n);
  for (int i = 0; i < q; i++)
    vhod[a[i]].push_back(i);
  vi b(q, -1);
  for (int i = 0; i < n; i++)
    for (int j = 1; j < (int) vhod[i].size(); j++)
      b[vhod[i][j]] = vhod[i][j - 1];
  for (int i = 0; i < n; i++)
    vhod[i].push_back(q);
  merge_sort_tree mst(q);
  mst.build(b);
  for (int i = 0; i < n; i++)
    for (int j = 0; j + 1 < (int) vhod[i].size(); j++) {
      ans_max[i] = max(ans_max[i], mst.diff(vhod[i][j] + 1, vhod[i][j + 1] - 1));
    }
  for (int i = 0; i < n; i++)
    cout << ans_min[i] + 1 << ' ' << ans_max[i] + 1 << '\n';
  return 0;
}