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

// Transform the contents of [first, last) into elements of [0..N],
// while preserving the ordering/equality relationship among indices into the data.
// Runs in O(nlogn).

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

template<typename it1, typename it2, typename cmp>
void compress(it1 first, it1 last, it2 result, cmp ord) {
    typedef typename remove_reference<decltype(*first)>::type T;
    map<T, vector<it2>, cmp> m(ord);
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [x, v] : m) {
        for (auto& i : v) *i = t;
        t++;
    }
}

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

const int N = 5e5+5;
ll a[N], b[N];
segtree<N, ll> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    a[0] = -inf, a[n+1] = 2*inf;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] -= i;
    compress(a, a+n+2, a);
    debug(vector(a, a+n+2));
    b[0] = 0, b[k+1] = n+1;
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    int ans = n-k;
    for (int i = 0; i <= k; i++) {
        int l = b[i], r = b[i+1];
        debug(l, r, a[l], a[r]);
        if (a[r] < a[l]) cout << "-1\n", exit(0);
        if (l+1 == r) continue;
        s.set(0, N-1, -inf);
        s.set(a[l], 0);
        for (int j = l+1; j < r; j++)
            s.set(a[j], s.max(0, a[j])+1);
        debug(s.max(0, a[r])+1);
        ans -= s.max(0, a[r]);
    }
    cout << ans << "\n";
}