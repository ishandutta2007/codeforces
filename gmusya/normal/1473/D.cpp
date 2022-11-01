#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;

const int INF = 1e9;

struct segment_tree {
  int n;
  vector <int> mi, ma;
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
  pii get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return {INF, -INF};
    if (l == tl && r == tr)
      return {mi[v], ma[v]};
    int tm = (tl + tr) / 2;
    pii x = get(v * 2, tl, tm, l, min(r, tm));
    pii y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return {min(x.fi, y.fi), max(x.se, y.se)};
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  pii get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector <int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      if (c == '+')
        arr[i] = arr[i - 1] + 1;
      else
        arr[i] = arr[i - 1] - 1;
    }
    segment_tree st(n + 1);
    st.build(arr);
    while (q--) {
      int l, r;
      cin >> l >> r;
      pii a = st.get(0, l - 1);
      pii b = st.get(r, n);
      b = {b.fi - arr[r] + arr[l - 1], b.se - arr[r] + arr[l - 1]};
      pii c = {min(a.fi, b.fi), max(a.se, b.se)};
      cout << c.se - c.fi + 1 << '\n';
    }
  }
  return 0;
}