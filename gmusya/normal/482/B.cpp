#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segment_tree_or {
  int n;
  vector <int> t;
  segment_tree_or(int _n) {
    n = _n;
    t.resize(n << 2);
  };
  void update(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] = 1;
      return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm));
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  void get(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      a[tl] = t[v];
      return;
    }
    if (t[v]) {
      t[v * 2] = 1;
      t[v * 2 + 1] = 1;
    }
    int tm = (tl + tr) / 2;
    get(v * 2, tl, tm, a);
    get(v * 2 + 1, tm + 1, tr, a);
  }
};

struct segment_tree_and {
  int n;
  vector <int> t;
  segment_tree_and(int _n) {
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
    t[v] = (t[v * 2] & t[v * 2 + 1]);
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return (1 << 30) - 1;
    if (l == tl && r == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    int x = get(v * 2, tl, tm, l, min(r, tm));
    int y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return (x & y);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <segment_tree_or> se(30, segment_tree_or(n));
  vector <pair <pair <int, int>, int>> queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i].first.first >> queries[i].first.second >> queries[i].second;
    queries[i].first.first--, queries[i].first.second--;
    for (int j = 0; j < 30; j++)
      if ((1 << j) & queries[i].second)
        se[j].update(1, 0, n - 1, queries[i].first.first, queries[i].first.second);
  }
  vector <int> arr(n);
  for (int j = 0; j < 30; j++) {
    vector <int> a(n);
    se[j].get(1, 0, n - 1, a);
    for (int i = 0; i < n; i++)
      arr[i] |= a[i] * (1 << j);
  }
  segment_tree_and seand(n);
  seand.build(1, 0, n - 1, arr);
  for (int i = 0; i < q; i++) {
    int l = queries[i].first.first, r = queries[i].first.second, val = queries[i].second;
    if (seand.get(1, 0, n - 1, l, r) != val) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  for (auto &now : arr)
    cout << now << ' ';
  return 0;
}