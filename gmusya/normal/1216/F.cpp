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
    t.resize(n << 2, 1e18);
  }
  void upd(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(v * 2, tl, tm, pos, val);
    else
      upd(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  ll get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 1e18;
    if (l == tl && r == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    ll x = get(v * 2, tl, tm, l, min(r, tm));
    ll y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return min(x, y);
  }
  void upd(int pos, ll val) {
    upd(1, 0, n - 1, pos, val);
  }
  ll get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  k++;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  segment_tree stpas(n + 1), stact(n + 1);
  stpas.upd(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1)
      stact.upd(i, stpas.get(i + 1, min(i + k, n)) + (i + 1));
    ll val = min(stact.get(i, min(i + k - 1, n)), stpas.get(i + 1, i + 1) + (i + 1));
    stpas.upd(i, val);
  }
  cout << stpas.get(0, 0);
  return 0;
}