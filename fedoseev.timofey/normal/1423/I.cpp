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
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

#define int long long

struct SegmentTree {
  vector <int> t;
  vector <int> mod;
  void update(int v, int x) {
    t[v] |= x;
    mod[v] |= x;
  }
  void push(int v) {
    if (mod[v]) {
      update(2 * v + 1, mod[v]);
      update(2 * v + 2, mod[v]);
      mod[v] = 0;
    }
  }
  int n;
  void modify(int ql, int qr, int val, int l, int r, int v) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
      update(v, val);
    } else {
      push(v);
      int m = (l + r) >> 1; 
      modify(ql, qr, val, l, m, 2 * v + 1);
      modify(ql, qr, val, m + 1, r, 2 * v + 2);
    } 
  }
  int get(int ql, int qr, int l, int r, int v) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return t[v];
    push(v);
    int m = (l + r) >> 1;
    return get(ql, qr, l, m, 2 * v + 1) | get(ql, qr, m + 1, r, 2 * v + 2);
  }
  SegmentTree(int nn) {
    n = nn;
    t.resize(4 * n, 0);
    mod.resize(4 * n, 0);
  }
};
 
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int k, q;
  cin >> k >> q;
  vector <ll> l(q), r(q), v(q);
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i] >> v[i];
  }
  int x = (1 << k);
  SegmentTree low(x), high(x);
  for (int i = 0; i < q; ++i) {
    int high_l = (l[i] >> k);
    int low_l = (l[i] & (x - 1));
    int high_r = (r[i] >> k);
    int low_r = (r[i] & (x - 1));
    if (high_l == high_r) {
      high.modify(high_l, high_r, v[i], 0, x - 1, 0);
      low.modify(low_l, low_r, v[i], 0, x - 1, 0);
    } else {
      if (high_l + 1 <= high_r - 1) {
        high.modify(high_l + 1, high_r - 1, v[i], 0, x - 1, 0);
        low.modify(0, x - 1, v[i], 0, x - 1, 0);
      }
      high.modify(high_l, high_l, v[i], 0, x - 1, 0);
      low.modify(low_l, x - 1, v[i], 0, x - 1, 0);
      high.modify(high_r, high_r, v[i], 0, x - 1, 0);
      low.modify(0, low_r, v[i], 0, x - 1, 0);
    }
  } 
  vector <int> lt(x), ht(x);
  for (int i = 0; i < x; ++i) {
    lt[i] = low.get(i, i, 0, x - 1, 0);
    ht[i] = high.get(i, i, 0, x - 1, 0);
  } 

  for (int i = 0; i < q; ++i) {
    int high_l = (l[i] >> k);
    int low_l = (l[i] & (x - 1));
    int high_r = (r[i] >> k);
    int low_r = (r[i] & (x - 1));
    if (high_l == high_r) {
      int h = ht[high_l];
      int l = low.get(low_l, low_r, 0, x - 1, 0);
      if ((h & l) != v[i]) {
        cout << "impossible\n";
        return 0;
      }
    } else {
      int h = ht[high_l];
      int l = low.get(low_l, x - 1, 0, x - 1, 0);
      if ((h & l) != v[i]) {
        cout << "impossible\n";
        return 0;
      }
      h = ht[high_r];
      l = low.get(0, low_r, 0, x - 1, 0);
      if ((h & l) != v[i]) {
        cout << "impossible\n";
        return 0;
      }
      if (high_l + 1 <= high_r - 1) {
        h = high.get(high_l + 1, high_r - 1, 0, x - 1, 0);
        l = low.get(0, x - 1, 0, x - 1, 0);
        if ((h & l) != v[i]) {
          cout << "impossible\n";
          return 0;
        }
      } 
    }
  } 
  cout << "possible\n";
  for (int i = 0; i < x; ++i) {
    cout << lt[i] << '\n';
  }
  for (int i = 0; i < x; ++i) {
    cout << ht[i] << '\n';
  }
}