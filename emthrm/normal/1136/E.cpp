#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
template <typename Monoid>
struct RSQandRUQ {
  RSQandRUQ(int sz_) { init(sz_); }

  RSQandRUQ(const vector<Monoid> &seq) {
    int seq_sz = seq.size();
    init(seq_sz);
    REP(i, seq_sz) dat[sz - 1 + i] = seq[i];
    for (int i = sz - 2; i >= 0; --i) dat[i] = dat[(i << 1) + 1] + dat[(i << 1) + 2];
  }

  void update(int a, int b, Monoid value) { update(a, b, value, 0, 0, sz); }

  Monoid sum(int a, int b) { return sum(a, b, 0, 0, sz); }

  inline Monoid operator [] (const int idx) { return sum(idx, idx + 1); }

private:
  int sz = 1;
  vector<Monoid> dat, lazy;
  vector<bool> need_to_be_eval;

  void init(int sz_) {
    while (sz < sz_) sz <<= 1;
    dat.assign((sz << 1) - 1, 0);
    lazy.assign((sz << 1) - 1, 0);
    need_to_be_eval.assign((sz << 1) - 1, false);
  }

  inline void evaluate(int node, int left, int right) {
    if (need_to_be_eval[node]) {
      dat[node] = (right - left) * lazy[node];
      if (node < sz - 1) {
        lazy[(node << 1) + 1] = lazy[(node << 1) + 2] = lazy[node];
        need_to_be_eval[(node << 1) + 1] = need_to_be_eval[(node << 1) + 2] = true;
      }
      lazy[node] = 0;
      need_to_be_eval[node] = false;
    }
  }

  void update(int a, int b, Monoid value, int node, int left, int right) {
    evaluate(node, left, right);
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      lazy[node] = value;
      need_to_be_eval[node] = true;
      evaluate(node, left, right);
    } else {
      update(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
      update(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
      dat[node] = dat[(node << 1) + 1] + dat[(node << 1) + 2];
    }
  }

  Monoid sum(int a, int b, int node, int left, int right) {
    evaluate(node, left, right);
    if (right <= a || b <= left) return 0;
    if (a <= left && right <= b) return dat[node];
    return sum(a, b, (node << 1) + 1, left, (left + right) >> 1) + sum(a, b, (node << 1) + 2, (left + right) >> 1, right);
  }
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<long long> a(n); REP(i, n) cin >> a[i];
  vector<long long> k(n, 0); FOR(i, 1, n) cin >> k[i];
  FOR(i, 1, n) k[i] += k[i - 1];
  REP(i, n) a[i] -= k[i];
  FOR(i, 1, n) k[i] += k[i - 1];
  RSQandRUQ<long long> rsq(a);
  int q; cin >> q;
  while (q--) {
    char c; cin >> c;
    if (c == '+') {
      int i; long long x; cin >> i >> x; --i;
      long long tmp = rsq.sum(i, i + 1) + x;
      int lb = i, ub = n;
      while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        (rsq.sum(mid, mid + 1) <= tmp ? lb : ub) = mid;
      }
      rsq.update(i, lb + 1, tmp);
    } else {
      int l, r; cin >> l >> r; --l; --r;
      cout << rsq.sum(l, r + 1) + k[r] - (l > 0 ? k[l - 1] : 0) << '\n';
    }
  }
  return 0;
}