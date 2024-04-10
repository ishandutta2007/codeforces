#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;

const int INF = 1e9;

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
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return -INF - 1;
    if (l == tl && r == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    int x = get(v * 2, tl, tm, l, min(r, tm));
    int y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return max(x, y);
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  int get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pair <pii, pii>> tmp(n);
  for (int i = 0; i < n; i++)
    cin >> tmp[i].fi.fi >> tmp[i].fi.se >> tmp[i].se.fi >> tmp[i].se.se;
  {
    sort(tmp.begin(), tmp.end());
    vector <int> l(n), r(n), s(n), f(n);
    for (int i = 0; i < n; i++) {
      l[i] = tmp[i].fi.fi;
      r[i] = tmp[i].fi.se;
      s[i] = tmp[i].se.fi;
      f[i] = tmp[i].se.se;
    }
    for (int i = 0; i < n; i++)
      f[i] = -f[i];
    segment_tree st_s(n), st_f(n);
    st_s.build(s), st_f.build(f);
    for (int i = 0; i < n; i++) {
      int pos = upper_bound(l.begin() + i, l.end(), r[i]) - l.begin() - 1;
      int minf = -st_f.get(i, pos);
      int maxs = st_s.get(i, pos);
      if (minf < s[i] || maxs > -f[i]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++)
    swap(tmp[i].fi, tmp[i].se);
  {
    sort(tmp.begin(), tmp.end());
    vector <int> l(n), r(n), s(n), f(n);
    for (int i = 0; i < n; i++) {
      l[i] = tmp[i].fi.fi;
      r[i] = tmp[i].fi.se;
      s[i] = tmp[i].se.fi;
      f[i] = tmp[i].se.se;
    }
    for (int i = 0; i < n; i++)
      f[i] = -f[i];
    segment_tree st_s(n), st_f(n);
    st_s.build(s), st_f.build(f);
    for (int i = 0; i < n; i++) {
      int pos = upper_bound(l.begin() + i, l.end(), r[i]) - l.begin() - 1;
      int minf = -st_f.get(i, pos);
      int maxs = st_s.get(i, pos);
      if (minf < s[i] || maxs > -f[i]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  return 0;
}