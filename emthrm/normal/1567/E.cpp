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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename Abelian>
struct FenwickTree {
  FenwickTree(int n, const Abelian ID = 0) : n(n), ID(ID), dat(n, ID) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat;
};

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

  std::pair<T, T> e1567(T x) const {
    typename IntervalType::const_iterator it = interval.lower_bound({x, x});
    if (x < it->first) it = std::prev(it);
    assert(it->first <= x && x <= it->second);
    return {it->first, it->second};
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

ll f(int l, int r) {
  const int len = r - l + 2;
  return len * (len - 1LL) / 2;
}

int main() {
  int n, q; cin >> n >> q;
  vector<int> a(n); REP(i, n) cin >> a[i];
  SetManagedByInterval<int> set;
  REP(i, n - 1) {
    if (a[i] <= a[i + 1]) set.insert(i);
  }
  FenwickTree<ll> bit(n - 1);
  for (auto [l, r] : set.interval) {
    if (0 <= l && r < n - 1) bit.add(l, f(l, r));
  }
  auto erase = [&](int p) -> void {
    auto [l, r] = set.e1567(p);
    bit.add(l, -f(l, r));
    if (l < p) bit.add(l, f(l, p - 1));
    if (p < r) bit.add(p + 1, f(p + 1, r));
    assert(set.erase(p).second);
  };
  auto insert = [&](int p) -> void {
    auto [it, flag] = set.insert(p);
    assert(flag);
    auto [l, r] = *it;
    if (l < p) bit.add(l, -f(l, p - 1));
    if (p < r) bit.add(p + 1, -f(p + 1, r));
    bit.add(l, f(l, r));
  };
  auto change = [&](int p) -> void {
    a[p] <= a[p + 1] ? erase(p) : insert(p);
  };
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int x, y; cin >> x >> y; --x;
      if (x + 1 < n && (a[x] <= a[x + 1]) != (y <= a[x + 1])) change(x);
      if (x > 0 && (a[x - 1] <= a[x]) != (a[x - 1] <= y)) change(x - 1);
      a[x] = y;
    } else if (t == 2) {
      int l, r; cin >> l >> r; --l; --r;
      if (l == r) {
        cout << 1 << '\n';
        continue;
      }
      if (set.contains(l, r - 1)) {
        const int len = r - l + 1;
        cout << len * (len + 1LL) / 2 << '\n';
        continue;
      }
      assert(l + 1 < n && r >= 1);
      ll ans = bit.sum(l, r) + (r - l + 1);
      if (r + 1 < n && a[r - 1] <= a[r] && a[r] <= a[r + 1]) {
        auto [le, ri] = set.e1567(r - 1);
        ans -= f(le, ri);
        ans += f(le, r - 1);
      }
      if (l > 0 && a[l - 1] <= a[l] && a[l] <= a[l + 1]) {
        auto [le, ri] = set.e1567(l);
        ans += f(l, ri);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}