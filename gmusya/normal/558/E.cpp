#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segment_tree {
  struct vertex {
    int val = 0;
    int sum = 0;
    vertex() {}
  };
  int n;
  vector <vertex> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void push(int v) {
    if (!t[v].val) return;
    t[v * 2].val = t[v].val;
    t[v * 2 + 1].val = t[v].val;
    t[v].val = 0;
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      t[v].sum = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
  }
  void update(int v, int tl, int tr, int l, int r, int val) {
    if (t[v].val == 1)
      t[v].sum = (tr - tl + 1);
    if (t[v].val == -1)
      t[v].sum = 0;
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v].val = val;
      if (t[v].val == 1)
        t[v].sum = (tr - tl + 1);
      if (t[v].val == -1)
        t[v].sum = 0;
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (t[v].val == 1)
      t[v].sum = (tr - tl + 1);
    if (t[v].val == -1)
      t[v].sum = 0;
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return t[v].sum;
    push(v);
    int tm = (tl + tr) / 2;
    int x = get(v * 2, tl, tm, l, min(r, tm));
    int y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
    return x + y;
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  void update(int l, int r, int val) {
    update(1, 0, n - 1, l, r, val);
  }
  int get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <vector <int>> arr(26, vector <int>(n));
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    arr[x - 'a'][i] = 1;
  }
  vector <segment_tree> se(26, segment_tree(n));
  for (int i = 0; i < 26; i++)
    se[i].build(arr[i]);
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    vector <int> cnt(26);
    for (int i = 0; i < 26; i++)
      cnt[i] = se[i].get(l, r);
    for (int i = 0; i < 26; i++)
      se[i].update(l, r, -1);
    int k;
    cin >> k;
    int sum = 0;
    if (k == 1) {
      for (int i = 0; i < 26; i++) {
        se[i].update(l + sum, l + sum + cnt[i] - 1, 1);
        sum += cnt[i];
      }
    } else {
      for (int i = 25; i >= 0; i--) {
        se[i].update(l + sum, l + sum + cnt[i] - 1, 1);
        sum += cnt[i];
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (char c = 'a'; c <= 'z'; c++)
      if (se[c - 'a'].get(i, i) == 1)
        cout << c;
  return 0;
}