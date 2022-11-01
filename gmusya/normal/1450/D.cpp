#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct answer_tree {
  int n;
  vector <int> t;
  answer_tree(int _n) {
    n = _n;
    t.resize(n << 2, 1);
  }
  void upd(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] = 0;
      return;
    }
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm));
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  void get(int v, int tl, int tr, vector <int> &ans) {
    if (tl == tr) {
      ans[tl] = t[v];
      return;
    }
    t[v * 2] = min(t[v * 2], t[v]);
    t[v * 2 + 1] = min(t[v * 2 + 1], t[v]);
    int tm = (tl + tr) / 2;
    get(v * 2, tl, tm, ans);
    get(v * 2 + 1, tm + 1, tr, ans);
  }
  void upd(int l, int r) {
    upd(1, 0, n - 1, l, r);
  }
  void get(vector <int> &ans) {
    get(1, 0, n - 1, ans);
  }
};

struct segment_tree {
  int n;
  vector <int> t;
  segment_tree(int _n) {
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
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  int firstleft(int v, int tl, int tr, int pos, int val) {
    if (tl > pos)
      return -1;
    if (t[v] >= val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = firstleft(v * 2 + 1, tm + 1, tr, pos, val);
    if (res == -1)
      res = firstleft(v * 2, tl, tm, pos, val);
    return res;
  }
  int firstright(int v, int tl, int tr, int pos, int val) {
    if (tr < pos)
      return -1;
    if (t[v] >= val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = firstright(v * 2, tl, tm, pos, val);
    if (res == -1)
      res = firstright(v * 2 + 1, tm + 1, tr, pos, val);
    return res;
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  int firstleft(int pos, int val) {
    return firstleft(1, 0, n - 1, pos, val);
  }
  int firstright(int pos, int val) {
    return firstright(1, 0, n - 1, pos, val);
  }
};

int mex(vector <int> a) {
  sort(a.begin(), a.end());
  int last = 1;
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] > last)
      break;
    if (a[i] == last)
      last++;
  }
  return last;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    answer_tree ans(n + 1);
    segment_tree st(n);
    st.build(a);
    vector <vector <int>> val(n + 1);
    for (int i = 0; i < n; i++) {
      int l = st.firstleft(i, a[i]);
      int r = st.firstright(i + 1, a[i] + 1);
      if (l == -1)
        l = 0;
      else
        l++;
      if (r == -1)
        r = n - 1;
      else
        r--;
      if (l != i && r != i)
        ans.upd(2, r - l);
      val[a[i]].push_back(r - l + 1);
    }
    for (int i = 0; i <= n; i++) {
      if ((int)val[i].size() < 2)
        continue;
      sort(val[i].begin(), val[i].end());
      int x = val[i][(int)val[i].size() - 2];
      ans.upd(1, x);
    }
    vector <int> res(n + 1);
    ans.get(res);
    int mx = mex(a);
    for (int i = 1; i <= n; i++)
      if (i <= n + 1 - mx)
        res[i] = 0;
    for (int i = 1; i <= n; i++)
      cout << res[i];
    cout << '\n';
  }
  return 0;
}