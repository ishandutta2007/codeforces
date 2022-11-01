#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

const int INF = 500'000'000;

struct segment_tree {
  int n;
  vector <int> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2, INF);
  }
  void push(int v) {
    t[v * 2] = min(t[v], t[v * 2]);
    t[v * 2 + 1] = min(t[v], t[v * 2 + 1]);
  }
  void upd(int v, int tl, int tr, int l, int r, int val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] = min(t[v], val);
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
  }
  int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
      return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      return get(v * 2, tl, tm, pos);
    else
      return get(v * 2 + 1, tm + 1, tr, pos);
  }
  void upd(int l, int r, int val) {
    upd(1, 0, n - 1, l, r, val);
  }
  int get(int pos) {
    return get(1, 0, n - 1, pos);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n1, n2, n3, n4;
  cin >> n1 >> n2 >> n3 >> n4;
  vi a1(n1), a2(n2), a3(n3), a4(n4);
  for (int i = 0; i < n1; i++)
    cin >> a1[i];
  for (int i = 0; i < n2; i++)
    cin >> a2[i];
  for (int i = 0; i < n3; i++)
    cin >> a3[i];
  for (int i = 0; i < n4; i++)
    cin >> a4[i];
  vvi ban1(n1);
  int m1;
  cin >> m1;
  while (m1--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ban1[x].push_back(y);
  }
  segment_tree se2(n2);
  for (int i1 = 0; i1 < n1; i1++) {
    ban1[i1].push_back(-1);
    ban1[i1].push_back(n2);
    sort(ban1[i1].begin(), ban1[i1].end());
    int w = a1[i1];
    for (int j = 0; j + 1 < (int)ban1[i1].size(); j++) {
      int l = ban1[i1][j] + 1;
      int r = ban1[i1][j + 1] - 1;
      se2.upd(l, r, w);
    }
    ban1[i1] = vi();
  }
  vvi ban2(n2);
  int m2;
  cin >> m2;
  while (m2--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ban2[x].push_back(y);
  }
  segment_tree se3(n3);
  for (int i2 = 0; i2 < n2; i2++) {
    ban2[i2].push_back(-1);
    ban2[i2].push_back(n3);
    sort(ban2[i2].begin(), ban2[i2].end());
    int w = se2.get(i2) + a2[i2];
    for (int j = 0; j + 1 < (int)ban2[i2].size(); j++) {
      int l = ban2[i2][j] + 1;
      int r = ban2[i2][j + 1] - 1;
      se3.upd(l, r, w);
    }
    ban2[i2] = vi();
  }
  vvi ban3(n3);
  int m3;
  cin >> m3;
  while (m3--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ban3[x].push_back(y);
  }
  segment_tree se4(n4);
  for (int i3 = 0; i3 < n3; i3++) {
    ban3[i3].push_back(-1);
    ban3[i3].push_back(n4);
    sort(ban3[i3].begin(), ban3[i3].end());
    int w = se3.get(i3) + a3[i3];
    for (int j = 0; j + 1 < (int)ban3[i3].size(); j++) {
      int l = ban3[i3][j] + 1;
      int r = ban3[i3][j + 1] - 1;
      se4.upd(l, r, w);
    }
    ban3[i3] = vi();
  }
  int ans = 4 * INF;
  for (int i4 = 0; i4 < n4; i4++)
    ans = min(ans, se4.get(i4) + a4[i4]);
  if (ans >= 400'000'001)
    ans = -1;
  cout << ans;
  return 0;
}