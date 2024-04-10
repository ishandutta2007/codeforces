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
#define debug(...)
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
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i]) return;
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

const int N = 5e5+5;
int a[N], dp[N];
segtree<N> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> r;
        vector<vector<int>> p(n);
        for (int i = n-1; i >= 0; i--) {
            while (!r.empty() && a[r.back()] < a[i]) r.pop_back();
            if (!r.empty()) p[r.back()].pb(i);
            r.pb(i);
        }
        s.set(0, N-1, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = s.max(0, a[i])+1;
            if (i > 0) cmax(dp[i], 2);
            s.set(a[i], dp[i]);
            for (auto& j : p[i]) s.set(a[j], dp[j]+1);
        }
        cout << *max_element(dp, dp+n) << "\n";
    }
}