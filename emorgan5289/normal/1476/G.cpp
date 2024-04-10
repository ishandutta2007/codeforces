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

const int N = 1e5+5, S = 2000;
int a[N], f[N], grp[N];
int ans[N];
int nxt[N], prv[N];
vector<array<int, 3>> upd;
vector<array<int, 5>> qry;

void ins(int x) {
    int i = ++f[x];
    grp[i-1]--, grp[i]++;
    if (grp[i] == 1 && grp[i-1] == 0) {
        nxt[prv[i-1]] = i;
        prv[nxt[i-1]] = i;
        nxt[i] = nxt[i-1];
        prv[i] = prv[i-1];
    }
    else if (grp[i] == 1) {
        prv[nxt[i-1]] = i;
        nxt[i] = nxt[i-1];
        prv[i] = i-1;
        nxt[i-1] = i;
    }
    else if (grp[i-1] == 0) {
        prv[i] = prv[i-1];
        nxt[prv[i]] = i;
    }
    // debug("ins", x, vector(nxt, nxt+10));
}

void rem(int x) {
    int i = --f[x];
    grp[i+1]--, grp[i]++;
    if (grp[i] == 1 && grp[i+1] == 0) {
        prv[nxt[i+1]] = i;
        nxt[prv[i+1]] = i;
        prv[i] = prv[i+1];
        nxt[i] = nxt[i+1];
    }
    else if (grp[i] == 1) {
        nxt[prv[i+1]] = i;
        prv[i] = prv[i+1];
        nxt[i] = i+1;
        prv[i+1] = i;
    }
    else if (grp[i+1] == 0) {
        nxt[i] = nxt[i+1];
        prv[nxt[i]] = i;
    }
    // debug("rem", x, vector(nxt, nxt+10));
}

bool cmp(array<int, 5> x, array<int, 5> y) {
    if (x[0]/S != y[0]/S) return x[0] < y[0];
    if (x[1]/S != y[1]/S) return x[1] < y[1];
    return x[2] < y[2];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int q = 0;
    // left, right, upds processed
    int x = 0, y = -1, z = -1;
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, k; cin >> l >> r >> k; l--, r--;
            qry.pb({l, r, z, k, q++});
        } else {
            int p, k; cin >> p >> k; p--;
            upd.pb({p, a[p], k});
            a[p] = k, z++;
        }
    }
    sort(all(qry), cmp);
    grp[0] = n;
    nxt[0] = n+1;
    prv[0] = 0;
    prv[n+1] = 0;
    nxt[n+1] = n+1;
    for (auto& [l, r, t, k, i] : qry) {
        debug(l, r, t);
        while (x > l) ins(a[--x]);
        while (y < r) ins(a[++y]);
        while (x < l) rem(a[x++]);
        while (y > r) rem(a[y--]);
        while (z < t) {
            auto [p, u, v] = upd[++z];
            a[p] = v;
            if (l <= p && p <= r)
                ins(v), rem(u);
        }
        while (z > t) {
            auto [p, u, v] = upd[z--];
            a[p] = u;
            if (l <= p && p <= r)
                ins(u), rem(v);
        }
        ans[i] = inf;
        // debug(i, k);
        // debug(vector(grp+1, grp+n+1));
        int o = nxt[0], sz = 0;
        for (int j = nxt[0]; j != n+1; j = nxt[j]) {
            sz += grp[j];
            while (o < j && sz-grp[o] >= k) {
                sz -= grp[o];
                o = nxt[o];
            }
            // debug(sz, k, ans[i]);
            if (sz >= k) cmin(ans[i], j-o);
        }
        // debug(ans[i]);
    }
    for (int i = 0; i < q; i++)
        cout << (ans[i] == inf ? -1 : ans[i]) << "\n";
}