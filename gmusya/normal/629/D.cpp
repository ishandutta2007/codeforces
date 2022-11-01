#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long long ll;
typedef long double ld;

ld PI = atan2(0, -1);

struct segment_tree {
  int n;
  vector <ll> t, mod;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
    mod.resize(n << 2);
  }
  void push(int v) {
    t[v] = max(t[v], mod[v]);
    t[v * 2] = max(t[v * 2], mod[v]);
    t[v * 2 + 1] = max(t[v * 2 + 1], mod[v]);
    mod[v * 2] = max(mod[v], mod[v * 2]);
    mod[v * 2 + 1] = max(mod[v], mod[v * 2 + 1]);
  }
  ll get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    ll x = get(v * 2, tl, tm, l, min(r, tm));
    ll y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
    return max(x, y);
  }
  void upd(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      mod[v] = max(mod[v], val);
      t[v] = max(t[v], mod[v]);
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
  ll get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
  void upd(int l, int r, ll val) {
    return upd(1, 0, n - 1, l, r, val);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++) {
    ll r, h;
    cin >> r >> h;
    a[i] = r * r * h;
  }
  vector <ll> allval = a;
  sort(allval.begin(), allval.end());
  allval.resize(unique(allval.begin(), allval.end()) - allval.begin());
  segment_tree st((int)allval.size());
  for (int i = 0; i < n; i++) {
    int id = lower_bound(allval.begin(), allval.end(), a[i]) - allval.begin() - 1;
    ll s = st.get(0, id);
    s += a[i];
    st.upd(id + 1, (int)allval.size() - 1, s);
  }
  cout << fsp(15) << st.get(0, (int)allval.size() - 1) * PI;
  return 0;
}