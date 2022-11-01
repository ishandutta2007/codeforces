#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
  int left(int v, int tl, int tr, int pos, int val) {
    if (tl > pos)
      return -1;
    if (t[v] > val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = left(v * 2 + 1, tm + 1, tr, pos, val);
    if (res == -1)
      res = left(v * 2, tl, tm, pos, val);
    return res;
  }
  int right(int v, int tl, int tr, int pos, int val) {
    if (tr < pos)
      return -1;
    if (t[v] > val)
      return -1;
    if (tl == tr)
      return tl;
    int tm = (tl + tr) / 2;
    int res = right(v * 2, tl, tm, pos, val);
    if (res == -1)
      res = right(v * 2 + 1, tm + 1, tr, pos, val);
    return res;
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  int left(int pos, int val) {
    return left(1, 0, n - 1, pos, val);
  }
  int right(int pos, int val) {
    return right(1, 0, n - 1, pos, val);
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
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector <int> pre(n), suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
      pre[i] = max(pre[i - 1], a[i]);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
      suf[i] = max(suf[i + 1], a[i]);
    segment_tree st(n);
    st.build(a);
    bool flag = false;
    for (int leftmin = 1; leftmin + 1 < n; leftmin++) {
      int l2 = st.left(leftmin - 1, a[leftmin]);
      if (l2 == -1)
        l2 = 0;
      else
        l2++;
      int r2 = st.right(leftmin, a[leftmin] - 1);
      if (r2 == -1)
        r2 = n - 1;
      else
        r2--;
      int l1 = lower_bound(pre.begin(), pre.end(), a[leftmin]) - pre.begin();
      int r1 = upper_bound(pre.begin(), pre.end(), a[leftmin]) - pre.begin() - 1;
      int l3 = lower_bound(suf.begin(), suf.end(), a[leftmin], greater<int>()) - suf.begin();
      int r3 = upper_bound(suf.begin(), suf.end(), a[leftmin], greater<int>()) - suf.begin() - 1;
      r1 = min(r1, leftmin - 1);
      l3 = max(l3, leftmin + 1);
      if (l1 > r1 || l3 > r3)
        continue;
      if (pre[l1] != a[leftmin] || suf[l3] != a[leftmin])
        continue;
      if (l1 >= leftmin)
        continue;
      if (r1 + 1 < l2)
        continue;
      if (r3 <= leftmin)
        continue;
      if (l3 - 1 > r2)
        continue;
      flag = true;
      cout << "YES\n";
      int x = min(leftmin - 1, r1) + 1;
      int z = n - max(leftmin + 1, l3);
      int y = n - x - z;
      cout << x << ' ' << y << ' ' << z << '\n';
      break;
    }
    if (!flag)
      cout << "NO\n";
  }
  return 0;
}