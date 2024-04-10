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
#include <queue>
#include <random>
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
struct RMQandRAQ1 {
  RMQandRAQ1(int sz, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    init(sz);
    dat.assign((n << 1) - 1, DEFAULT);
  }

  RMQandRAQ1(const vector<Monoid> &a, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = min(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void add(int a, int b, Monoid value) { add(a, b, value, 0, 0, n); }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  int find(int a, int b, Monoid value) { return find(a, b, value, 0, 0, n); }

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

  void add(int a, int b, Monoid value, int node, int left, int right) {
    evaluate(node);
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      lazy[node] += value;
      evaluate(node);
    } else {
      add(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
      add(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
      dat[node] = min(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b, int node, int left, int right) {
    evaluate(node);
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return min(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, Monoid value, int node, int left, int right) {
    evaluate(node);
    if (dat[node] > value || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
  }
};

template <typename Monoid>
struct RMQandRAQ2 {
  RMQandRAQ2(int sz, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    init(sz);
    dat.assign((n << 1) - 1, DEFAULT);
  }

  RMQandRAQ2(const vector<Monoid> &a, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void add(int a, int b, Monoid value) { add(a, b, value, 0, 0, n); }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  int find(int a, int b, Monoid value) { return find(a, b, value, 0, 0, n); }

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

  void add(int a, int b, Monoid value, int node, int left, int right) {
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

  // int find(int a, int b, Monoid value, int node, int left, int right) {
  //   evaluate(node);
  //   if (dat[node] > value || right <= a || b <= left) return -1;
  //   if (right - left == 1) return node - (n - 1);
  //   int res_l = find(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
  //   if (res_l != -1) return res_l;
  //   return find(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
  // }
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  map<char, int> c;
  c['S'] = 0; c['A'] = 1; c['W'] = 2; c['D'] = 3;
  while (t--) {
    string s; cin >> s;
    int x = 0, y = 0;
    vector<long long> xi{0}, yi{0};
    REP(i, s.length()) {
      x += dx[c[s[i]]];
      xi.emplace_back(x);
      y += dy[c[s[i]]];
      yi.emplace_back(y);
    }
    int n = xi.size();
    RMQandRAQ1<long long> mn_x(xi, LINF), mn_y(yi, LINF);
    RMQandRAQ2<long long> mx_x(xi, -LINF), mx_y(yi, -LINF);
    long long ans = (mx_x.query(0, n) - mn_x.query(0, n) + 1) * (mx_y.query(0, n) - mn_y.query(0, n) + 1);
    REP(i, n) {
      long long now = xi[i];
      mn_x.add(i, n, 1);
      mx_x.add(i, n, 1);
      ans = min(ans, (max(mx_x.query(0, n), now) - min(mn_x.query(0, n), now) + 1) * (mx_y.query(0, n) - mn_y.query(0, n) + 1));
      mn_x.add(i, n, -2);
      mx_x.add(i, n, -2);
      ans = min(ans, (max(mx_x.query(0, n), now) - min(mn_x.query(0, n), now) + 1) * (mx_y.query(0, n) - mn_y.query(0, n) + 1));
      mn_x.add(i, n, 1);
      mx_x.add(i, n, 1);
    }
    REP(i, n - 1) {
      long long now = yi[i];
      mn_y.add(i, n, 1);
      mx_y.add(i, n, 1);
      ans = min(ans, (mx_x.query(0, n) - mn_x.query(0, n) + 1) * (max(mx_y.query(0, n), now) - min(mn_y.query(0, n), now) + 1));
      mn_y.add(i, n, -2);
      mx_y.add(i, n, -2);
      ans = min(ans, (mx_x.query(0, n) - mn_x.query(0, n) + 1) * (max(mx_y.query(0, n), now) - min(mn_y.query(0, n), now) + 1));
      mn_y.add(i, n, 1);
      mx_y.add(i, n, 1);
    }
    cout << ans << '\n';
  }
  return 0;
}