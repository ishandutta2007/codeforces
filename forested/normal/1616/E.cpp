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

// ===== fenwick_tree.hpp =====
#ifndef FENWICK_TREE_HPP
#define FENWICK_TREE_HPP

#include <cassert>
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

template <typename CommutativeGroup>
class FenwickTree {
public:
    using Value = typename CommutativeGroup::Value;

private:
    std::vector<Value> data;

public:
    FenwickTree(std::size_t n) : data(n, CommutativeGroup::id()) {}

    void add(std::size_t idx, const Value &x) {
        assert(idx < data.size());
        for (; idx < data.size(); idx |= idx + 1) {
            data[idx] = CommutativeGroup::op(data[idx], x);
        }
    }

    Value sum(std::size_t r) const {
        assert(r <= data.size());
        Value ret = CommutativeGroup::id();
        for (; r > 0; r &= r - 1) {
            ret = CommutativeGroup::op(ret, data[r - 1]);
        }
        return ret;
    }

    Value sum(std::size_t l, std::size_t r) const {
        assert(l <= r && r <= data.size());
        return CommutativeGroup::op(sum(r), CommutativeGroup::inv(sum(l)));
    }
};

#endif
// ===== fenwick_tree.hpp =====

void solve() {
    i32 n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    array<Vec<i32>, 26> sidx;
    REP(i, n) {
        sidx[s[i] - 'a'].push_back(i);
    }
    array<i32, 26> iter;
    fill(ALL(iter), 0);
    FenwickTree<Add<i32>> fw(n);
    
    auto cost = [&](i32 from, i32 to) -> i32 {
        from += fw.sum(from + 1, n);
        return from - to;
    };
    
    i64 op = 0, ans = inf64;
    REP(i, n) {
        i32 c = t[i] - 'a';
        REP(d, t[i] - 'a') {
            if (iter[d] == sidx[d].size()) {
                continue;
            }
            chmin(ans, op + cost(sidx[d][iter[d]], i));
        }
        if (iter[c] == sidx[c].size()) {
            break;
        }
        op += cost(sidx[c][iter[c]], i);
        fw.add(sidx[c][iter[c]], 1);
        ++iter[c];
    }
    if (ans == inf64) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main() {
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}