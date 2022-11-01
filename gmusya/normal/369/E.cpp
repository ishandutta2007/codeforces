#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

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
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      t[v].push_back(a[tl]);
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
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  int get(int l, int r, int lval, int rval) {
    return get(1, 0, n - 1, l, r, lval, rval);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <int> l(n), r(n);
  {
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
      tie(l[i], r[i]) = tie(a[i].first, a[i].second);
  }
  merge_sort_tree mst(n);
  mst.build(r);
  while (q--) {
    int cnt;
    cin >> cnt;
    vector <int> x(cnt);
    for (int i = 0; i < cnt; i++)
      cin >> x[i];
    int ans = n;
    for (int i = 0; i + 1 < cnt; i++) {
      int lpos = upper_bound(l.begin(), l.end(), x[i]) - l.begin();
      int rpos = upper_bound(l.begin(), l.end(), x[i + 1]) - l.begin() - 1;
      ans -= mst.get(lpos, rpos, 0, x[i + 1] - 1);
    }
    {
      int lpos = 0;
      int rpos = upper_bound(l.begin(), l.end(), x[0]) - l.begin() - 1;
      ans -= mst.get(lpos, rpos, 0, x[0] - 1);
    }
    {
      int lpos = upper_bound(l.begin(), l.end(), x[cnt - 1]) - l.begin();
      int rpos = n - 1;
      ans -= mst.get(lpos, rpos, 0, 1e7);
    }
    cout << ans << '\n';
  }
  return 0;
}