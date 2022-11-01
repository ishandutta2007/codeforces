#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

struct segment_tree {
  struct vertex {
    ll mod = 0, min = 0;
    vertex() {};
  };
  int n;
  vector <vertex> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void push(int v) {
    t[v * 2].mod += t[v].mod;
    t[v * 2 + 1].mod += t[v].mod;
    t[v].mod = 0;
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      t[v].min = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v].min = min(t[v * 2].min, t[v * 2 + 1].min);
  }
  void update(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v].mod += val;
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v].min = min(t[v * 2].min + t[v * 2].mod, t[v * 2 + 1].min + t[v * 2 + 1].mod);
  }
  ll get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return INF;
    if (l == tl && r == tr)
      return t[v].mod + t[v].min;
    push(v);
    int tm = (tl + tr) / 2;
    ll x = get(v * 2, tl, tm, l, min(r, tm));
    ll y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v].min = min(t[v * 2].min + t[v * 2].mod, t[v * 2 + 1].min + t[v * 2 + 1].mod);
    return min(x, y);
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  void update(int l, int r, ll val) {
    update(1, 0, n - 1, l, r, val);
  }
  ll get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
  void inc(int l, int r, int val) {
    if (l <= r) {
      update(l, r, val);
      return;
    }
    update(l, n - 1, val);
    update(0, r, val);
  }
  ll rmq(int l, int r) {
    if (l <= r)
      return get(l, r);
    ll x = get(l, n - 1);
    ll y = get(0, r);
    return min(x, y);
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
  segment_tree se(n);
  se.build(a);
  int q;
  cin >> q;
  string s;
  getline(cin, s);
  while (q--) {
    getline(cin, s);
    vector <int> val(1);
    vector <int> sig(1);
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == ' ') {
        val.push_back(0), sig.push_back(1);
      } else if (s[i] == '-') {
        sig.back() = -1;
      } else {
        val.back() = val.back() * 10 + (s[i] - '0');
      }
    }
    if (val.size() == 2) {
      int l = val[0], r = val[1];
      cout << se.rmq(l, r) << '\n';
    } else {
      int l = val[0], r = val[1], value = val[2] * sig[2];
      se.inc(l, r, value);
    }
  }
  return 0;
}