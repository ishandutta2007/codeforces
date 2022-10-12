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

template<typename T>
struct rmq {

    vector<vector<T>> tree;

    // runs in O(nlogn).
    rmq(vector<T>& data) {
        int n = data.size();
        int h = n == 0 ? 0 : ceil(log2(n));
        tree.assign(h+1, vector<T>(n));
        tree[0] = data;
        for (int i = 1; i <= h; i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                tree[i][j] = min(tree[i-1][j], tree[i-1][j+(1<<(i-1))]);
    }

    // returns the minimum of the array on the interval [a..b] in O(1) time.
    T query(int a, int b) {
        int n = floor(log2(b-a+1));
        return min(tree[n][a], tree[n][b-(1<<n)+1]);
    }
};

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); for (auto& x : a) cin >> x;
        vector<int> f(n+5);
        bool v = 1;
        for (auto& x : a) {
            f[x]++;
            v = v && f[x] <= (n+1)/2;
        }
        if (!v) {
            cout << "-1\n"; continue;
        }
        f.assign(n+5, 0);
        debug(a);
        f[a[0]]++; f[a[n-1]]++;
        int runs = 1;
        for (int i = 0; i < n-1; i++)
            if (a[i] == a[i+1]) f[a[i]] += 2, runs++;
        int bad = -1;
        debug(runs, f[1]);
        for (auto& x : a)
            if (f[x]-2 > runs-1)
                bad = x;
        if (bad == -1) {
            cout << runs-1 << "\n";
            continue;
        }
        while (f[bad]-2 > runs-1)
            runs++;
        cout << runs-1 << "\n";
    }
}