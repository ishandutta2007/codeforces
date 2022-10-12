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

auto now() {
    return chrono::steady_clock::now();
}

template<typename T>
string delta(T a, T b) {
    return to_string(chrono::duration_cast<chrono::microseconds>(b-a).count())+"us";
}

struct flat_map {

    vector<int> key, value;

    flat_map() {}

    flat_map(map<int, int> m) {
        for (auto& [p, q] : m) {
            key.pb(p);
            value.pb(q);
        }
    }

    int query(int x) {
        // auto t = now();
        int r = value[lower_bound(all(key), x)-key.begin()-1];
        // debug("q", delta(t, now()), key.size());
        return r;
    }

};

const int N = 2e5+5, S = 5000;
int n, m, a[N];
flat_map k[N/S+1], o[N/S+1];

map<int, int> v_to_m(vector<array<int, 3>>& v) {
    int c = 0;
    sort(all(v));
    map<int, int> ret;
    for (auto& [p, q, _] : v) {
        c += q;
        ret[p] = c;
    }
    ret[-1] = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto t = now();

    vector<array<int, 3>> bv;
    for (int i = 0; i < m; i++)
        bv.pb({a[i], 1, 0});
    auto base = flat_map(v_to_m(bv));

    debug("base", delta(t, now()));
    t = now();

    for (int i = 0; i < (n/S+1); i++) {
        bv.clear();
        for (int j = i*S; j < (i+1)*S && j < n-m+1; j++) {
            bv.pb({a[j], -1, j-i*S});
            bv.pb({a[j+m], 1, j-i*S});
        }
        k[i] = flat_map(v_to_m(bv));

        // auto tmp = o[i] = k[i];
        // for (auto& [p, q] : tmp) q = 0;
        // for (auto& [p, q] : o[i]) q = 0;
        // for (int j = i*S; j < (i+1)*S-1 && j < n-m+1; j++) {
        //     auto it = o[i].begin();
        //     for (auto& [p, q] : tmp) {
        //         if (a[j] <= p) q--;
        //         if (a[j+m] <= p) q++;
        //         cmin(it->second, q);
        //         it++;
        //     }
        // }
        // debug(i, o[i]);
        // o[i].clear();

        // debug(i, bv);
        segtree<S+5, int> s;
        map<int, int> tmp;
        for (auto& [p, q, j] : bv) {
            s.add(j, S+2, q);
            tmp[p] = min(0, s.min(0, S));
        }
        tmp[-1] = 0;
        o[i] = flat_map(tmp);
        // debug(i, o[i]);
    }

    debug("init", delta(t, now()));
    t = now();

    // query {l, r}
    // take all u's up to and including i, where l <= i <= r

    int q; cin >> q;
    int last = 0;
    while (q--) {
        int l, r, x; cin >> l >> r >> x; l--, r--;
        x ^= last;

        if (q%1000 == 0) debug(q);

        // debug(l, r, x);

        // debug("a", delta(t, now()));
        // t = now();

        last = inf;
        int c = base.query(x);
        int j = 0;

        // debug("j == 0", j, c);

        // debug("b", delta(t, now()));
        // t = now();

        while (j/S < l/S) {
            // debug(k[j/S]);
            c += k[j/S].query(x);
            j += S;
        }

        // debug("j in group w/ l", j, c);

        // debug("c", delta(t, now()));
        // t = now();

        while (j < l) {
            if (a[j] < x) c--;
            if (a[j+m] < x) c++;
            j++;
        }

        // debug("j == l", j, c);

        // debug("d", delta(t, now()));
        // t = now();

        if (j/S < r/S) {

            while (j%S != 0) {
                cmin(last, c);
                if (a[j] < x) c--;
                if (a[j+m] < x) c++;
                j++;
            }

            // debug("j%S == 0", j, c);

            // debug("e", delta(t, now()));
            // t = now();
            
            while (j/S < r/S) {
                cmin(last, c + o[j/S].query(x));
                c += k[j/S].query(x);
                j += S;
            }

        }

        // debug("j close to r", j, c);

        // debug("f", delta(t, now()));
        // t = now();

        while (j < r) {
            cmin(last, c);
            c -= (a[j] < x);
            c += (a[j+m] < x);
            j++;
        }

        // debug("j == r", j, c);

        // debug("g", delta(t, now()));
        // t = now();

        cmin(last, c);

#ifndef LOCAL
        cout << last << "\n";
#endif
    }

    debug("queries", delta(t, now()));
    t = now();
}