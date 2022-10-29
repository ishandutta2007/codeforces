// Template
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <tuple>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <cassert>
#include <cmath>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll infll = 3003003003003003003LL;
template <typename T>
inline bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T> 
inline bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &element : vec) is >> element;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (int i = 0, vec_len = (int)vec.size(); i < vec_len; ++i) {
        os << vec[i] << (i + 1 == vec_len ? "" : " ");
    }
    return os;
}
struct IOSET {
    IOSET() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} ioset;

// Segment Tree
#include <vector>
#include <cassert>

template <typename Operator>
struct SegmentTree {
    using NodeType = decltype(Operator::identity());
    int length, n_;
    std::vector<NodeType> node;
    
    SegmentTree(int n) {
        assert(n >= 0);
        n_ = n;
        length = 1;
        while (length < n || length == 1) length <<= 1;
        node.assign(length << 1, Operator::identity());
    }
    
    SegmentTree(int n, NodeType x) {
        assert(n >= 0);
        n_ = n;
        length = 1;
        while (length < n || length == 1) length <<= 1;
        node.assign(length << 1, x);
        for (int i = length - 1; i > 0; --i) node[i] = Operator::func(node[(i << 1) | 0], node[(i << 1) | 1]);
    }
    
    SegmentTree(std::vector<NodeType> &vec) : n_((int)vec.size()) {
        length = 1;
        while (length < (int)vec.size() || length == 1) length <<= 1;
        node.assign(2 * length, Operator::identity());
        for (int i = 0; i < (int)vec.size(); ++i) node[i + length] = vec[i];
        for (int i = length - 1; i > 0; --i) node[i] = Operator::func(node[(i << 1) | 0], node[(i << 1) | 1]);
    }
    
    void update(int idx, NodeType val) {
        assert(idx >= 0 && idx < n_);
        idx += length;
        node[idx] = val;
        while (idx >>= 1) node[idx] = Operator::func(node[(idx << 1) | 0], node[(idx << 1) | 1]);
    }
    
