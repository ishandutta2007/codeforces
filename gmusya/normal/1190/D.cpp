#include <iostream>
#include <vector>
#include <map>
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
  void build(vi &a) {
    build(1, 0, n - 1, a);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  int cntx = 0, cnty = 0;
  {
    map <int, int> allx, ally;
    for (int i = 0; i < n; i++)
      allx[x[i]] = 0, ally[y[i]] = 0;
    for (auto &now : allx)
      now.second = cntx++;
    for (auto &now : ally)
      now.second = cnty++;
    for (int i = 0; i < n; i++)
      x[i] = allx[x[i]], y[i] = ally[y[i]];
  }
  vvi hor(cnty), ver(cntx);
  for (int i = 0; i < n; i++) {
    hor[y[i]].push_back(x[i]);
    ver[x[i]].push_back(y[i]);
  }
  vi y_max(cntx);
  for (int i = 0; i < cntx; i++) {
    sort(ver[i].begin(), ver[i].end());
    y_max[i] = ver[i].back();
  }
  for (int i = 0; i < cnty; i++)
    sort(hor[i].begin(), hor[i].end());
  merge_sort_tree mst(cntx);
  mst.build(y_max);
  long long ans = 0;
  for (int cury = 0; cury < cnty; cury++) {
    hor[cury].push_back(cntx);
    for (int i = 0; i + 1 < (int) hor[cury].size(); i++) {
      int x_old = hor[cury][i], x_new = hor[cury][i + 1];
      int left = mst.get(0, x_old, cury, cnty);
      int right = mst.get(x_old, x_new - 1, cury, cnty);
      ans += left * 1ll * right;
    }
  }
  cout << ans;
  return 0;
}