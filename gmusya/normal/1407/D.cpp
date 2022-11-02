#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

struct segment_tree {
  int n;
  vi mi, ma;
  segment_tree(int _n) {
    n = _n;
    mi.resize(n << 2);
    ma.resize(n << 2);
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      mi[v] = ma[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    mi[v] = min(mi[v * 2], mi[v * 2 + 1]);
    ma[v] = max(ma[v * 2], ma[v * 2 + 1]);
  }
  int rightbigger(int v, int tl, int tr, int pos, int val) {
    if (tr < pos)
      return -1;
    if (ma[v] < val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = rightbigger(v * 2, tl, tm, pos, val);
    if (res == -1)
      res = rightbigger(v * 2 + 1, tm + 1, tr, pos, val);
    return res;
  }
  int leftbigger(int v, int tl, int tr, int pos, int val) {
    if (tl > pos)
      return -1;
    if (ma[v] < val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = leftbigger(v * 2 + 1, tm + 1, tr, pos, val);
    if (res == -1)
      res = leftbigger(v * 2, tl, tm, pos, val);
    return res;
  }
  int rightlower(int v, int tl, int tr, int pos, int val) {
    if (tr < pos)
      return -1;
    if (mi[v] > val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = rightlower(v * 2, tl, tm, pos, val);
    if (res == -1)
      res = rightlower(v * 2 + 1, tm + 1, tr, pos, val);
    return res;
  }
  int leftlower(int v, int tl, int tr, int pos, int val) {
    if (tl > pos)
      return -1;
    if (mi[v] > val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = leftlower(v * 2 + 1, tm + 1, tr, pos, val);
    if (res == -1)
      res = leftlower(v * 2, tl, tm, pos, val);
    return res;
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  int rightbigger(int pos, int val) {
    return rightbigger(1, 0, n - 1, pos, val);
  }
  int rightlower(int pos, int val) {
    return rightlower(1, 0, n - 1, pos, val);
  }
  int leftbigger(int pos, int val) {
    return leftbigger(1, 0, n - 1, pos, val);
  }
  int leftlower(int pos, int val) {
    return leftlower(1, 0, n - 1, pos, val);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  segment_tree st(n);
  st.build(h);
  vvi g(n);
  for (int i = 0; i < n; i++) {
    int val = h[i];
    int pos = st.leftlower(i - 1, val);
    if (pos != -1)
      g[pos].push_back(i);
    pos = st.rightlower(i + 1, val);
    if (pos != -1)
      g[i].push_back(pos);
    pos = st.leftbigger(i - 1, val);
    if (pos != -1)
      g[pos].push_back(i);
    pos = st.rightbigger(i + 1, val);
    if (pos != -1)
      g[i].push_back(pos);
  }
  queue <int> q;
  vector <int> d(n, n);
  q.push(0);
  d[0] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v])
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        q.push(u);
      }
  }
  cout << d[n - 1];
  return 0;
}