    NodeType get(int l, int r) {
        assert(l >= 0 && l <= n_ && r >= 0 && r <= n_ && l <= r);
        l += length;
        r += length;
        NodeType vl = Operator::identity(), vr = Operator::identity();
        while (r > l) {
            if (l & 1) vl = Operator::func(vl, node[l++]);
            if (r & 1) vr = Operator::func(node[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return Operator::func(vl, vr);
    }
    
    NodeType &operator[](int idx) {
        return node[idx + length];
    }
    
    template <typename F>
    int max_right(int l, F f) {
        assert(l >= 0 && l < n_);
        l += length;
        NodeType sum = Operator::identity();
        do {
            while (!(l & 1)) l >>= 1;
            if (!f(Operator::func(sum, node[l]))) {
                while (l < length) {
                    l <<= 1;
                    if (f(Operator::func(sum, node[l]))) {
                        sum = Operator::func(sum, node[l]);
                        ++l;
                    }
                }
                return l - length;
            }
            sum = Operator::func(sum, node[l]);
            ++l;
        } while ((l & -l) != l);
        return n_;
    }
};

struct RMQ {
    using NodeType = int;
    static NodeType identity() {
        return inf;
    }
    static NodeType func(NodeType x, NodeType y) {
        return x < y ? x : y;
    }
};

struct RGQ {
    using NodeType = int;
    static NodeType identity() {
        return 0;
    }
    static NodeType func(NodeType x, NodeType y) {
        if (x == 0) return y;
        if (y == 0) return x;
        return gcd(x, y);
    }
};

// Lazy Segment Tree
#include <vector>
#include <cassert>

template <typename Operator>
class LazySegmentTree {
    using NodeType = decltype(Operator::node_identity());
    using FuncType = decltype(Operator::func_identity());
    int length, height, n_;
    std::vector<NodeType> node;
    std::vector<FuncType> lazy;
    std::vector<int> width;
    
    void eval(int n) {
        node[n] = Operator::node_func(node[n], lazy[n], width[n]);
        if (n < length) {
            lazy[(n << 1) | 0] = Operator::merge_func(lazy[(n << 1) | 0], lazy[n]);
            lazy[(n << 1) | 1] = Operator::merge_func(lazy[(n << 1) | 1], lazy[n]);
        }
        lazy[n] = Operator::func_identity();
    }
    
public:
    LazySegmentTree(int n) {
        assert(n >= 0);
        n_ = n;
        length = 1;
        height = 0;
        while (length < n || length == 1) {
            length <<= 1;
            ++height;
        }
        node.resize(length << 1, Operator::node_identity());
        lazy.resize(length << 1, Operator::func_identity());
        width.resize(length << 1, 1);
        for (int i = length - 1; i > 0; --i) width[i] = width[i << 1] << 1;
    }
    
    LazySegmentTree(int n, NodeType x) {
        assert(n >= 0);
        n_ = n;
        length = 1;
        height = 0;
        while (length < n) {
            length <<= 1;
            ++height;
        }
        node.resize(length << 1, x);
        for (int i = length - 1; i > 0; --i) node[i] = Operator::merge_node(node[(i << 1) | 0], node[(i << 1) | 1]);
        lazy.resize(length << 1, Operator::func_identity());
        width.resize(length << 1, 1);
        for (int i = length - 1; i > 0; --i) width[i] = width[i << 1] << 1;
    }
    
    LazySegmentTree(std::vector<NodeType> &vec) : n_((int)vec.size()) {
        length = 1;
        height = 0;
        while (length < (int)vec.size()) {
            length <<= 1;
            ++height;
        }
        node.resize(length << 1, Operator::node_identity());
        for (int i = 0; i < (int)vec.size(); ++i) node[i + length] = vec[i];
        for (int i = length - 1; i > 0; --i) node[i] = Operator::merge_node(node[(i << 1) | 0], node[(i << 1) | 1]);
        lazy.resize(length << 1, Operator::func_identity());
        width.resize(length << 1, 1);
        for (int i = length - 1; i > 0; --i) width[i] = width[i << 1] << 1;
    }
    
    void update(int a, int b, FuncType x) {
        assert(a >= 0 && a <= n_ && b >= 0 && b <= n_ && a <= b);
        int l = a + length, r = b + length - 1;
        for (int i = height; i > 0; --i) {
            eval(l >> i);
            eval(r >> i);
        }
        ++r;
        while (r > l) {
            if (l & 1) {
                lazy[l] = Operator::merge_func(lazy[l], x);
                eval(l);
                ++l;
            }
            if (r & 1) {
                --r;
                lazy[r] = Operator::merge_func(lazy[r], x);
                eval(r);
            }
            l >>= 1; r >>= 1;
        }
        l = a + length; r = b + length - 1;
        while (l >>= 1) node[l] = Operator::merge_node(Operator::node_func(node[(l << 1) | 0], lazy[(l << 1) | 0], width[(l << 1) | 0]), Operator::node_func(node[(l << 1) | 1], lazy[(l << 1) | 1], width[(l << 1) | 1]));
        while (r >>= 1) node[r] = Operator::merge_node(Operator::node_func(node[(r << 1) | 0], lazy[(r << 1) | 0], width[(r << 1) | 0]), Operator::node_func(node[(r << 1) | 1], lazy[(r << 1) | 1], width[(r << 1) | 1]));
    }
    
    void update(int idx, NodeType x) {
        assert(idx >= 0 && idx < n_);
        idx += length;
        for (int i = height; i >= 0; --i) eval(idx >> i);
        node[idx] = x;
        while (idx >>= 1) node[idx] = Operator::merge_node(Operator::node_func(node[(idx << 1) | 0], lazy[(idx << 1) | 0], width[(idx << 1) | 0]), Operator::node_func(node[(idx << 1) | 1], lazy[(idx << 1) | 1], width[(idx << 1) | 1]));
    }
    
    NodeType get(int a, int b) {
        assert(a >= 0 && a <= n_ && b >= 0 && b <= n_ && a <= b);
        int l = a + length, r = b + length - 1;
        for (int i = height; i >= 0; --i) {
            eval(l >> i);
            eval(r >> i);
        }
        ++r;
        NodeType vl = Operator::node_identity(), vr = Operator::node_identity();
        while (l < r) {
            if (l & 1) {
                vl = Operator::merge_node(vl, Operator::node_func(node[l], lazy[l], width[l]));
                ++l;
            }
            if (r & 1) {
                --r;
                vr = Operator::merge_node(Operator::node_func(node[r], lazy[r], width[r]), vr);
            }
            l >>= 1; r >>= 1;
        }
        return Operator::merge_node(vl, vr);
    }
};

struct RSQRUQ {
    using NodeType = int;
    using FuncType = int;
    static NodeType node_identity() {
        return 0;
    }
    static FuncType func_identity() {
        return inf;
    }
    static NodeType merge_node(NodeType x, NodeType y) {
        return x + y;
    }
    static FuncType merge_func(FuncType x, FuncType y) {
        if (y == inf) return x;
        return y;
    }
    static NodeType node_func(NodeType x, FuncType y, int len) {
        if (y == inf) return x;
        return y * len;
    }
};

// Main
ll solve(int n, int p, vector<int> &a) {
    SegmentTree<RMQ> rmq(a);
    SegmentTree<RGQ> rgq(a);
    
    ll ans = 0;
    
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
        return a[i] < a[j];
    });
    LazySegmentTree<RSQRUQ> connected(n);
    for (int i : idx) {
        if (a[i] > p) {
            break;
        }
        // left
        int ok = i, ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (rmq.get(mid, i + 1) == a[i] && rgq.get(mid, i + 1) == a[i]) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans += (ll)a[i] * (i - ok - connected.get(ok, i));
        connected.update(ok, i, 1);
        //cout << '[' << ok << ' ' << i << "]\n";
        //cout << ans << '\n';
        
        // right
        ok = i, ng = n;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (rmq.get(i, mid + 1) == a[i] && rgq.get(i, mid + 1) == a[i]) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans += (ll)a[i] * (ok - i - connected.get(i, ok));
        connected.update(i, ok, 1);
        //cout << '[' << i << ' ' << ok << "]\n";
        //cout << ans << '\n';
    }
    ans += (ll)p * (n - 1 - connected.get(0, n - 1));
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        cin >> a;
        cout << solve(n, p, a) << '\n';
    }
}