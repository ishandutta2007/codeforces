#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T>
struct CHT {
  using Line = pair<T, T>;

  CHT(bool is_minimized = true) : is_minimized(is_minimized) {}

  void add(T a, T b) {
    Line now(a, b);
    if (deq.empty()) {
      deq.emplace_back(now);
    } else if (deq.back().first <= a) {
      if (deq.back().first == a) {
        if (is_minimized) {
          if (b >= deq.back().second) return;
          deq.pop_back();
        } else {
          if (b <= deq.back().second) return;
          deq.pop_back();
        }
      }
      while (deq.size() >= 2 && !is_necessary(deq[deq.size() - 2], deq.back(), now)) deq.pop_back();
      deq.emplace_back(now);
    } else {
      if (deq.front().first == a) {
        if (is_minimized) {
          if (b >= deq.front().second) return;
          deq.pop_front();
        } else {
          if (b <= deq.front().second) return;
          deq.pop_front();
        }
      }
      while (deq.size() >= 2 && !is_necessary(now, deq[0], deq[1])) deq.pop_front();
      deq.emplace_front(now);
    }
  }

  T query(T x) const {
    int lb = -1, ub = deq.size() - 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      if (is_minimized) {
        (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;
      } else {
        (f(deq[mid], x) > f(deq[mid + 1], x) ? ub : lb) = mid;
      }
    }
    return f(deq[ub], x);
  }

  T monotone_inc_query(T x) {
    if (is_minimized) {
      while (deq.size() >= 2 && f(deq[deq.size() - 2], x) <= f(deq.back(), x)) deq.pop_back();
      return f(deq.back(), x);
    } else {
      while (deq.size() >= 2 && f(deq[0], x) <= f(deq[1], x)) deq.pop_front();
      return f(deq.front(), x);
    }
  }

  T monotone_dec_query(T x) {
    if (is_minimized) {
      while (deq.size() >= 2 && f(deq[0], x) >= f(deq[1], x)) deq.pop_front();
      return f(deq.front(), x);
    } else {
      while (deq.size() >= 2 && f(deq[deq.size() - 2], x) >= f(deq.back(), x)) deq.pop_back();
      return f(deq.back(), x);
    }
  }

private:
  bool is_minimized;
  deque<Line> deq;

  using Real = long double;
  bool is_necessary(const Line &l1, const Line &l2, const Line &l3) const {
    Real lhs = static_cast<Real>(l3.second - l2.second) / (l2.first - l3.first);
    Real rhs = static_cast<Real>(l2.second - l1.second) / (l1.first - l2.first);
    return is_minimized ? lhs < rhs : lhs > rhs;
    // T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;
    // if (lhs_den < 0) {
    //   lhs_num = -lhs_num;
    //   lhs_den = -lhs_den;
    // }
    // T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;
    // if (rhs_den < 0) {
    //   rhs_num = -rhs_num;
    //   rhs_den = -rhs_den;
    // }
    // return is_minimized ? lhs_num * rhs_den < rhs_num * lhs_den : lhs_num * rhs_den > rhs_num * lhs_den;
  }

  T f(const Line &l, T x) const { return l.first * x + l.second; }
};

int main() {
  int n; cin >> n;
  vector<int> xl(n), xr(n), y(n); REP(i, n) cin >> xl[i] >> xr[i] >> y[i];
  vector<int> idx(n);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int a, int b) { return xl[a] == xl[b] ? xr[a] < xr[b] : xl[a] < xl[b]; });
  bool shortest = true;
  FOR(i, 1, n) shortest &= xr[idx[i - 1]] <= xl[idx[i]];
  using ld = long double;
  ld ans = LINF;
  if (shortest) ans = xr[idx[n - 1]] - xl[idx[0]];
  sort(ALL(idx), [&](int a, int b) { return y[a] < y[b]; });
  CHT<ld> l(true), r(false);
  REP(i, n) {
    l.add(-y[idx[i]], xl[idx[i]]);
    r.add(-y[idx[i]], xr[idx[i]]);
  }
  vector<pair<ld, ld>> seg;
  REP(i, n) REP(j, n) {
    if (y[i] > y[j]) {
      ld l = xl[j] == xr[i] ? LINF : 1.0L * (y[i] - y[j]) / (xr[i] - xl[j]);
      ld r = xl[i] == xr[j] ? LINF : 1.0L * (y[i] - y[j]) / (xl[i] - xr[j]);
      seg.emplace_back(l, r);
    }
  }
  function<bool(ld, ld)> f = [](ld a, ld b) {
    return a * b < 0 ? a > 0 : a < b;
  };
  using P = pair<ld, ld>;
  sort(ALL(seg), [&](P a, P b) { return a.first == b.first ? f(a.second, b.second) : f(a.first, b.first); });
  // for (auto [l, r] : seg) cout << l * 180 / M_PI << ' ' << r * 180 / M_PI << '\n';
  function<void(ld)> solve = [&](ld inv) {
    if (abs(inv - LINF) < 1) return;
    ld x = 1 / inv;
    chmin(ans, r.query(x) - l.query(x));
  };
  for (int i = 0; i < seg.size();) {
    int j = i + 1;
    ld mx = seg[i].second;
    while (j < seg.size() && f(seg[j].first, mx)) {
      if (f(mx, seg[j].second)) mx = seg[j].second;
      ++j;
    }
    solve(seg[i].first);
    solve(mx);
    i = j;
  }
  cout << ans << '\n';
  return 0;
}