#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;

struct segment_tree {
  int n;
  vector <int> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      t[v]++;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(v * 2, tl, tm, pos, val);
    else
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    int x = get(v * 2, tl, tm, l, min(r, tm));
    int y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return x + y;
  }
  void upd(int pos, int val) {
    upd(1, 0, n - 1, pos, val);
  }
  int get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <pii> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i].fi >> a[i].se;
    {
      map <int, int> allx;
      for (pii seg : a)
        allx[seg.fi] = allx[seg.se];
      int cnt = 0;
      for (auto &now : allx)
        now.se = cnt++;
      for (pii &seg : a) {
        seg.fi = allx[seg.fi];
        seg.se = allx[seg.se];
      }
    }
    sort(a.begin(), a.end());
    segment_tree stx(2 * n), sty(2 * n);
    for (int i = 0; i < n; i++) {
      stx.upd(a[i].fi, 1);
      sty.upd(a[i].se, 1);
    }
    vector <int> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = stx.get(a[i].se + 1, 2 * n - 1) + sty.get(0, a[i].fi - 1);
    cout << *min_element(ans.begin(), ans.end()) << '\n';
  }
  return 0;
}