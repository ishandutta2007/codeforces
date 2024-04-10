#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> pii;

struct segment_tree {
  int n;
  vector <int> t, mod;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
    mod.resize(n << 2);
  }
  void upd(int v, int tl, int tr, int l, int r, int val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      mod[v] += val;
      return;
    }
    int tm = (tl + tr) / 2;
    mod[v * 2] += mod[v];
    mod[v * 2 + 1] += mod[v];
    mod[v] = 0;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v * 2] + mod[v * 2], t[v * 2 + 1] + mod[v * 2 + 1]);
  }
  int firstzero(int v, int tl, int tr) {
    if (t[v] + mod[v] > 0)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    mod[v * 2] += mod[v];
    mod[v * 2 + 1] += mod[v];
    mod[v] = 0;
    t[v] = min(t[v * 2] + mod[v * 2], t[v * 2 + 1] + mod[v * 2 + 1]);
    int res = firstzero(v * 2, tl, tm);
    if (res == -1)
      res = firstzero(v * 2 + 1, tm + 1, tr);
    return res;
  }
  int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
      return t[v] + mod[v];
    int tm = (tl + tr) / 2;
    mod[v * 2] += mod[v];
    mod[v * 2 + 1] += mod[v];
    mod[v] = 0;
    t[v] = min(t[v * 2] + mod[v * 2], t[v * 2 + 1] + mod[v * 2 + 1]);
    if (pos <= tm)
      return get(v * 2, tl, tm, pos);
    else
      return get(v * 2 + 1, tm + 1, tr, pos);
  }
  void upd(int l, int r, int val) {
    upd(1, 0, n - 1, l, r, val);
  }
  int firstzero() {
    return firstzero(1, 0, n - 1);
  }
  int get(int pos) {
    return get(1, 0, n - 1, pos);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> next(n);
    for (int i = 0; i < n; i++) {
      cin >> next[i];
      if (next[i] != -1)
        next[i]--;
    }
    segment_tree st(n);
    vector <vector <pii>> g(n);
    for (int i = 0; i < n; i++) {
      if (next[i] == -1)
        continue;
      st.upd(i + 1, next[i] - 1, 1);
      g[i].push_back({i + 1, next[i] - 1});
      if (next[i] != n) {
        g[next[i]].push_back({i, i});
        st.upd(i, i, 1);
      }
    }
    vector <int> arr;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      int pos = st.firstzero();
      if (pos == -1) {
        flag = false;
        break;
      }
      arr.push_back(pos);
      for (pii tmp : g[pos])
        st.upd(tmp.first, tmp.second, -1);
      st.upd(pos, pos, 1e9);
    }
    if (!flag) {
      cout << -1 << '\n';
      continue;
    }
    reverse(arr.begin(), arr.end());
    vector <int> p(n);
    for (int i = 0; i < n; i++)
      p[arr[i]] = i;
    for (auto &now : p)
      cout << now + 1 << ' ';
    cout << '\n';
  }
  return 0;
}