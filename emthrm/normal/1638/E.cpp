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
struct LazySegmentTree {
  using Monoid = typename T::Monoid;
  using OperatorMonoid = typename T::OperatorMonoid;

  explicit LazySegmentTree(const int n)
      : LazySegmentTree(std::vector<Monoid>(n, T::m_id())) {}

  explicit LazySegmentTree(const std::vector<Monoid>& a)
      : n(a.size()), height(0) {
    while ((1 << height) < n) ++height;
    p2 = 1 << height;
    lazy.assign(p2, T::o_id());
    data.assign(p2 << 1, T::m_id());
    std::copy(a.begin(), a.end(), data.begin() + p2);
    for (int i = p2 - 1; i > 0; --i) {
      data[i] = T::m_merge(data[i << 1], data[(i << 1) + 1]);
    }
  }

  void set(int idx, const Monoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) {
      propagate(idx >> i);
    }
    data[idx] = val;
    for (int i = 1; i <= height; ++i) {
      const int current_idx = idx >> i;
      data[current_idx] =
          T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);
    }
  }

  void apply(int idx, const OperatorMonoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) {
      propagate(idx >> i);
    }
    data[idx] = T::apply(data[idx], val);
    for (int i = 1; i <= height; ++i) {
      const int current_idx = idx >> i;
      data[current_idx] =
          T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);
    }
  }

  void apply(int left, int right, const OperatorMonoid val) {
    if (right <= left) return;
    left += p2;
    right += p2;
    const int ctz_left = __builtin_ctz(left);
    for (int i = height; i > ctz_left; --i) {
      propagate(left >> i);
    }
    const int ctz_right = __builtin_ctz(right);
    for (int i = height; i > ctz_right; --i) {
      propagate(right >> i);
    }
    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply_sub(l++, val);
      if (r & 1) apply_sub(--r, val);
    }
    for (int i = left >> (ctz_left + 1); i > 0; i >>= 1) {
      data[i] = T::m_merge(data[i << 1], data[(i << 1) + 1]);
    }
    for (int i = right >> (ctz_right + 1); i > 0; i >>= 1) {
      data[i] = T::m_merge(data[i << 1], data[(i << 1) + 1]);
    }
  }

  Monoid get(int left, int right) {
    if (right <= left) return T::m_id();
    left += p2;
    right += p2;
    const int ctz_left = __builtin_ctz(left);
    for (int i = height; i > ctz_left; --i) {
      propagate(left >> i);
    }
    const int ctz_right = __builtin_ctz(right);
    for (int i = height; i > ctz_right; --i) {
      propagate(right >> i);
    }
    Monoid res_l = T::m_id(), res_r = T::m_id();
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) res_l = T::m_merge(res_l, data[left++]);
      if (right & 1) res_r = T::m_merge(data[--right], res_r);
    }
    return T::m_merge(res_l, res_r);
  }

  Monoid operator[](const int idx) {
    const int node = idx + p2;
    for (int i = height; i > 0; --i) {
      propagate(node >> i);
    }
    return data[node];
  }

  template <typename G>
  int find_right(int left, const G g) {
    if (left >= n) return n;
    left += p2;
    for (int i = height; i > 0; --i) {
      propagate(left >> i);
    }
    Monoid val = T::m_id();
    do {
      while (!(left & 1)) left >>= 1;
      Monoid nxt = T::m_merge(val, data[left]);
      if (!g(nxt)) {
        while (left < p2) {
          propagate(left);
          left <<= 1;
          nxt = T::m_merge(val, data[left]);
          if (g(nxt)) {
            val = nxt;
            ++left;
          }
        }
        return left - p2;
      }
      val = nxt;
      ++left;
    } while (__builtin_popcount(left) > 1);
    return n;
  }

  template <typename G>
  int find_left(int right, const G g) {
    if (right <= 0) return -1;
    right += p2;
    for (int i = height; i > 0; --i) {
      propagate((right - 1) >> i);
    }
    Monoid val = T::m_id();
    do {
      --right;
      while (right > 1 && (right & 1)) right >>= 1;
      Monoid nxt = T::m_merge(data[right], val);
      if (!g(nxt)) {
        while (right < p2) {
          propagate(right);
          right = (right << 1) + 1;
          nxt = T::m_merge(data[right], val);
          if (g(nxt)) {
            val = nxt;
            --right;
          }
        }
        return right - p2;
      }
      val = nxt;
    } while (__builtin_popcount(right) > 1);
    return -1;
  }

private:
  const int n;
  int p2, height;
  std::vector<Monoid> data;
  std::vector<OperatorMonoid> lazy;

  void apply_sub(const int idx, const OperatorMonoid& val) {
    data[idx] = T::apply(data[idx], val);
    if (idx < p2) lazy[idx] = T::o_merge(lazy[idx], val);
  }

  void propagate(const int idx) {
    // assert(1 <= idx && idx < p2);
    apply_sub(idx << 1, lazy[idx]);
    apply_sub((idx << 1) + 1, lazy[idx]);
    lazy[idx] = T::o_id();
  }
};

