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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T>
struct IntervalManagedBySet {
  using IntervalType = std::set<std::pair<T, T>>;
  IntervalType intervals{
      {std::numeric_limits<T>::lowest(), std::numeric_limits<T>::lowest()},
      {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()}};

  IntervalManagedBySet() = default;

  bool contains(const T x) const { return contains(x, x); }

  bool contains(const T left, const T right) const {
    typename IntervalType::const_iterator it =
        intervals.lower_bound({left, left});
    if (left < it->first) it = std::prev(it);
    return it->first <= left && right <= it->second;
  }

  std::pair<typename IntervalType::const_iterator, bool> erase(const T x) {
    typename IntervalType::const_iterator it = intervals.lower_bound({x, x});
    if (it->first == x) {
      const T right = it->second;
      it = intervals.erase(it);
      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;
    } else {
      it = std::prev(it);
      T left, right;
      std::tie(left, right) = *it;
      if (right < x) return {std::next(it), false};
      intervals.erase(it);
      it = std::next(intervals.emplace(left, x - 1).first);
      if (x + 1 <= right) it = intervals.emplace(x + 1, right).first;
    }
    return {it, true};
  }

  std::pair<typename IntervalType::const_iterator, T> erase(
      const T left, const T right) {
    assert(left <= right);
    typename IntervalType::const_iterator it =
        intervals.lower_bound({left, left});
    T res = 0;
    for (; it->second <= right; it = intervals.erase(it)) {
      res += it->second - it->first + 1;
    }
    if (it->first <= right) {
      res += right - it->first + 1;
      const T r = it->second;
      intervals.erase(it);
      it = intervals.emplace(right + 1, r).first;
    }
    if (left < std::prev(it)->second) {
      it = std::prev(it);
      res += it->second - left + 1;
      const T l = it->first;
      intervals.erase(it);
      it = std::next(intervals.emplace(l, left - 1).first);
    }
    return {it, res};
  }

  std::pair<typename IntervalType::const_iterator, bool> insert(const T x) {
    typename IntervalType::const_iterator it = intervals.lower_bound({x, x});
    if (it->first == x) return {it, false};
    if (x <= std::prev(it)->second) return {std::prev(it), false};
    T left = x, right = x;
    if (x + 1 == it->first) {
      right = it->second;
      it = intervals.erase(it);
    }
    if (std::prev(it)->second == x - 1) {
      it = std::prev(it);
      left = it->first;
      intervals.erase(it);
    }
    return {intervals.emplace(left, right).first, true};
  }

  std::pair<typename IntervalType::const_iterator, T> insert(T left, T right) {
    assert(left <= right);
    typename IntervalType::const_iterator it =
        intervals.lower_bound({left, left});
    if (left <= std::prev(it)->second) {
      it = std::prev(it);
      left = it->first;
    }
    T res = 0;
    if (left == it->first && right <= it->second) return {it, res};
    for (; it->second <= right; it = intervals.erase(it)) {
      res -= it->second - it->first + 1;
    }
    if (it->first <= right) {
      res -= it->second - it->first + 1;
      right = it->second;
      it = intervals.erase(it);
    }
    res += right - left + 1;
    if (right + 1 == it->first) {
      right = it->second;
      it = intervals.erase(it);
    }
    if (std::prev(it)->second == left - 1) {
      it = std::prev(it);
      left = it->first;
      intervals.erase(it);
    }
    return {intervals.emplace(left, right).first, res};
  }

  T mex(const T x = 0) const {
    auto it = intervals.lower_bound({x, x});
    if (x <= std::prev(it)->second) it = std::prev(it);
    return x < it->first ? x : it->second + 1;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const IntervalManagedBySet& x) {
    if (x.intervals.size() == 2) return os;
    auto it = next(x.intervals.begin());
    while (true) {
      os << '[' << it->first << ", " << it->second << ']';
      it = next(it);
      if (next(it) == x.intervals.end()) break;
      os << ' ';
    }
    return os;
  }
};

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> occur;
  while (n--) {
    int a; cin >> a;
    ++occur[a];
  }
  IntervalManagedBySet<int> set;
  for (const auto [num, oc] : occur) {
    if (oc >= k) set.insert(num);
  }
  int l = 0, r = -1;
  for (auto it = next(set.intervals.begin()); next(it) != set.intervals.end(); it = next(it)) {
    if (it->second - it->first > r - l) tie(l, r) = *it;
  }
  if (r == -1) {
    cout << "-1\n";
  } else {
    cout << l << ' ' << r << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}