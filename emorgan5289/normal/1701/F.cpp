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

constexpr int N = 1<<19;

struct segtree {

    struct node {
        ll value, active;
    };

    node tree[2*N];
    ll a[2*N], b[2*N], u[2*N];

    void init() {
        for (int i = 0; i < N; i++)
            a[N+i] = b[N+i] = i;
        for (int i = N-1; i > 0; i--)
            a[i] = a[2*i], b[i] = b[2*i+1];
        fill(u, u+2*N, 0);
        fill(tree, tree+2*N, node({0, 0}));
    }

    node merge(node x, node y) {
        return {x.value+y.value, x.active+y.active};
    }

    void push(int i) {
        tree[i].value += u[i]*tree[i].active;
        if (i < N) {
            u[2*i] += u[i];
            u[2*i+1] += u[i];
        }
        u[i] = 0;
    }

    void range_add(int l, int r, ll x, int i = 1) {
        if (l <= a[i] && r >= b[i])
            u[i] += x;
        push(i);
        if (l > b[i] || r < a[i] || (l <= a[i] && r >= b[i]))
            return;
        range_add(l, r, x, 2*i);
        range_add(l, r, x, 2*i+1);
        tree[i] = merge(tree[2*i], tree[2*i+1]);
    }

    void point_add(int i, ll x, ll d) {
        int j = 1;
        while (j != N+i) {
            push(j);
            tree[j].value += x;
            tree[j].active += d;
            if (a[2*j+1] <= i)
                j = 2*j+1;
            else
                j = 2*j;
        }
        push(j);
        tree[j].value += x;
        tree[j].active += d;
    }

    node range_sum(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return {0, 0};
        return merge(range_sum(l, r, 2*i), range_sum(l, r, 2*i+1));
    }

} ival_l, ival_r;

int f[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ival_l.init();
    ival_r.init();
    ll q, d; cin >> q >> d;
    debug(q, d);
    ll ans = 0;
    while (q--) {
        ll i; cin >> i;
        ll l = max(0ll, i-d), r = min(ll(N-1), i+d);
        debug(i, f[i]);
        if (f[i]) {
            // remove

            auto ar = ival_l.range_sum(i+1, r).active;
            auto al = ival_r.range_sum(l, i-1).active;

            auto vr = ival_l.range_sum(i+1, N-1).value;
            auto vl = ival_r.range_sum(0, i-1).value;

            ival_l.point_add(i, -ar, -1);
            ival_l.range_add(l, i-1, -1);
            ival_r.point_add(i, -al, -1);
            ival_r.range_add(i+1, r, -1);

            ans -= ar*(ar-1)/2 + al*(al-1)/2;
            ans -= ival_r.range_sum(0, N-1).value - vl - vr;
        } else {
            // add

            auto ar = ival_l.range_sum(i+1, r).active;
            auto al = ival_r.range_sum(l, i-1).active;

            auto vr = ival_l.range_sum(i+1, N-1).value;
            auto vl = ival_r.range_sum(0, i-1).value;

            ans += ar*(ar-1)/2 + al*(al-1)/2;
            ans += ival_r.range_sum(0, N-1).value - vl - vr;

            ival_l.point_add(i, ar, 1);
            ival_l.range_add(l, i-1, 1);
            ival_r.point_add(i, al, 1);
            ival_r.range_add(i+1, r, 1);
        }
        f[i] ^= 1;

        debug(ival_l.range_sum(0, N-1).active, ival_l.range_sum(0, N-1).value);
        debug(ival_r.range_sum(0, N-1).active, ival_r.range_sum(0, N-1).value);

        cout << ans << "\n";
    }
}