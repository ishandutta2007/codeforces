#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

struct segment_tree {
  int n;
  vector <int> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void build(int v, int tl, int tr, vi &a) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return t[v];
    int tm = (tl + tr) / 2;
    int x = get(v * 2, tl, tm, l, min(r, tm));
    int y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return max(x, y);
  }
  void build(vi &a) {
    build(1, 0, n - 1, a);
  }
  int get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    a.push_back(a[i]);
  for (int i = 0; i < n; i++)
    a.push_back(a[i]);
  segment_tree st(3 * n);
  st.build(a);
  int r = 0;
  vi ans(n);
  for (int l = 0; l < n; l++) {
    while (r < 3 * n && st.get(l, r) <= 2 * a[r])
      r++;
    ans[l] = r - l;
  }
  if (ans[0] == 3 * n)
    for (int i = 0; i < n; i++)
      ans[i] = -1;
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  return 0;
}