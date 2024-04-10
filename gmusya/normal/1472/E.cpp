#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

struct segment_tree {
  int n;
  vector <pii> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2, {1'000'000'001, -1});
  }
  void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      t[v] = {val, tl};
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(v * 2, tl, tm, pos, val);
    else
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  pii get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return {1'000'000'001, -1};
    if (l == tl && r == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    pii x = get(v * 2, tl, tm, l, min(r, tm));
    pii y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return min(x, y);
  }
  int first(int v, int tl, int tr, int val) {
    if (t[v].first >= val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = first(v * 2, tl, tm, val);
    if (res == -1)
      res = first(v * 2 + 1, tm + 1, tr, val);
    return res;
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
    vector <int> x(n), y(n);
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i];
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b) {
      if (x[a] != x[b])
        return x[a] < x[b];
      return y[a] < y[b];
    });
    segment_tree st(n);
    vector <int> ans(n, -1);
    for (int i = 0; i < n; i++)
      st.upd(1, 0, n - 1, i, y[p[i]]);
    int last = -1;
    for (int i = 0; i < n; i++) {
      last++;
      while (last < n && x[p[last]] < x[p[i]])
        last++;
      last--;
      if (last >= 0) {
        int pos = st.get(1, 0, n - 1, 0, last).second;
        if (y[p[pos]] < y[p[i]]) {
          ans[p[i]] = p[pos] + 1;
          continue;
        }
      }
      int id = st.first(1, 0, n - 1, x[p[i]]);
      if (id == -1)
        continue;
      if (x[p[id]] < y[p[i]] && y[p[id]] < x[p[i]])
        ans[p[i]] = p[id] + 1;
    }
    for (auto &now : ans)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}