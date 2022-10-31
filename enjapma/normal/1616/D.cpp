#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define drep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)

#define popcount __builtin_popcount
#define next __next
#define prev __prev

#ifndef LOCAL
#define dmp(...) ;
#else
#define dmp(...)                                                               \
    cerr << "[ " << #__VA_ARGS__ << " ] : " << dump_str(__VA_ARGS__) << endl
#endif

// ---------------- Utility ------------------

template <class T> bool chmin(T &a, const T &b) {
    if (a <= b) return false;
    a = b;
    return true;
}

template <class T> bool chmax(T &a, const T &b) {
    if (a >= b) return false;
    a = b;
    return true;
}

template <class T> using MaxHeap = priority_queue<T>;

template <class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

template <class T> vector<T> vect(int len, T elem) {
    return vector<T>(len, elem);
}

// ----------------- Input -------------------

template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) {
    return is >> p.first >> p.second;
}

template <class T> istream &operator>>(istream &is, vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++)
        is >> vec[i];
    return is;
}

// ----------------- Output ------------------

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    return os << p.first << ',' << p.second;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const T &e : v)
        os << e << " ";
    return os;
}

template <class T> ostream &operator<<(ostream &os, const deque<T> &d) {
    for (const T &e : d)
        os << e << " ";
    return os;
}

template <class T> ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{ ";
    for (const T &e : s)
        os << e << " ";
    return os << "}";
}

template <class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
    os << "{ ";
    for (const auto &[key, val] : m)
        os << "( " << key << " -> " << val << " ) ";
    return os << "}";
}

template <class TupleTy, size_t... I>
void dump_tuple(ostream &os, const TupleTy t, std::index_sequence<I...>) {
    (..., (os << (I == 0 ? "" : ",") << std::get<I>(t)));
}

template <class... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t) {
    os << "(";
    dump_tuple(os, t, std::make_index_sequence<sizeof...(Args)>());
    return os << ")";
}

void dump_str_rec(ostringstream &) {
}

template <class Head, class... Tail>
void dump_str_rec(ostringstream &oss, Head &&head, Tail &&...tail) {
    oss << ", " << head;
    dump_str_rec(oss, forward<Tail>(tail)...);
}

template <class T, class... U> string dump_str(T &&arg, U &&...args) {
    ostringstream oss;
    oss << arg;
    dump_str_rec(oss, forward<U>(args)...);
    return oss.str();
}

// --------------- Fast I/O ------------------

void fastio() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
}

// ------------------ ACL --------------------

// #include <atcoder/modint>
// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// using mint = atcoder::static_modint<MOD>;
// ostream &operator<<(ostream &os, const mint &v) {
//   return os << v.val();
// }

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

const bool multitest = true;

struct UnionFind {
    vector<int> par, rank, sz, es;
    UnionFind(int n) {
        par.assign(n, 0);
        rank.assign(n, 0);
        sz.assign(n, 1);
        es.assign(n, 0);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int find(const int x) {
        return (par[x] == x) ? x : (par[x] = find(par[x]));
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            es[x]++;
            return;
        }
        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
            es[y] += es[x] + 1;
        } else {
            par[y] = x;
            sz[x] += sz[y];
            es[x] += es[y] + 1;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
    bool same(const int x, const int y) {
        return find(x) == find(y);
    }
    int size(const int x) {
        return sz[find(x)];
    }
    vector<vector<int>> components() {
        int n = par.size();
        vector<vector<int>> cs;
        vector<int> idx(n, -1);
        for (int i = 0; i < n; i++) {
            if (find(i) != i) continue;
            idx[i] = cs.size();
            cs.emplace_back();
        }
        for (int i = 0; i < n; i++) {
            int id = idx[find(i)];
            cs[id].push_back(i);
        }
        return cs;
    }
};

template <class D> struct SegmentTree {
    using DMerger = function<D(D, D)>;
    int length;
    vector<D> seg;
    const D d_unit;
    const DMerger dm;

    SegmentTree() {
    }
    SegmentTree(int n, const DMerger dm, const D &d_unit)
        : dm(dm), d_unit(d_unit) {
        length = 1;
        while (length < n)
            length <<= 1;
        seg.assign(2 * length, d_unit);
    }
    SegmentTree(vector<D> vec, const DMerger dm, const D &d_unit)
        : dm(dm), d_unit(d_unit) {
        length = 1;
        while (length < vec.size())
            length <<= 1;
        seg.assign(2 * length, d_unit);
        for (int i = 0; i < vec.size(); i++)
            seg[length - 1 + i] = vec[i];
        for (int i = length - 2; i >= 0; i--)
            seg[i] = dm(seg[i * 2 + 1], seg[i * 2 + 2]);
    }

    void update(int k, D x) {
        k += length - 1;
        seg[k] = x;
        while (k) {
            k = (k - 1) / 2;
            seg[k] = dm(seg[k * 2 + 1], seg[k * 2 + 2]);
        }
    }

    D query(int a, int b, int k, int l, int r) const {
        if (r <= a || b <= l) {
            return d_unit;
        } else if (a <= l && r <= b) {
            return seg[k];
        } else {
            D lch = query(a, b, k * 2 + 1, l, (l + r) / 2);
            D rch = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return dm(lch, rch);
        }
    }
    D query(int a, int b) const {
        return query(a, b, 0, 0, length);
    }
    D get_point(int x) const {
        return seg[length - 1 + x];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    ll x;
    cin >> x;
    for (int i = 0; i < n; i++) {
        a[i] -= x;
    }

    vector<ll> rui(n + 1, 0ll);
    for (int i = 0; i < n; i++) {
        rui[i + 1] = rui[i] + a[i];
    }

    SegmentTree<ll> seg(
        rui, [](ll x, ll y) { return min(x, y); }, LLINF);

    vector<pii> rs;
    for (int i = 0; i + 2 <= n; i++) {
        if (seg.query(i + 2, n + 1) >= rui[i]) continue;
        int l = i + 1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (seg.query(i + 2, mid + 1) < rui[i])
                r = mid;
            else
                l = mid;
        }
        assert(rui[r] < rui[i]);
        rs.emplace_back(i, r);
    }

    for (int i = 0; i < rs.size(); i++) {
        swap(rs[i].first, rs[i].second);
    }

    sort(all(rs));
    int ans = 0;
    if (!rs.empty()) {
        int cur = rs[0].first;
        for (int i = 1; i < rs.size(); i++) {
            if (rs[i].second >= cur) {
                ans++;
                cur = rs[i].first;
            }
        }
        ans++;
    }
    cout << n - ans << endl;
    return;
}

int main() {
    fastio();
    if (!multitest) {
        solve();
    } else {
        cerr << "[Warning] Multi testcase mode on" << endl;
        int t;
        cin >> t;
        while (t--)
            solve();
    }
    return 0;
}