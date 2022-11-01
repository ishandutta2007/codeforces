#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct segment_tree {
    int n;
    vector <int> t, mod;
    segment_tree(int _n) {
      n = _n;
      t.resize(n << 2, INF);
      mod.resize(n << 2);
    }
    void push(int v) {
      mod[v * 2] += mod[v];
      mod[v * 2 + 1] += mod[v];
      t[v * 2] += mod[v];
      t[v * 2 + 1] += mod[v];
      mod[v] = 0;
      t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    void prisv(int v, int tl, int tr, int pos, int val) {
      if (tl == tr) {
        t[v] = val;
        return;
      }
      push(v);
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        prisv(v * 2, tl, tm, pos, val);
      else
        prisv(v * 2 + 1, tm + 1, tr, pos, val);
      t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    void upd(int v, int tl, int tr, int l, int r) {
      if (l > r)
        return;
      if (l == tl && r == tr) {
        mod[v]++;
        t[v]++;
        return;
      }
      push(v);
      int tm = (tl + tr) / 2;
      upd(v * 2, tl, tm, l, min(r, tm));
      upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
      t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    int get(int v, int tl, int tr, int l, int r) {
      if (l > r)
        return INF;
      if (l == tl && r == tr)
        return t[v];
      push(v);
      int tm = (tl + tr) / 2;
      int x = get(v * 2, tl, tm, l, min(r, tm));
      int y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
      return min(x, y);
    }
    int get(int l, int r) {
      return get(1, 0, n - 1, max(l, 0), min(n - 1, r));
    }
    void upd(int l, int r) {
      upd(1, 0, n - 1, max(l, 0), min(r, n - 1));
    }
    void prisv(int pos, int val) {
      prisv(1, 0, n - 1, pos, val);
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
  vector <int> last(n + 1, -1);
  vector <int> prev(n, -1);
  for (int i = 0; i < n; i++) {
    prev[i] = last[a[i]];
    if (i)
      last[a[i - 1]] = i - 1;
  }
  segment_tree st(n + 1);
  st.prisv(0, 1);
  vector <int> hm(n);
  hm[0] = 1;
  for (int i = 1; i < n; i++)
    hm[i] = hm[i - 1] + (a[i] != a[i - 1]);
  for (int i = 1; i < n; i++) {
    int newans;
    if (prev[i] == -1) {
      newans = max(st.get(0, i - 2), 1) + 1;
      newans = min(newans, hm[i - 1] + 1);
      st.prisv(i - 1, newans);
      if (a[i] != a[i - 1])
        st.upd(0, i - 2);
    } else {
      newans = max(st.get(0, prev[i] - 1), 1) + 1;
      newans = min(newans, hm[i - 1] + 1);
      newans = min(newans, st.get(prev[i] + 1, i - 2) + 1);
      newans = min(newans, st.get(prev[i], prev[i]));
      st.prisv(i - 1, newans);
      if (a[i] != a[i - 1])
        st.upd(0, i - 2);
    }
    if (i - 1 > 0 && a[i - 1] == a[i - 2])
      st.prisv(i - 2, INF);
    if (prev[i - 1] != -1)
      st.prisv(prev[i - 1], INF);
  }
  cout << st.get(0, n - 1);
  return 0;
}