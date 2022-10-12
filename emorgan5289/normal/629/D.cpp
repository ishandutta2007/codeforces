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

template<int _N, typename T>
struct segtree {

    constexpr static T max_T = numeric_limits<T>::max();
    constexpr static T min_T = numeric_limits<T>::min();
    constexpr static int N = 1<<int(ceil(log2(_N)));

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
        if (!u[i] && !f[i]) return;
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

    void set(int l, int r, T x) { _upd(l, r, x, 1); }
    void add(int l, int r, T x) { _upd(l, r, x, 0); }
    void set(int i, T x) { set(i, i, x); }
    void add(int i, T x) { add(i, i, x); }
    T sum(int l, int r) { return _qry(l, r).s; }
    T min(int l, int r) { return _qry(l, r).l; }
    T max(int l, int r) { return _qry(l, r).r; }
    T get(int i) { return _qry(i, i).s; }
};

template<typename it1, typename it2>
void compress(it1 first, it1 last, it2 result) {
    typedef typename remove_reference<decltype(*first)>::type T;
    map<T, vector<it2>> m;
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [x, v] : m) {
        for (auto& i : v) *i = t;
        t++;
    }
}

typedef long double ld;

const int N = 1e5+5;
const ld pi = acos(-1);
ll a[N], p[N];

segtree<N, ld> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ld r, h; cin >> r >> h;
        a[i] = h*r*r;
    }
    compress(a, a+n, p);
    for (int i = 0; i < n; i++)
        s.set(p[i], a[i]*pi+s.max(0, p[i]-1));
    cout << setprecision(25) << fixed << s.max(0, n-1) << "\n";
}