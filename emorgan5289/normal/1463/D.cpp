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

template<int _N, typename T>
struct segtree {

    constexpr static T max_T = numeric_limits<T>::max();
    constexpr static T min_T = numeric_limits<T>::min();
    constexpr static int H = int(ceil(log2(_N))), N = 1<<H;

    struct node { T s, l, r; } t[2*N];
    node merge(node x, node y) {
        return {x.s+y.s, std::min(x.l, y.l), std::max(x.r, y.r)};
    }

    T u[2*N]; bool f[2*N]; int a[2*N], b[2*N];
    segtree() {
        fill(t, t+2*N, node({0, 0, 0}));
        fill(f, f+2*N, 0), fill(u, u+2*N, 0);
        iota(a+N, a+2*N, 0), iota(b+N, b+2*N, 0);
        for (int i = N-1; i > 0; i--)
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
        if (i < N) apply(2*i, u[i], f[i]), apply(2*i+1, u[i], f[i]);
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
        for (int x = H; x >= 0; x--) push((N+i)>>x);
        return t[N+i].s;
    }

    void set(int l, int r, T x) { _upd(l, r, x, 1); }
    void add(int l, int r, T x) { _upd(l, r, x, 0); }
    void set(int i, T x) { set(i, i, x); }
    void add(int i, T x) { add(i, i, x); }
    T sum(int l, int r) { return _qry(l, r).s; }
    T min(int l, int r) { return _qry(l, r).l; }
    T max(int l, int r) { return _qry(l, r).r; }
};

const int N = 2e5+5;
int b[N], f[2*N];
segtree<2*N, int> s1, s2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        s1.set(1, 2*n, 0);
        s2.set(1, 2*n, 0);
        fill(f+1, f+2*n+1, 0);
        for (int i = 0; i < n; i++)
            cin >> b[i], f[b[i]]++;
        for (int i = 1; i <= 2*n; i++)
            s1.add(i, 2*n, f[i] ? -1 : 1);
        int l = 1, r = 2*n, ans = 0;
        if (s1.min(1, 2*n) >= 0) ans++;
        for (int x = 1; x <= n; x++, l++, r--) {
            while (!f[l]) l++;
            while (f[r]) r--;
            s1.add(l, 2*n, 1), s1.add(r, 2*n, -1);
            s2.add(l, 2*n, 1), s2.add(r, 2*n, -1);
            if (min(s1.min(1, 2*n), s2.min(1, 2*n)) >= 0) ans++;
        }
        cout << ans << "\n";
    }
}