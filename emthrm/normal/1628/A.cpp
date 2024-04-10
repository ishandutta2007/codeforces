#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T>
struct SetManagedByInterval {
  using IntervalType = std::set<std::pair<T, T>>;
  IntervalType interval{
    {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},
    {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()},
  };

  bool contains(T x) const { return contains(x, x); }

  bool contains(T left, T right) const {
    typename IntervalType::const_iterator it = interval.lower_bound({left, left});
    if (left < it->first) it = std::prev(it);
    return it->first <= left && right <= it->second;
  }

  std::pair<typename IntervalType::const_iterator, bool> erase(T x) {
    typename IntervalType::const_iterator it = interval.lower_bound({x, x});
    if (it->first == x) {
      T right = it->second;
      it = interval.erase(it);
      if (x + 1 <= right) it = interval.emplace(x + 1, right).first;
      return {it, true};
    }
    it = std::prev(it);
    T left, right; std::tie(left, right) = *it;
    if (right < x) return {std::next(it), false};
    interval.erase(it);
    it = std::next(interval.emplace(left, x - 1).first);
    if (x + 1 <= right) it = interval.emplace(x + 1, right).first;
    return {it, true};
  }

  std::pair<typename IntervalType::const_iterator, T> erase(T left, T right) {
    assert(left <= right);
    typename IntervalType::const_iterator it = interval.lower_bound({left, left});
    T res = 0;
    for (; it->second <= right; it = interval.erase(it)) res += it->second - it->first + 1;
    if (it->first <= right) {
      res += right - it->first + 1;
      T r = it->second;
      interval.erase(it);
      it = interval.emplace(right + 1, r).first;
    }
    if (left < std::prev(it)->second) {
      it = std::prev(it);
      res += it->second - left + 1;
      T l = it->first;
      interval.erase(it);
      it = std::next(interval.emplace(l, left - 1).first);
    }
    return {it, res};
  }

  std::pair<typename IntervalType::const_iterator, bool> insert(T x) {
    typename IntervalType::const_iterator it = interval.lower_bound({x, x});
    if (it->first == x) return {it, false};
    if (x <= std::prev(it)->second) return {std::prev(it), false};
    T left = x, right = x;
    if (x + 1 == it->first) {
      right = it->second;
      it = interval.erase(it);
    }
    if (std::prev(it)->second == x - 1) {
      it = std::prev(it);
      left = it->first;
      interval.erase(it);
    }
    return {interval.emplace(left, right).first, true};
  }

  std::pair<typename IntervalType::const_iterator, T> insert(T left, T right) {
    assert(left <= right);
    typename IntervalType::const_iterator it = interval.lower_bound({left, left});
    if (left <= std::prev(it)->second) {
      it = std::prev(it);
      left = it->first;
    }
    T res = 0;
    if (left == it->first && right <= it->second) return {it, res};
    for (; it->second <= right; it = interval.erase(it)) res -= it->second - it->first + 1;
    if (it->first <= right) {
      res -= it->second - it->first + 1;
      right = it->second;
      it = interval.erase(it);
    }
    res += right - left + 1;
    if (right + 1 == it->first) {
      right = it->second;
      it = interval.erase(it);
    }
    if (std::prev(it)->second == left - 1) {
      it = std::prev(it);
      left = it->first;
      interval.erase(it);
    }
    return {interval.emplace(left, right).first, res};
  }

  T mex(T x = 0) const {
    auto it = interval.lower_bound({x, x});
    if (x <= std::prev(it)->second) it = std::prev(it);
    return x < it->first ? x : it->second + 1;
  }

  friend std::ostream &operator<<(std::ostream &os, const SetManagedByInterval &st) {
    if (st.interval.size() == 2) return os;
    auto it = next(st.interval.begin());
    while (true) {
      os << '[' << it->first << ", " << it->second << ']';
      it = next(it);
      if (next(it) == st.interval.end()) {
        break;
      } else {
        os << ' ';
      }
    }
    return os;
  }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  map<int, int> m;
  SetManagedByInterval<int> s;
  REP(i, n) {
    if (++m[a[i]] == 1) s.insert(a[i]);
  }
  vector<int> ans;
  for (int i = 0; i < n;) {
    const int mex = s.mex();
    ans.emplace_back(mex);
    SetManagedByInterval<int> tmp;
    do {
      tmp.insert(a[i]);
      --m[a[i]];
      if (m[a[i]] == 0) {
        m.erase(a[i]);
        s.erase(a[i]);
      }
      ++i;
    } while (tmp.mex() < mex);
  }
  const int b = ans.size();
  cout << b << '\n';
  REP(i, b) cout << ans[i] << " \n"[i + 1 == b];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}