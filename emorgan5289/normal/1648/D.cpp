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

template<int N, typename T = int>
struct segtree {

    constexpr static T max_T = numeric_limits<T>::max();
    constexpr static T min_T = numeric_limits<T>::min();
    constexpr static int H = int(ceil(log2(N))), _N = 1<<H;

    struct node { T s, l, r; } t[2*_N];
    node merge(node x, node y) {
        return {x.s+y.s, std::min(x.l, y.l), std::max(x.r, y.r)};
    }

    T u[2*_N]; bool f[2*_N]; int a[2*_N], b[2*_N];
    segtree() {
        fill(t, t+2*_N, node({0, 0, 0}));
        fill(f, f+2*_N, 0), fill(u, u+2*_N, 0);
        iota(a+_N, a+2*_N, 0), iota(b+_N, b+2*_N, 0);
        for (int i = _N-1; i > 0; i--)
            a[i] = a[2*i], b[i] = b[2*i+1];
    }

    void apply(int i, T x, bool ins) {
        if (ins) u[i] = x, f[i] = 1;
        else u[i] += x;
    }

    void push(int i) {
        if (!f[i] && !u[i]) return;
        if (f[i]) t[i] = {0, 0, 0};
        t[i].s += u[i]*(b[i]-a[i]+1), t[i].l += u[i], t[i].r += u[i];
        if (i < _N) apply(2*i, u[i], f[i]), apply(2*i+1, u[i], f[i]);
        u[i] = f[i] = 0;
    }

    void _upd(int l, int r, T x, bool ins, int i = 1) {
        if (l <= a[i] && r >= b[i]) apply(i, x, ins);
        push(i);
        if (l > b[i] || r < a[i] || (l <= a[i] && r >= b[i])) return;
        _upd(l, r, x, ins, 2*i), _upd(l, r, x, ins, 2*i+1);
        t[i] = merge(t[2*i], t[2*i+1]);
    }

    node _qry(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i]) return t[i];
        if (l > b[i] || r < a[i]) return {0, max_T, min_T};
        return merge(_qry(l, r, 2*i), _qry(l, r, 2*i+1));
    }

    T get(int i) {
        for (int x = H; x >= 0; x--) push((_N+i)>>x);
        return t[_N+i].s;
    }

    void set(int l, int r, T x) { _upd(l, r, x, 1); }
    void add(int l, int r, T x) { _upd(l, r, x, 0); }
    void set(int i, T x) { set(i, i, x); }
    void add(int i, T x) { add(i, i, x); }
    T sum(int l, int r) { return _qry(l, r).s; }
    T min(int l, int r) { return _qry(l, r).l; }
    T max(int l, int r) { return _qry(l, r).r; }
};

const int N = 1<<19;
segtree<N, ll> s;

struct bruh_moment {

    struct node {
        ll maxp, maxq, ans;
    };

    node combine(node x, node y) {
        return {
            max(x.maxp, y.maxp),
            max(x.maxq, y.maxq),
            max({x.ans, y.ans, x.maxp+y.maxq})
        };
    }

    constexpr static node identity = {-inf_ll, -inf_ll, -inf_ll};

    vector<int> a, b;
    vector<node> tree;
    int n;

    bruh_moment(vector<ll>& p, vector<ll>& q) {

        n = 1<<int(ceil(log2(p.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < p.size()) {
                    tree[i] = {p[i-n], q[i-n], p[i-n]+q[i-n]};
                } else {
                    tree[i] = identity;
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    node query(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, nq; cin >> n >> nq;
    array<vector<ll>, 3> a;
    for (int i = 0; i < 3; i++) {
        a[i].resize(n+1);
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for (int i = 1; i < n; i++) {
        a[0][i] += a[0][i-1];
        a[1][n-i-1] += a[1][n-i];
        a[2][n-i-1] += a[2][n-i];
    }

    vector<array<ll, 3>> e(nq);

    for (int i = 0; i < nq; i++) {
        ll l, r, k; cin >> l >> r >> k;
        e[i] = {l-1, r-1, k};
    }

    for (int i = 0; i < n; i++)
        s.set(i, a[2][i]-a[1][i+1]);

    sort(all(e), greater<>());
    for (auto& [l, r, k] : e) {
        debug(l, r, k);
        debug(s.max(l, min(n-1, r+1))-k);
        int j = max(0ll, l-1);
        s.set(j, max(s.get(j), s.max(l, r)-k));
    }

    vector<ll> p(n), q(n);
    for (int i = 0; i < n; i++) {
        p[i] = a[0][i] + a[1][i];
        q[i] = s.get(i);
    }

    debug(p);
    debug(q);

    // answer is max of p[i] + q[j] + k where i <= j
    // and [i, j] is a subinterval of [l, r] with weight k

    bruh_moment bruh(p, q);
    ll ans = -inf_ll;
    for (auto& [l, r, k] : e) {
        cmax(ans, bruh.query(l, r).ans-k);
    }
    cout << ans << "\n";
}