#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

template<ll M>
struct modint {

    static ll _reduce(ll n) {
        constexpr static ll b = -1ull/M;
        ll r = n-(ll)(__uint128_t(b)*n>>64)*M; return r >= M ? r-M : r;
    }

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = _reduce(n*n))
            if (k&1) r = _reduce(r*n);
        return r;
    }

    ll v; modint(ll n = 0) : v(_reduce(n)) { v += (M&0-(v<0)); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
    modint& operator*=(const modint n) { v = _reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = _reduce(v*_pow(n.v, M-2)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const { return _pow(v, k); }
    modint inv() const { return _pow(v, M-2); }
};

// combined data structure for various ancestor-related queries.

struct ancestor {

    vector<int> vin, vout, d;
    vector<vector<int>> adj, p;
    int n, t = 0, e;

    void dfs(int i, int v) {
        vin[i] = t++;
        p[i][0] = v, d[i] = d[v]+1;
        for (int j = 1; j <= e; j++)
            p[i][j] = p[p[i][j-1]][j-1];
        for (auto& j : adj[i])
            if (j != v) dfs(j, i);
        vout[i] = t-1;
    }

    // accepts an adjecency list. can include or exlude parents, it works either way.
    // constructor runs in O(nlogn) time.
    ancestor(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (adj.empty()) return;
        vin.resize(n), vout.resize(n), d.assign(n, 0);
        e = ceil(log2(n));
        p.assign(n, vector<int>(e+1));
        dfs(root, root);
    }

    // returns true if i is an ancestor of j in O(1) time.
    bool is_ancestor(int i, int j) const {
        return vin[i] <= vin[j] && vout[i] >= vout[j];
    }

    // returns the k'th ancestor of i O(logk) time.
    int ktha(int i, int k) const {
        while (k) {
            int j = k&-k;
            i = p[i][__builtin_ctz(j)];
            k -= j;
        }
        return i;
    }

    // returns the LCA of i and j in O(logn) time.
    int lca(int i, int j) const {
        if (is_ancestor(i, j)) return i;
        if (is_ancestor(j, i)) return j;
        for (int k = e; k >= 0; k--)
            if (!is_ancestor(p[i][k], j))
                i = p[i][k];
        return p[i][0];
    }

    // returns the vertex one step along the path from i to j in O(logn) time.
    int step(int i, int j) const {
        return is_ancestor(i, j) ? ktha(j, d[j]-d[i]-1) : p[i][0];
    }

    // returns the number of edges between i and j in O(logn) time.
    int dist(int i, int j) {
        return d[i]+d[j]-2*d[lca(i, j)];
    }
};

struct hld_single {

    vector<vector<int>> adj;
    vector<int> vin, vout, head, p, d, sz;
    vector<bool> hvy;
    int n, t = 0;

    void _assign(int i, int v) {
        if ((p[i] = v) != -1) d[i] = d[v]+1;
        for (int j : adj[i])
            if (j != v) _assign(j, i), sz[i] += sz[j];
        int b = -1;
        for (int j : adj[i])
            if (j != v && (b == -1 || sz[j] > sz[b])) b = j;
        if (b != -1) hvy[b] = 1;
    }

    void _dfs(int i) {
        vin[i] = t++;
        head[i] = hvy[i] ? head[p[i]] : i;
        for (int j : adj[i])
            if (j != p[i] && hvy[j]) _dfs(j);
        for (int j : adj[i])
            if (j != p[i] && !hvy[j]) _dfs(j);
        vout[i] = t-1;
    }

    hld_single(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (_adj.size() == 0) return;
        vin.resize(n), vout.resize(n), head.resize(n);
        p.assign(n, -1), d.assign(n, 0), sz.assign(n, 1), hvy.assign(n, 0);
        _assign(root, -1), _dfs(root);
    }

    // returns a single interval (inclusive of both ends) which
    // represents the subtree of vertex i.
    array<int, 2> subtree(int i) const {
        return {vin[i], vout[i]};
    }

    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to the root (inclusive of both).
    vector<array<int, 2>> path(int i) const {
        vector<array<int, 2>> out;
        for (; i != -1; i = p[head[i]])
            out.push_back({vin[head[i]], vin[i]});
        reverse(out.begin(), out.end());
        return out;
    }

    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to vertex j (inclusive of both).
    vector<array<int, 2>> path(int i, int j) const {
        vector<array<int, 2>> tmp, out;
        for (; head[i] != head[j]; j = p[head[j]]) {
            if (d[head[i]] > d[head[j]]) swap(i, j);
            tmp.push_back({vin[head[j]], vin[j]});
        }
        if (d[i] > d[j]) swap(i, j);
        tmp.push_back({vin[i], vin[j]});
        sort(tmp.begin(), tmp.end());
        for (auto [l, r] : tmp) {
            if (!out.empty() && out.back()[1] == l-1)
                l = out.back()[0], out.pop_back();
            out.push_back({l, r});
        }
        return out;
    }
};

struct suffixarray {

    // s = original string, a = suffix array
    // r = inverse suffix array (i.e. a[r[i]] = i)
    // lcp[i] = length of longest common prefix of a[i] and a[i+1]
    vector<int> s, a, r, lcp;

    // runs in O(nlogn) time.
    template<typename it>
    suffixarray(it first, it last) : s(first, last) {

        // construct a, r
        int n = s.size()+1, c = 1, j = 1, b;
        map<int, vector<int>> grp;
        vector<int> rc(n);
        r.resize(n); a.resize(n);
        for (int i = 0; i < n-1; i++)
            grp[s[i]].push_back(i);
        a[0] = n-1, r[n-1] = 0;
        for (auto& [_, v] : grp) {
            for (auto& i : v)
                r[i] = c, a[j++] = i;
            c++;
        }
        vector<vector<int>> cnt(n);
        for (int k = 1; k < 2*n; k <<= 1) {
            for (int i = 0; i < n; i++)
                cnt[r[b = (a[i]+2*n-k)%n]].push_back(b);
            c = -1, j = 0;
            for (auto& v : cnt) {
                for (int i = 0; i < v.size(); i++) {
                    if (i == 0 || r[(v[i]+k)%n] != r[(v[i-1]+k)%n]) c++;
                    rc[v[i]] = c, a[j++] = v[i];
                } v.clear();
            } swap(r, rc);
        }
        a.erase(a.begin()), r.erase(r.end()-1);

        // construct lcp
        lcp.resize(--n-1), c = 0;
        for (int i = 0; i < n; i++) {
            if (--r[i] == 0) continue;
            j = a[r[i]-1];
            while (max(i, j)+c < n && s[i+c] == s[j+c]) c++;
            lcp[r[i]-1] = c, c = max(0, c-1);
        }
    }

    suffixarray(string str) : suffixarray(str.begin(), str.end()) {}

    // returns a pair [l, r] such that all suffixes starting at
    // indices in the suffix array a[l..r] contain the input as a prefix,
    // runs in O(mlogn) time where m is the input size.
    template<typename it>
    pair<int, int> interval(it first, it last) const {
        auto cmp = [&](int p) {
            for (int i = 0; first+i != last; i++) {
                if (p+i >= s.size() || s[p+i] < first[i]) return -1;
                if (s[p+i] > first[i]) return 1;
            } return 0;
        };
        int m, l, x = 0, y = s.size();
        while (x < y)
            if (cmp(a[m = (x+y)/2]) == -1) x = m+1;
            else y = m;
        l = x, x = -1, y = s.size()-1;
        while (x < y)
            if (cmp(a[m = (x+y+1)/2]) == 1) y = m-1;
            else x = m;
        return {l, x};
    }

    pair<int, int> interval(string str) const {
        return interval(str.begin(), str.end());
    }
};

template<typename it, typename bin_op>
struct sparse_table {

    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op f;

    sparse_table(it first, it last, bin_op op) : t(1), f(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }

    // returns f(a[l..r]) in O(1) time
    T query(int l, int r) {
        int h = floor(log2(r-l+1));
        return f(t[h][l], t[h][r-(1<<h)+1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string sp; cin >> sp;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    hld_single hld(adj);
    ancestor anc(adj);
    string s(sp);
    for (int i = 0; i < n; i++)
        s[hld.vin[i]] = sp[i];
    string t = s; reverse(all(t));
    s += '$'+t;
    suffixarray suf(s);
    sparse_table raw_lcp(all(suf.lcp), [](int i, int j){ return min(i, j); });
    debug(s);

    auto getpath = [&](int x, int y) {
        vector<array<int, 2>> a;
        int z = anc.lca(x, y);
        if (z != x)
            for (auto& [l, r] : hld.path(x, anc.step(z, x)))
                a.pb({2*n-r, 2*n-l});
        reverse(all(a));
        for (auto& [l, r] : hld.path(y, z)) a.pb({l, r});
        return a;
    };

    auto lcp = [&](int x, int y) {
        if (x == y) return n;
        x = suf.r[x], y = suf.r[y];
        if (x > y) swap(x, y);
        return raw_lcp.query(x, y-1);
    };

    int m; cin >> m;
    while (m--) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--, c--, d--;
        debug(a, b, c, d);
        auto va = getpath(a, b), vb = getpath(c, d);
        debug(va, vb);
        for (auto& [l, r] : va)
            debug(s.substr(l, r-l+1));
        for (auto& [l, r] : vb)
            debug(s.substr(l, r-l+1));
        int i = 0, j = 0;
        int ans = 0;
        while (i < va.size() && j < vb.size()) {
            int l = min(
                lcp(va[i][0], vb[j][0]),
                min(va[i][1]-va[i][0], vb[j][1]-vb[j][0])+1
            );
            debug(i, j, va[i][0], vb[j][0], l);
            ans += l;
            if (l == 0) break;
            va[i][0] += l;
            vb[j][0] += l;
            if (va[i][0] > va[i][1]) i++;
            if (vb[j][0] > vb[j][1]) j++;
        }
        cout << ans << "\n";
    }
}