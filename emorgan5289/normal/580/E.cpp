#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll p = 53777, mod = 1e9+7;
ll pw[1000000];

// returns (b^r)%m, runs in O(logr) time.
template<typename T>
T powmod(T b, T r, T m) {
    T out = 1;
    for (T t = 1; t <= r; t <<= 1) {
        if (r&t) out = (out*b)%m;
        b = (b*b)%m;
    }
    return out;
}

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

struct segtree {

    struct node {
        int w; ll h;
    };

    node combine(node x, node y) {
        return {x.w+y.w, (x.h+pw[x.w]*y.h)%mod};
    }

    constexpr static node identity = {0, 0};

    vector<int> a, b;
    vector<node> tree;
    vector<int> u;
    int n;

    segtree(vector<int>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, -1);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {1, v[i-n]};
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

    void push(int i) {
        if (u[i] == -1) return;
        // debug(i, u[i], (pw[tree[i].w])%mod, (1+mod-p)%mod);
        tree[i].h = (u[i]*(1+mod-pw[tree[i].w])%mod)*inv(1+mod-p, mod)%mod;
        if (i < n) {
            u[2*i] = u[2*i+1] = u[i];
        }
        u[i] = -1;
    }

    void update(int l, int r, int x, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] = x;
        }
        push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i])
            return;
        update(l, r, x, 2*i);
        update(l, r, x, 2*i+1);
        tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k; m += k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c; v[i] = c-'0';
    }
    pw[0] = 1;
    for (int i = 1; i < 1000000; i++)
        pw[i] = pw[i-1]*p%mod;
    segtree s(v);
    while (m--) {
        int t, l, r, d; cin >> t >> l >> r >> d; l--, r--;
        if (t == 1) s.update(l, r, d);
        else {
            ll a = s.query(l, r-d).h, b = s.query(l+d, r).h;
            cout << (a == b ? "YES" : "NO") << "\n";
        }
    }
}