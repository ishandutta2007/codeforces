#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct segment_tree {
  struct vertex {
    bool flag = false;
    int cnt4 = 0, cnt7 = 0;
    int cnt47 = 0, cnt74 = 0;
  };
  int n;
  vector <vertex> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void push(int v, int tl, int tr) {
    if (t[v].flag) {
      swap(t[v].cnt4, t[v].cnt7);
      swap(t[v].cnt47, t[v].cnt74);
      if (tl != tr) {
        t[v * 2].flag = !t[v * 2].flag;
        t[v * 2 + 1].flag = !t[v * 2 + 1].flag;
      }
    }
    t[v].flag = false;
  }
  void build(int v, int tl, int tr, string &s) {
    if (tl == tr) {
      t[v].flag = false;
      if (s[tl] == '4')
        t[v].cnt4++;
      else
        t[v].cnt7++;
      t[v].cnt47 = t[v].cnt74 = 1;
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, s);
    build(v * 2 + 1, tm + 1, tr, s);
    int lv = v * 2, rv = v * 2 + 1;
    t[v].cnt4 = (t[lv].cnt4 + t[rv].cnt4);
    t[v].cnt7 = (t[lv].cnt7 + t[rv].cnt7);
    t[v].cnt47 = max({t[lv].cnt4 + t[rv].cnt47, t[lv].cnt47 + t[rv].cnt7, t[lv].cnt4 + t[rv].cnt7});
    t[v].cnt74 = max({t[lv].cnt74 + t[rv].cnt4, t[lv].cnt7 + t[rv].cnt74, t[lv].cnt7 + t[rv].cnt4});
    t[v].flag = false;
  }
  void sw(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r)
      return;
    if (l == tl && r == tr) {
      swap(t[v].cnt4, t[v].cnt7);
      swap(t[v].cnt47, t[v].cnt74);
      if (tl != tr) {
        t[v * 2].flag = !t[v * 2].flag;
        t[v * 2 + 1].flag = !t[v * 2 + 1].flag;
      }
      return;
    }
    int tm = (tl + tr) / 2;
    sw(v * 2, tl, tm, l, min(r, tm));
    sw(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    int lv = v * 2, rv = v * 2 + 1;
    t[v].cnt4 = (t[lv].cnt4 + t[rv].cnt4);
    t[v].cnt7 = (t[lv].cnt7 + t[rv].cnt7);
    t[v].cnt47 = max({t[lv].cnt4 + t[rv].cnt47, t[lv].cnt47 + t[rv].cnt7, t[lv].cnt4 + t[rv].cnt7});
    t[v].cnt74 = max({t[lv].cnt74 + t[rv].cnt4, t[lv].cnt7 + t[rv].cnt74, t[lv].cnt7 + t[rv].cnt4});
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  segment_tree se(n);
  string s;
  cin >> s;
  se.build(1, 0, n - 1, s);
  while (q--) {
    string t;
    cin >> t;
    if (t == "count") {
      cout << se.t[1].cnt47 << '\n';
    }
    if (t == "switch") {
      int l, r;
      cin >> l >> r;
      l--, r--;
      se.sw(1, 0, n - 1, l, r);
    }
  }
  return 0;
}