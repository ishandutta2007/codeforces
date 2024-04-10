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

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  const int MAX = 1000000;
  int n, m; cin >> n >> m;
  RMQandRAQ<int> rmq(MAX, INF);
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    rmq.add(MAX - a[i], MAX, -1);
  }
  vector<int> b(m);
  REP(i, m) {
    cin >> b[i];
    rmq.add(MAX - b[i], MAX, 1);
  }
  int q; cin >> q;
  while (q--) {
    int query, i, x; cin >> query >> i >> x; --i;
    if (query == 1) { // a
      rmq.add(MAX - a[i], MAX, 1);
      a[i] = x;
      rmq.add(MAX - a[i], MAX, -1);
    } else { // b
      rmq.add(MAX - b[i], MAX, -1);
      b[i] = x;
      rmq.add(MAX - b[i], MAX, 1);
    }
    if (rmq.query(0, MAX) >= 0) {
      cout << -1 << '\n';
      continue;
    }
    int left = -1, right = MAX - 1;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      (rmq.query(0, mid + 1) < 0 ? right : left) = mid;
    }
    cout << MAX - right << '\n';
    // FOR(i, MAX - 20, MAX) cout << rmq.query(i, i + 1) << ' ';
    // cout << '\n';
  }
  return 0;
}