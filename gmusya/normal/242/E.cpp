#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

struct segment_tree {
  int n;
  vector <int> val;
  vector <bool> rev;
  vector <int> sz;
  segment_tree(int _n) {
    n = _n;
    val.resize(n << 2);
    rev.resize(n << 2);
    sz.resize(n << 2);
  }
  void push(int v) {
    rev[v * 2] = (rev[v] ^ rev[v * 2]);
    rev[v * 2 + 1] = (rev[v] ^ rev[v * 2 + 1]);
    rev[v] = 0;
  }
  void update(int v) {
    val[v] = 0;
    if (rev[v * 2])
      val[v] += sz[v * 2] - val[v * 2];
    else
      val[v] += val[v * 2];
    if (rev[v * 2 + 1])
      val[v] += sz[v * 2 + 1] - val[v * 2 + 1];
    else
      val[v] += val[v * 2 + 1];
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      sz[v] = 1;
      val[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    sz[v] = sz[v * 2] + sz[v * 2 + 1];
    val[v] = val[v * 2] + val[v * 2 + 1];
  }
  void update(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      rev[v] = (rev[v] ^ 1);
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm));
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    update(v);
  }
  int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr) {
      if (rev[v])
        return sz[v] - val[v];
      return val[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    int x = sum(v * 2, tl, tm, l, min(r, tm));
    int y = sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    update(v);
    return x + y;
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  void update(int l, int r) {
    update(1, 0, n - 1, l, r);
  }
  int sum(int l, int r) {
    return sum(1, 0, n - 1, l, r);
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
  vector <segment_tree> se(20, segment_tree(n));
  for (int pow = 0; pow < 20; pow++) {
    vector <int> tmp(n);
    for (int i = 0; i < n; i++)
      if (a[i] & (1 << pow))
        tmp[i] = 1;
    se[pow].build(tmp);
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      ll ans = 0;
      for (int pow = 0; pow < 20; pow++)
        ans += (1ll << pow) * se[pow].sum(l, r);
      cout << ans << '\n';
    }
    if (type == 2) {
      int l, r, val;
      cin >> l >> r >> val;
      l--, r--;
      for (int pow = 0; pow < 20; pow++)
        if ((1 << pow) & val)
          se[pow].update(l, r);
    }
  }
  return 0;
}