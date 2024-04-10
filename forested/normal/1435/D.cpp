// Template
#include "bits/stdc++.h"
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
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
struct IOSET {
    IOSET() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} ioset;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &element : vec) is >> element;
    return is;
}
template <typename T>
vector<T> operator--(vector<T> &vec) {
    for (T &element : vec) --element;
    return vec;
}

// Lazy Segment Tree
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
        while (length < n) {
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


struct hoge {
    using NodeType = int;
    using FuncType = int;
    static NodeType node_identity() {
        return -1;
    }
    static FuncType func_identity() {
        return -1;
    }
    static NodeType merge_node(NodeType x, NodeType y) {
        return max(x, y);
    }
    static FuncType merge_func(FuncType x, FuncType y) {
        if (y == -1) return x;
        return max(x, y);
    }
    static NodeType node_func(NodeType x, FuncType y, int len) {
        if (y == -1) return x;
        return max(x, y);
    }
};

// Fenwick Tree
template <typename T>
class FenwickTree {
    int length;
    std::vector<T> node;
    
public:
    FenwickTree (int n) : length(n), node(length + 1, 0) {
        assert(n >= 0);
    }
    
    void add(int idx, T val) {
        assert(idx >= 0 && idx < length);
        ++idx;
        while (idx <= length) {
            node[idx] += val;
            idx += (idx & (-idx));
        }
    }
    
    T getsum(int idx) {
        assert(idx >= 0 && idx <= length);
        T ans = T(0);
        while (idx) {
            ans += node[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }
};

// Main
int main() {
    int n;
    cin >> n;
    vector<int> a(2 * n, 0), b(2 * n, 0);
    rep(i, 2 * n) {
        char c;
        cin >> c;
        if (c == '-') {
            a[i] = 1;
            int x;
            cin >> x;
            --x;
            b[i] = x;
        }
    }
    
    vector<int> ans(n, -1);
    int cnt = 0;
    LazySegmentTree<hoge> st(n);
    FenwickTree<int> ft(n);
    rep(i, 2 * n) {
        if (a[i] == 0) {
            ft.add(cnt, 1);
            ++cnt;
            continue;
        }
        st.update(0, cnt, b[i]);
        int ok = cnt, ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (st.get(mid, mid + 1) <= b[i]) ok = mid;
            else ng = mid;
        }
        if (ok == cnt) {
            cout << "NO\n";
            return 0;
        }
        if (ft.getsum(cnt) - ft.getsum(ok) == 0) {
            cout << "NO\n";
            return 0; 
        }
        int ng_ = ok, ok_ = cnt;
        while (ok_ - ng_ > 1) {
            int mid = (ok_ + ng_) / 2;
            if (ft.getsum(mid) - ft.getsum(ok)) ok_ = mid;
            else ng_ = mid;
        }
        ans[ok_ - 1] = b[i];
        ft.add(ok_ - 1, -1);
    }
    
    cout << "YES\n";
    rep(i, n) cout << ans[i] + 1 << " \n"[i == n - 1];
}