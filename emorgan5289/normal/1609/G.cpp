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

const int N = 1<<18;
segtree<N, ll> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, q; cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll b_sum = 0;
    s.set(m, N-1, inf_ll);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b_sum += b[i];
        s.add(i, i == 0 ? b[i] : b[i]-b[i-1]);
    }
    while (q--) {
        ll t, k, d; cin >> t >> k >> d;
        if (t == 1) {
            for (int i = 0; i < k; i++)
                a[n-k+i] += (i+1)*d;
        } else {
            b_sum += d*k*(k+1)/2;
            s.add(m-k, m-1, d);
        }

        ll ans = b_sum-s.sum(0, m-1);
        int x = 0;
        for (int i = 0; i < n; i++) {
            int y;
            if (i == n-1) {
                y = m-1;
            } else {
                int r = 1;
                while (s.a[r] != s.b[r]) {
                    s.push(r);
                    // debug(s.a[r], s.b[r]);
                    r = 2*r+1;
                    s.push(r);
                    // debug(s.a[r], s.b[r], a[i+1]-a[i], s.t[r].l);
                    if (s.a[r] >= m || s.t[r].l > a[i+1]-a[i]) {
                        r--;
                        s.push(r);
                    }
                }
                y = s.a[r];
            }
            debug(x, y, s.sum(x, y), a[i]*(y-x+1));
            ans += s.sum(0, y);
            ans += a[i]*(y-x+1);
            x = y;
        }

        cout << ans << "\n";
    }
}