#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxn = 1 << 20;
const ll inf = 1ll << 60;
ll st[maxn << 1], lazy[maxn];

void apply(int i, ll v) {
    st[i] += v;
    if (i < maxn) lazy[i] += v;
}

void build(int i) {
    while (i >>= 1) {
        st[i] = lazy[i] + max(st[i << 1], st[i << 1 | 1]);
    }
}

void update(int l, int r, ll v) {
    int l0 = l += maxn, r0 = r += maxn;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) apply(l++, v);
        if (r & 1) apply(--r, v);
    }
    build(l0);
    build(r0 - 1);
}

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    vt<pii> a(n), b(m);
    vt<vt<int>> c(l, vt<int>(3));
    for (pii &p : a) cin >> p.fi >> p.se;
    for (pii &p : b) cin >> p.fi >> p.se;
    for (auto &v : c) {
        for (int &x : v) cin >> x;
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));

    {
        vt<pii> b1{{0, 0}};
        for (int i = 0; i < m; i++) {
            if (i && b[i - 1].fi == b[i].fi) continue;

            while (b1.back().se >= b[i].se) b1.pop_back();
            b1.push_back(b[i]);
        }
        b = b1;
        m = sz(b);
    }
    for (int i = 1; i < m; i++) {
        update(b[i - 1].fi, b[i].fi, -b[i].se);
    }
    update(b.back().fi, maxn, -inf);

    ll ans = -inf;
    int ci = 0;
    for (int i = 0; i < n; i++) {
        for (; ci < l && c[ci][0] < a[i].fi; ci++) {
            update(c[ci][1], maxn, c[ci][2]);
        }

        ans = max(ans, st[1] - a[i].se);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}