#ifndef LOCAL
#define FAST_IO
#endif

// ===== template.hpp =====
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)
#define REP3(i, m, n) for (i32 i = (i32) (m); i < (i32) (n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)
#define ALL(x) begin(x), end(x)

using namespace std;

using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = __uint128_t;
using i32 = signed int;
using i64 = signed long long;
using i128 = __int128_t;
using f64 = double;
using f80 = long double;

template <typename T>
using Vec = vector<T>;

template <typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

istream &operator>>(istream &is, i128 &x) {
    i64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, i128 x) {
    os << (i64) x;
    return os;
}
istream &operator>>(istream &is, u128 &x) {
    u64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, u128 x) {
    os << (u64) x;
    return os;
}

[[maybe_unused]] constexpr i32 INF = 1000000100;
[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;
struct SetUpIO {
    SetUpIO() {
#ifdef FAST_IO
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
#endif
        cout << fixed << setprecision(15);
    }
} set_up_io;
// ===== template.hpp =====

#ifdef DEBUGF
#include "cpl/template/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

// ===== sparse_table.hpp =====

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include <functional>

template <typename T, typename F = std::less<T>>
class SparseTable {
    std::vector<std::vector<T>> table;
    int s;
    const F f;

    int log2(int n) const {
        return 31 - __builtin_clz(n);
    }
    
    T min2(const T &x, const T &y) const {
        if (f(x, y)) {
            return x;
        } else {
            return y;
        }
    }

public:
    SparseTable(std::vector<T> arr, F _f = F()) : s(static_cast<int>(arr.size())), f(std::move(_f)) {
        if (s == 0) {
            return;
        }
        int m = log2(s);
        table.resize(m + 1);
        table[0] = std::move(arr);
        for (int i = 1; i <= m; ++i) {
            int w = 1 << i;
            table[i].resize(s - w + 1);
            for (int j = 0; j < static_cast<int>(table[i].size()); ++j) {
                table[i][j] = min2(table[i - 1][j], table[i - 1][j + (w >> 1)]);
            }
        }
    }

    int size() const {
        return s;
    }

    // not empty
    T min(int l, int r) const {
        assert(l >= 0 && l < r && r <= s);
        int m = log2(r - l);
        return min2(table[m][l], table[m][r - (1 << m)]);
    }
};

// ===== sparse_table.hpp =====
// ===== fenwick_tree.hpp =====

#include <cassert>
#include <vector>

// ===== operations.hpp =====

#include <limits>
#include <utility>

template <typename T>
struct Add {
    using Value = T;
    static Value id() {
        return T(0);
    }
    static Value op(const Value &lhs, const Value &rhs) {
        return lhs + rhs;
    }
    static Value inv(const Value &x) {
        return -x;
    }
};

template <typename T>
struct Mul {
    using Value = T;
    static Value id() {
        return Value(1);
    }
    static Value op(const Value &lhs, const Value &rhs) {
        return lhs * rhs;
    }
    static Value inv(const Value &x) {
        return Value(1) / x;
    }
};

template <typename T>
struct Min {
    using Value = T;
    static Value id() {
        return std::numeric_limits<T>::max();
    }
    static Value op(const Value &lhs, const Value &rhs) {
        return std::min(lhs, rhs);
    }
};

template <typename T>
struct Max {
    using Value = T;
    static Value id() {
        return std::numeric_limits<Value>::min();
    }
    static Value op(const Value &lhs, const Value &rhs) {
        return std::max(lhs, rhs);
    }
};

template <typename T>
struct Xor {
    using Value = T;
    static Value id() {
        return T(0);
    }
    static Value op(const Value &lhs, const Value &rhs) {
        return lhs ^ rhs;
    }
    static Value inv(const Value &x) {
        return x;
    }
};

template <typename Monoid>
struct Reversible {
    using Value = std::pair<typename Monoid::Value, typename Monoid::Value>;
    static Value id() {
        return Value(Monoid::id(), Monoid::id());
    }
    static Value op(const Value &v1, const Value &v2) {
        return Value(
            Monoid::op(v1.first, v2.first),
            Monoid::op(v2.second, v1.second));
    }
};

// ===== operations.hpp =====

template <typename CommutativeGroup>
class FenwickTree {
public:
    using Value = typename CommutativeGroup::Value;

private:
    std::vector<Value> data;

public:
    FenwickTree(int n) : data(n, CommutativeGroup::id()) {}

    void add(int idx, const Value &x) {
        assert(idx >= 0 && idx < static_cast<int>(data.size()));
        for (; idx < static_cast<int>(data.size()); idx |= idx + 1) {
            data[idx] = CommutativeGroup::op(data[idx], x);
        }
    }

    Value sum(int r) const {
        assert(r >= 0 && r <= static_cast<int>(data.size()));
        Value ret = CommutativeGroup::id();
        for (; r > 0; r &= r - 1) {
            ret = CommutativeGroup::op(ret, data[r - 1]);
        }
        return ret;
    }

    Value sum(int l, int r) const {
        assert(l >= 0 && l <= r && r <= static_cast<int>(data.size()));
        return CommutativeGroup::op(sum(r), CommutativeGroup::inv(sum(l)));
    }
};
// ===== fenwick_tree.hpp =====
// ===== segment_tree.hpp =====

#include <cassert>
#include <utility>
#include <vector>


template <typename Monoid>
class SegmentTree {
public:
    using Value = typename Monoid::Value;

private:
    int old_length;
    int length;
    std::vector<Value> node;

    static int ceil2(int n) {
        int l = 1;
        while (l < n) {
            l <<= 1;
        }
        return l;
    }

public:
    SegmentTree(int n) :
        old_length(n),
        length(ceil2(old_length)),
        node(length << 1, Monoid::id()) {
        assert(n >= 0);
    }

    SegmentTree(const std::vector<Value> &v) :
        old_length(static_cast<int>(v.size())),
        length(ceil2(old_length)),
        node(length << 1, Monoid::id()) {
        for (int i = 0; i < old_length; ++i) {
            node[i + length] = v[i];
        }
        for (int i = length - 1; i > 0; --i) {
            node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);
        }
    }

    template <typename F>
    SegmentTree(int n, const F &f) :
        old_length(n), length(ceil2(n)), node(length << 1, Monoid::id()) {
        assert(n >= 0);
        for (int i = 0; i < old_length; ++i) {
            node[i + length] = f(i);
        }
        for (int i = length - 1; i > 0; --i) {
            node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);
        }
    }

    const Value &operator[](int idx) const {
        assert(idx >= 0 && idx < old_length);
        return node[idx + length];
    }

    void update(int idx, Value val) {
        assert(idx >= 0 && idx < old_length);
        idx += length;
        node[idx] = std::move(val);
        while (idx != 1) {
            idx >>= 1;
            node[idx] = Monoid::op(node[idx << 1], node[idx << 1 | 1]);
        }
    }

    Value prod(int l, int r) const {
        assert(l >= 0 && l <= r && r <= old_length);
        Value prodl = Monoid::id();
        Value prodr = Monoid::id();
        l += length;
        r += length;
        while (l != r) {
            if (l & 1) {
                prodl = Monoid::op(prodl, node[l++]);
            }
            if (r & 1) {
                prodr = Monoid::op(node[--r], prodr);
            }
            l >>= 1;
            r >>= 1;
        }
        return Monoid::op(prodl, prodr);
    }
    
    Value all_prod() const {
        return node[1];
    }
};

