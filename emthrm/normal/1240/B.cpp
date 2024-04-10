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
#include <stack>
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
struct RMQ {
  RMQ(int sz, const Monoid &UNITY) : UNITY(UNITY) {
    init(sz);
    dat.assign((n << 1) - 1, UNITY);
  }

  RMQ(const vector<Monoid> &a, const Monoid &UNITY) : UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = min(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void update(int node, const Monoid &value) {
    node += n - 1;
    dat[node] = value;
    while (node > 0) {
      node = (node - 1) >> 1;
      dat[node] = min(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  int find(int a, int b, const Monoid &value) { return find(a, b, value, 0, 0, n); }

  Monoid operator[](const int idx) const { return dat[idx + n - 1]; }

private:
  int n = 1;
  const Monoid UNITY;
  vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }

  Monoid query(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return min(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, const Monoid &value, int node, int left, int right) {
    if (dat[node] > value || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<int> a(n), comp(n);
    REP(i, n) {
      cin >> a[i];
      comp[i] = a[i];
    }
    sort(ALL(comp));
    comp.erase(unique(ALL(comp)), comp.end());
    int m = comp.size();
    if (m == 1) {
      cout << 0 << '\n';
      continue;
    }
    vector<vector<int> > idx(m);
    REP(i, n) {
      a[i] = lower_bound(ALL(comp), a[i]) - comp.begin();
      idx[a[i]].emplace_back(i);
    }
    // REP(i, m) cout << idx[i].size() << ' ';
    // cout << endl;
    RMQ<int> rmq(a, INF);
    int to_right = 0;
    while (to_right < m) {
      int mn = rmq.query(idx[to_right].front() + 1, n);
      if (mn < to_right) break;
      ++to_right;
    }
    int ans = m - to_right;
    REP(i, m) {
      if (to_right == i) ++to_right;
      for (int e : idx[i]) rmq.update(e, INF);
      while (to_right < m) {
        int mn = rmq.query(idx[to_right].front() + 1, n);
        if (mn < to_right) break;
        ++to_right;
      }
      ans = min(ans, i + 1 + m - to_right);
    }
    cout << ans << '\n';
  }
  return 0;
}