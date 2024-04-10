#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<ll _N, typename T>
struct segtree {

    constexpr static ll N = 1<<ll(ceil(log2(_N)));

    T t[2*N];
    T merge(T x, T y) {
        return x.s+y.s;
    }

    T u[2*N]; bool f[2*N]; ll a[2*N], b[2*N];
    segtree() {
        fill(t, t+2*N, 0);
        fill(f, f+2*N, 0), fill(u, u+2*N, 0);
        iota(a+N, a+2*N, 0), iota(b+N, b+2*N, 0);
        for (ll i = N-1; i > 0; i--)
            a[i] = a[2*i], b[i] = b[2*i+1];
    }

    void apply(ll i, T x) {
        u[i] = x, f[i] = 1;
    }

    void push(ll i) {
        t[i] = u[i]*(b[i]-a[i]+1);
        if (i < N) apply(2*i, u[i]), apply(2*i+1, u[i]);
        u[i] = f[i] = 0;
    }

    void _upd(ll l, ll r, T x, ll i = 1) {
        if (l <= a[i] && r >= b[i]) apply(i, x);
        if (f[i]) push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i]) return;
        _upd(l, r, x, 2*i), _upd(l, r, x, 2*i+1);
        t[i] = t[2*i]+t[2*i+1];
    }

    T _qry(ll l, ll r, ll i = 1) {
        if (f[i]) push(i);
        if (l <= a[i] && r >= b[i]) return t[i];
        if (l > b[i] || r < a[i]) return 0;
        return _qry(l, r, 2*i)+_qry(l, r, 2*i+1);
    }

    T get(ll i) {
        for (int x = 20; x >= 0; x--)
            if (f[(N+i)>>x]) push((N+i)>>x);
        return t[N+i];
    }

    T right(int l, ll y, ll i = 1) {
        if (f[i]) push(i);
        if (a[i] == b[i]) return i-N;
        ll left = _qry(l, N-1, 2*i);
        if (left <= y) return right(l, y-left, 2*i+1);
        return right(l, y, 2*i);
    }

    void set(ll l, ll r, T x) { _upd(l, r, x); }
    void set(ll i, T x) { set(i, i, x); }
};

const ll N = 2e5+5;
segtree<N, ll> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a; s.set(i, a);
    }
    while (q--) {
        ll t, x, y; cin >> t >> x >> y; x--;
        if (t == 1) {
            ll l = -1;
            for (ll i = 1<<20; i > 0; i /= 2)
                if (l+i < n && s.get(l+i) >= y)
                    l += i;
            if (l < x) s.set(l+1, x, y);
        } else {
            ll ans = 0;
            while (x < n) {
                x--;
                for (ll i = 1<<20; i > 0; i /= 2)
                    if (x+i < n && s.get(x+i) > y)
                        x += i;
                if (++x >= n) break;
                ll r = min(n, s.right(x, y))-1;
                ans += r-x+1, y -= s._qry(x, r);
                x = r+1;
            }
            cout << ans << "\n";
        }
    }
}