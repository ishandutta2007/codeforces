#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

struct segment_tree {
  struct vertex {
    ll min1 = 0, min2 = INF, sum = 0;
    int cnt = 1;
    vertex() {}
  };
  int n;
  vector <vertex> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int v, int tl, int tr) {
    if (tl == tr)
      return;
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v].cnt = (tr - tl + 1);
  }
  void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, tl, tm, t[v].min1);
    update(v * 2 + 1, tm + 1, tr, tm + 1, tr, t[v].min1);
  }
  void update(int v) {
    int l = v * 2, r = v * 2 + 1;
    // cout << "L: " << t[l].min1 << ' ' << t[l].cnt << ' ' << t[l].min2 << ' ' << t[l].sum << '\n';
    // cout << "R: " << t[r].min1 << ' ' << t[r].cnt << ' ' << t[r].min2 << ' ' << t[r].sum << '\n';
    t[v].sum = t[l].sum + t[r].sum;
    if (t[l].min1 == t[r].min1) {
      t[v].min1 = t[l].min1;
      t[v].cnt = (t[l].cnt + t[r].cnt);
      t[v].min2 = min(t[l].min2, t[r].min2);
      // cout << "V: " << t[v].min1 << ' ' << t[v].cnt << ' ' << t[v].min2 << ' ' << t[v].sum << '\n';
      return;
    }
    if (t[l].min1 > t[r].min1)
      swap(l, r);
    t[v].min1 = t[l].min1;
    t[v].cnt = t[l].cnt;
    t[v].min2 = min(t[l].min2, t[r].min1);
  }
  void update(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r)
      return;
    if (t[v].min2 > val && l == tl && r == tr) {
      t[v].sum -= t[v].min1 * t[v].cnt;
      t[v].min1 = max(val, t[v].min1);
      t[v].sum += t[v].min1 * t[v].cnt;
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    update(v);
  }
  ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return t[v].sum;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    ll x = query(v * 2, tl, tm, l, min(r, tm));
    ll y = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return x + y;
  }
  void update(int l, int r, ll val) {
    update(1, 0, n - 1, l, r, val);
  }
  ll query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  segment_tree se(n);
  se.build(1, 0, n - 1);
  ll sum = 0;
  ll ans = 0;
  ll r = n;
  ll oldr = n;
  for (int i = n - 1; i >= 0; i--) {
    ll x, y;
    if (a[i] == 0) {
      se.update(r, n - 1, sum);
      x = se.query(r, n - 1);
      y = (r - i - 1) * (r - i) / 2;
      for (int j = i + 1; j < r; j++)
        se.update(j, j, j - i);
      r = i;
      sum = 0;
    } else {
      sum++;
      se.update(r, n - 1, sum);
      x = se.query(r, n - 1);
      y = (r - i) * (r - i + 1) / 2;
    }
    ans += x + y;
  }
  cout << ans;
  return 0;
}