namespace monoid {

template <typename T>
struct RangeMinimumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return std::numeric_limits<Monoid>::max(); }
  static constexpr OperatorMonoid o_id() {
    return std::numeric_limits<OperatorMonoid>::max();
  }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return std::min(a, b);
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return b == o_id() ? a : b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return b == o_id() ? a : b;
  }
};

template <typename T>
struct RangeMaximumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() {
    return std::numeric_limits<Monoid>::lowest();
  }
  static constexpr OperatorMonoid o_id() {
    return std::numeric_limits<OperatorMonoid>::lowest();
  }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return std::max(a, b);
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return b == o_id() ? a : b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return b == o_id()? a : b;
  }
};

template <typename T, T Inf>
struct RangeMinimumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return Inf; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return std::min(a, b);
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return a + b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return a + b;
  }
};

template <typename T, T Inf>
struct RangeMaximumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return -Inf; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return std::max(a, b);
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return a + b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return a + b;
  }
};

template <typename T>
struct RangeSumAndUpdateQuery {
  using Monoid = struct { T sum; int len; };
  using OperatorMonoid = T;
  static std::vector<Monoid> init(const int n) {
    return std::vector<Monoid>(n, Monoid{0, 1});
  }
  static constexpr Monoid m_id() { return {0, 0}; }
  static constexpr OperatorMonoid o_id() {
    return std::numeric_limits<OperatorMonoid>::max();
  }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return Monoid{a.sum + b.sum, a.len + b.len};
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return b == o_id() ? a : b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return Monoid{b == o_id() ? a.sum : b * a.len, a.len};
  }
};

template <typename T>
struct RangeSumAndAddQuery {
  using Monoid = struct { T sum; int len; };
  using OperatorMonoid = T;
  static std::vector<Monoid> init(const int n) {
    return std::vector<Monoid>(n, Monoid{0, 1});
  }
  static constexpr Monoid m_id() { return {0, 0}; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return Monoid{a.sum + b.sum, a.len + b.len};
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return a + b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return Monoid{a.sum + b * a.len, a.len};
  }
};

}  // namespace monoid

int main() {
  int n, q; cin >> n >> q;
  // left -> {color, time}
  map<int, pair<int, int>> ls{{0, {0, -1}}, {n, {0, -1}}};
  vector xs(n, vector<ll>{0});
  vector ts(n, vector<int>{-2});
  LazySegmentTree<monoid::RangeMaximumAndAddQuery<ll, LINF>> seg(vector<ll>(n, 0));
  REP(i, q) {
    string s; cin >> s;
    if (s == "Color") {
      int l, r, c; cin >> l >> r >> c; --l; --r; --c;
      auto it = ls.lower_bound(l);
      if (it->first > l) {
        it = prev(it);
        const auto [col, tm] = it->second;
        if (ts[col].back() > tm) {
          const int idx = lower_bound(ALL(ts[col]), tm) - ts[col].begin();
          seg.apply(l, min(next(it)->first, r + 1), xs[col].back() - xs[col][idx - 1]);
        }
        it = next(it);
        if (it->first > r + 1) it = ls.emplace(r + 1, make_pair(col, tm)).first;
      }
      while (it->first <= r) {
        const auto [col, tm] = it->second;
        if (ts[col].back() > tm) {
          const int idx = lower_bound(ALL(ts[col]), tm) - ts[col].begin();
          seg.apply(it->first, min(next(it)->first, r + 1), xs[col].back() - xs[col][idx - 1]);
        }
        it = ls.erase(it);
        if (r + 1 < it->first) {
          ls[r + 1] = {col, tm};
          break;
        }
      }
      ls[l] = {c, i};
    } else if (s == "Add") {
      int c, x; cin >> c >> x; --c;
      xs[c].emplace_back(x);
      xs[c].back() += xs[c].end()[-2];
      ts[c].emplace_back(i);
    } else if (s == "Query") {
      int i; cin >> i; --i;
      ll ans = seg[i];
      const auto [col, tm] = prev(ls.upper_bound(i))->second;
      if (ts[col].back() > tm) {
        const int idx = lower_bound(ALL(ts[col]), tm) - ts[col].begin();
        ans += xs[col].back() - xs[col][idx - 1];
      }
      cout << ans << '\n';
    }
    // REP(i, n) cout << seg[i] << " \n"[i + 1 == n];
    // for (const auto [l, ct] : ls) {
    //   cout << l << " -> {" << ct.first << ", " << ct.second << "}\n";
    // }
  }
  return 0;
}