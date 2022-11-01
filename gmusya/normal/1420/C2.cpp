#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 1e9;

struct segment_tree {
  struct node {
    ll odd_min = 0, odd_max = 0;
    ll even_min = 0, even_max = 0;
  };
  vector <node> t;
  segment_tree(vector <int> a) {
    int n = a.size();
    t.resize(n << 2);
    build(1, 0, n - 1, a);
  }
  node merge(node l, node r) {
    node ans;
    ans.odd_min = min(l.odd_min - r.even_max, l.even_min + r.odd_min);
    ans.odd_max = max(l.odd_max - r.even_min, l.even_max + r.odd_max);
    ans.even_min = min(l.odd_min - r.odd_max, l.even_min + r.even_min);
    ans.even_max = max(l.odd_max - r.odd_min, l.even_max + r.even_max);
    return ans;
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      t[v].odd_min = t[v].odd_max = a[tl];
      t[v].even_min = 0, t[v].even_max = 0;
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
  }
  void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      t[v].odd_min = t[v].odd_max = val;
      t[v].even_min = 0, t[v].even_max = 0;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    segment_tree se(a);
    cout << max(se.t[1].odd_max, se.t[1].even_max) << '\n';
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      swap(a[l], a[r]);
      se.update(1, 0, n - 1, l, a[l]);
      se.update(1, 0, n - 1, r, a[r]);
      cout << max(se.t[1].odd_max, se.t[1].even_max) << '\n';
    }
  }
  return 0;
}