#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

struct segment_tree {
  int n;
  vector <ll> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
  ll get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    ll x = get(v * 2, tl, tm, l, min(r, tm));
    ll y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return x + y;
  }
  void update(int pos, ll val) {
    update(1, 0, n - 1, pos, val);
  }
  ll get(int l, int r) {
    return get(1, 0, n - 1, l, r);
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
  {
    map <int, int> m;
    for (int i = 0; i < n; i++)
      m[a[i]] = i;
    int x = 0;
    for (auto &now : m)
      a[now.second] = x++;
  }
  ll ans = 0;
  segment_tree se0(n), se1(n);
  for (int i = 0; i < n; i++) {
    se0.update(a[i], 1);
    se1.update(a[i], se0.get(a[i] + 1, n - 1));
    ans += se1.get(a[i] + 1, n - 1);
  }
  cout << ans;
  return 0;
}