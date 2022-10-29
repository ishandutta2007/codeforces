// ===== template.hpp =====
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (n); ++i)
#define REP3(i, m, n) for (i32 i = (m); i < (n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (n) - 1; i >= 0; --i)
#define ALL(x) begin(x), end(x)

using namespace std;

using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = __uint128_t;
using i32 = signed int;
using i64 = signed long long;
using i128 = __int128_t;

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

[[maybe_unused]] constexpr i32 inf = 1000000100;
[[maybe_unused]] constexpr i64 inf64 = 3000000000000000100;

struct SetIO {
    SetIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(10);
    }
} set_io;
// ===== template.hpp =====

#ifdef DEBUGF
#include  "../new_library/other/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

// ===== coordinate_compression.hpp =====
#ifndef COORDINATE_COMPRESSION_HPP
#define COORDINATE_COMPRESSION_HPP

#include <algorithm>
#include <vector>

template <typename T>
class CoordinateCompression {
    std::vector<T> data;

    std::size_t size_sum() {
        return 0;
    }

    template <typename... Tail>
    std::size_t size_sum(const std::vector<T> &head, const Tail &...tail) {
        return head.size() + size_sum(tail...);
    }

    void push() {}

    template <typename... Tail>
    void push(const std::vector<T> &head, const Tail &...tail) {
        for (const T &ele : head) {
            data.emplace_back(ele);
        }
        push(tail...);
    }

    void compress() {}

    template <typename... Tail>
    void compress(std::vector<T> &head, Tail &...tail) {
        for (T &ele : head) {
            ele =
                (T)(std::lower_bound(data.begin(), data.end(), ele) -
                    data.begin());
        }
        compress(tail...);
    }

public:
    template <typename... V>
    CoordinateCompression(V &...v) {
        data.reserve(size_sum(v...));
        push(v...);
        std::sort(data.begin(), data.end());
        data.erase(std::unique(data.begin(), data.end()), data.end());
        compress(v...);
    }

    const T &operator[](const T &ele) const {
        return data[ele];
    }

    std::size_t size() const {
        return data.size();
    }
};

#endif
// ===== coordinate_compression.hpp =====
// ===== segment_tree.hpp =====
#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <cassert>
#include <utility>
#include <vector>

// ===== operations.hpp =====
#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

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

#endif
// ===== operations.hpp =====

template <typename Monoid>
class SegmentTree {
public:
    using Value = typename Monoid::Value;

private:
    std::size_t old_length;
    std::size_t length;
    std::vector<Value> node;

    static std::size_t ceil2(std::size_t n) {
        std::size_t l = 1;
        while (l < n) {
            l <<= 1;
        }
        return l;
    }

public:
    SegmentTree(std::size_t n) :
        old_length(n),
        length(ceil2(old_length)),
        node(length << 1, Monoid::id()) {}

    SegmentTree(const std::vector<Value> &v) :
        old_length(v.size()),
        length(ceil2(old_length)),
        node(length << 1, Monoid::id()) {
        for (std::size_t i = 0; i < old_length; ++i) {
            node[i + length] = v[i];
        }
        for (std::size_t i = length - 1; i > 0; --i) {
            node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);
        }
    }

    template <typename F>
    SegmentTree(std::size_t n, const F &f) :
        old_length(n), length(ceil2(n)), node(length << 1, Monoid::id()) {
        for (std::size_t i = 0; i < old_length; ++i) {
            node[i + length] = f(i);
        }
        for (std::size_t i = length - 1; i > 0; --i) {
            node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);
        }
    }

    const Value &operator[](std::size_t idx) const {
        assert(idx < old_length);
        return node[idx + length];
    }

    void update(std::size_t idx, Value val) {
        assert(idx < old_length);
        idx += length;
        node[idx] = std::move(val);
        while (idx != 1) {
            idx >>= 1;
            node[idx] = Monoid::op(node[idx << 1], node[idx << 1 | 1]);
        }
    }

    Value prod(std::size_t l, std::size_t r) const {
        assert(l <= r && r <= old_length);
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
};

#endif
// ===== segment_tree.hpp =====

void solve() {
    i32 n;
    cin >> n;
    Vec<i32> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    i32 x;
    cin >> x;
    REP(i, n) {
        a[i] -= x;
    }
    
    Vec<i64> asum(n + 1, 0);
    REP(i, n) asum[i + 1] = asum[i] + a[i];
    CoordinateCompression<i64> cc(asum);
    
    // s[i + 1] - s[i] <= 0
    // s[t] - s[i] <= -1
    // maximize s[n]
    SegmentTree<Min<i32>> seg(cc.size());
    Vec<i32> dist(n + 1, inf);
    dist[0] = 0;
    REP(i, 1, n + 1) {
        chmin(dist[i], dist[i - 1]);
        if (i32 m = seg.prod(asum[i] + 1, cc.size()); m != Min<i32>::id()) {
            chmin(dist[i], m - 1);
        }
        seg.update(asum[i - 1], min(seg[asum[i - 1]], dist[i - 1]));
    }
    i32 c = -dist[n];
    cout << n - c << '\n';
}

int main() {
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}