// ===== segment_tree.hpp =====

struct RMQ {
    using Value = i64;
    static Value id() {
        return -INF64;
    }
    static Value op(Value x, Value y) {
        return max(x, y);
    }
};

void solve() {
    i32 n;
    i64 m_;
    cin >> n >> m_;
    Vec<i64> x(n), p(n);
    REP(i, n) {
        cin >> x[i] >> p[i];
    }
    
    Vec<i64> poses;
    poses.reserve(3 * n);
    REP(i, n) {
        poses.push_back(x[i] - p[i]);
        poses.push_back(x[i]);
        poses.push_back(x[i] + p[i]);
    }
    sort(ALL(poses));
    poses.erase(unique(ALL(poses)), poses.end());
    i32 p_n = (i32) poses.size();
    
    FenwickTree<Add<i64>> cons(p_n), coeff(p_n);
    REP(i, n) {
        i32 l = (i32) (lower_bound(ALL(poses), x[i] - p[i]) - poses.begin());
        i32 m = (i32) (lower_bound(ALL(poses), x[i]) - poses.begin());
        i32 r = (i32) (lower_bound(ALL(poses), x[i] + p[i]) - poses.begin());
        cons.add(l, p[i] - x[i]);
        cons.add(m, -(p[i] - x[i]));
        cons.add(m, p[i] + x[i]);
        cons.add(r, -(p[i] + x[i]));
        coeff.add(l, 1);
        coeff.add(m, -1);
        coeff.add(m, -1);
        coeff.add(r, 1);
    }
    Vec<i64> acc(p_n);
    REP(i, p_n) {
        acc[i] = cons.sum(i + 1) + poses[i] * coeff.sum(i + 1);
    }
    
    Vec<i64> pls(p_n), mns(p_n);
    REP(i, p_n) {
        pls[i] = acc[i] + poses[i];
        mns[i] = acc[i] - poses[i];
    }
    //SparseTable<i64, greater<>> sp_acc(acc), sp_pls(pls), sp_mns(mns);
    SegmentTree<RMQ> seg_acc(acc), seg_pls(pls), seg_mns(mns);
    string ans(n, '0');
    REP(i, n) {
        i32 l = (i32) (lower_bound(ALL(poses), x[i] - p[i]) - poses.begin());
        i32 m = (i32) (lower_bound(ALL(poses), x[i]) - poses.begin());
        i32 r = (i32) (lower_bound(ALL(poses), x[i] + p[i]) - poses.begin());
        bool ok = true;
        //if (l != 0 && sp_acc.min(0, l) > m_) {
        if (seg_acc.prod(0, l) > m_) {
            ok = false;
        }
        //if (sp_mns.min(l, m) > m_ + p[i] - x[i]) {
        if (seg_mns.prod(l, m) > m_ + p[i] - x[i]) {
            ok = false;
        }
        //if (sp_pls.min(m, r) > m_ + p[i] + x[i]) {
        if (seg_pls.prod(m, r) > m_ + p[i] + x[i]) {
            ok = false;
        }
        //if (r != p_n && sp_acc.min(r, p_n) > m_) {
        if (seg_acc.prod(r, p_n) > m_) {
            ok = false;
        }
        if (ok) {
            ans[i] = '1';
        }
        DBG(ok);
    }
    DBG(sp_mns.min(1, 4));
    DBG(sp_pls.min(4, 7));
    
    cout << ans << '\n';
}

int main() {
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}