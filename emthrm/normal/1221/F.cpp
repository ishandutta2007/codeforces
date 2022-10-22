#include <algorithm>
#include <bitset>
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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
template <typename Monoid>
struct RMQandRAQ {
  RMQandRAQ(int sz, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    init(sz);
    dat.assign((n << 1) - 1, DEFAULT);
  }

  RMQandRAQ(const vector<Monoid> &a, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void add(int a, int b, const Monoid &value) { add(a, b, value, 0, 0, n); }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  Monoid operator[](const int idx) { return query(idx, idx + 1); }

  int find(int a, int b, const Monoid &value) { return find(a, b, value, 0, 0, n); }

private:
  int n = 1;
  const Monoid UNITY, DEFAULT;
  vector<Monoid> dat, lazy;

  void init(int sz) {
    while (n < sz) n <<= 1;
    lazy.assign((n << 1) - 1, DEFAULT);
  }

  inline void evaluate(int node) {
    if (lazy[node] != DEFAULT) {
      dat[node] += lazy[node];
      if (node < n - 1) {
        lazy[(node << 1) + 1] += lazy[node];
        lazy[(node << 1) + 2] += lazy[node];
      }
      lazy[node] = DEFAULT;
    }
  }

  void add(int a, int b, const Monoid &value, int node, int left, int right) {
    evaluate(node);
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      lazy[node] += value;
      evaluate(node);
    } else {
      add(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
      add(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
      dat[node] = max(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b, int node, int left, int right) {
    evaluate(node);
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return max(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, const Monoid &value, int node, int left, int right) {
    evaluate(node);
    if (dat[node] < value || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> x(n), y(n), c(n); REP(i, n) cin >> x[i] >> y[i] >> c[i];
  vector<int> see{0};
  REP(i, n) {
    see.emplace_back(x[i]);
    see.emplace_back(y[i]);
  }
  sort(ALL(see));
  see.erase(unique(ALL(see)), see.end());
  int sz = see.size();
  vector<vector<int> > kesu(sz);
  REP(i, n) kesu[lower_bound(ALL(see), min(x[i], y[i])) - see.begin()].emplace_back(i);
  // REP(i, sz) {
  //   for (int e : kesu[i]) cout << e << ' ';
  //   cout << '\n';
  // }
  RMQandRAQ<long long> rmq(sz, -LINF);
  REP(i, n) {
    int idx = lower_bound(ALL(see), max(x[i], y[i])) - see.begin();
    rmq.add(idx, sz, c[i]);
  }
  REP(i, sz) rmq.add(i, i + 1, -see[i]);
  long long ans = -LINF;
  int x1, y1, x2, y2;
  REP(i, sz) {
    // REP(i, sz) cout << rmq[i] << ' ';
    // cout << '\n';
    long long now = rmq.query(i, sz);
    if (now > ans) {
      ans = now;
      x1 = y1 = see[i];
      int idx = rmq.find(i, sz, now);
      x2 = y2 = see[idx];
    }
    for (int e : kesu[i]) {
      int idx = lower_bound(ALL(see), max(x[e], y[e])) - see.begin();
      rmq.add(idx, sz, -c[e]);
    }
    if (i + 1 < sz) rmq.add(i + 1, sz, see[i + 1] - see[i]);
  }
  if (ans < 0) {
    ans = 0;
    x1 = y1 = x2 = y2 = 2000000000;
  }
  cout << ans << '\n' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
  return 0;
}