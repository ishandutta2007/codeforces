#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <cassert>
#include <complex>
#include <functional>
 
using namespace std;
 
typedef long long ll;

struct SegmentTree {
  int n, zero;
  vector <int> t;
  function <int(int, int)> f;

  void build(const vector <int> &a) {
    for (int i = 0; i < n; ++i) {
      t[n + i] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      t[i] = f(t[i << 1], t[i << 1 | 1]);
    }
  }

  void modify(int x, int val) {
    x += n;
    for (t[x] = f(t[x], val); x > 1; x >>= 1) {
      t[x >> 1] = f(t[x], t[x ^ 1]);
    }
  }

  int get(int l, int r) {
    ++r;
    int res = zero;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = f(res, t[l++]);
      if (r & 1) res = f(res, t[--r]);
    }
    return res;
  }

  SegmentTree(int _n, int _zero, function <int(int, int)> _f) {
    n = _n;
    zero = _zero;
    f = _f;
    t.resize(2 * n, zero);
  }
};

const int Inf = 1e9 + 7;

bool check(int n, vector <int> l1, vector <int> r1, vector <int> l2, vector <int> r2) {
  vector <int> c;
  for (int i = 0; i < n; ++i) {
    c.push_back(l1[i]);
    c.push_back(r1[i]);
    c.push_back(l2[i]);
    c.push_back(r2[i]);
  }
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(), c.end()) - c.begin());
  for (int i = 0; i < n; ++i) {
    l1[i] = lower_bound(c.begin(), c.end(), l1[i]) - c.begin();
    r1[i] = lower_bound(c.begin(), c.end(), r1[i]) - c.begin();
    l2[i] = lower_bound(c.begin(), c.end(), l2[i]) - c.begin();
    r2[i] = lower_bound(c.begin(), c.end(), r2[i]) - c.begin();
  }
  int m = c.size();
  SegmentTree lmax(m, -Inf, [&] (int a, int b) {
      return max(a, b);
  });
  SegmentTree rmin(m, Inf, [&] (int a, int b) {
      return min(a, b);
  });
  for (int i = 0; i < n; ++i) {
    lmax.modify(l1[i], l2[i]);
    lmax.modify(r1[i], l2[i]);
    rmin.modify(l1[i], r2[i]);
    rmin.modify(r1[i], r2[i]);
  }
  for (int i = 0; i < n; ++i) {
    int lm = lmax.get(l1[i], r1[i]);
    int rm = rmin.get(l1[i], r1[i]);
    if (lm > r2[i]) return false;
    if (rm < l2[i]) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> l1(n), r1(n), l2(n), r2(n);
  for (int i = 0; i < n; ++i) {
    cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
  }
  if (check(n, l1, r1, l2, r2) && check(n, l2, r2, l1, r1)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}