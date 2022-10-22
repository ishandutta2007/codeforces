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
struct RSQ {
  RSQ(int sz, const Monoid &UNITY = 0) : UNITY(UNITY) {
    init(sz);
    dat.assign((n << 1) - 1, UNITY);
  }

  RSQ(const vector<Monoid> &a, const Monoid &UNITY = 0) : UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = dat[(i << 1) + 1] + dat[(i << 1) + 2];
  }

  void add(int node, Monoid value) {
    node += n - 1;
    dat[node] += value;
    while (node > 0) {
      node = (node - 1) >> 1;
      dat[node] = dat[(node << 1) + 1] + dat[(node << 1) + 2];
    }
  }

  Monoid sum(int a, int b) { return sum(a, b, 0, 0, n); }

  int find(int a, int b, Monoid value) { return find(a, b, value, 0, 0, n); }

  inline Monoid operator[](const int idx) const { return dat[idx + n - 1]; }

private:
  int n = 1;
  const Monoid UNITY;
  vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }

  Monoid sum(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return sum(a, b, (node << 1) + 1, left, (left + right) >> 1) + sum(a, b, (node << 1) + 2, (left + right) >> 1, right);
  }

  int find(int a, int b, Monoid value, int node, int left, int right) {
    if (dat[node] < value || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
    if (res_l != -1) return res_l;
    return find(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
  }
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> x1(n), y1(n), x2(n), y2(n), x, y;
  REP(i, n) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    if (x1[i] > x2[i]) swap(x1[i], x2[i]);
    if (y1[i] > y2[i]) swap(y1[i], y2[i]);
    x.emplace_back(x1[i]);
    x.emplace_back(x2[i]);
    y.emplace_back(y1[i]);
    y.emplace_back(y2[i]);
  }
  sort(ALL(x));
  x.erase(unique(ALL(x)), x.end());
  sort(ALL(y));
  y.erase(unique(ALL(y)), y.end());
  int nx = x.size(), ny = y.size();
  REP(i, n) {
    x1[i] = lower_bound(ALL(x), x1[i]) - x.begin();
    y1[i] = lower_bound(ALL(y), y1[i]) - y.begin();
    x2[i] = lower_bound(ALL(x), x2[i]) - x.begin();
    y2[i] = lower_bound(ALL(y), y2[i]) - y.begin();
  }
  vector<vector<int> > minus(nx);
  vector<vector<pair<int, int> > > plus(nx);
  REP(i, n) if (y1[i] == y2[i]) {
    plus[x1[i]].emplace_back(y1[i], x2[i]);
    minus[x2[i]].emplace_back(y1[i]);
  }
  vector<vector<int> > shita(nx), ue(nx);
  REP(i, n) if (x1[i] == x2[i]) {
    shita[x1[i]].emplace_back(y1[i]);
    ue[x1[i]].emplace_back(y2[i]);
  }
  long long ans = 0;
  vector<int> memo(ny, 0);
  vector<vector<int> > hiku(nx);
  REP(i, nx) {
    for (int e : minus[i]) --memo[e];
    for (auto e : plus[i]) {
      ++memo[e.first];
      hiku[e.second].emplace_back(e.first);
    }
    REP(p, shita[i].size()) {
      RSQ<int> rsq(memo);
      vector<vector<int> > hikubeki(hiku);
      FOR(j, i + 1, nx) {
        // REP(k, ny) cout << rsq[k] << ' ';
        // cout << '\n';
        REP(q, shita[j].size()) {
          int l = max(shita[i][p], shita[j][q]), r = min(ue[i][p], ue[j][q]);
          // cout << l << ' ' << r << '\n';
          long long tmp = (l <= r ? rsq.sum(l, r + 1) : 0);
          if (tmp >= 2) ans += tmp * (tmp - 1) / 2;
        }
        for (int e : hikubeki[j]) rsq.add(e, -1);
      }
      // cout << ans << '\n';
    }
  }
  cout << ans << '\n';
  return 0;
}