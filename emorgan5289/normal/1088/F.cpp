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

const int N = 1<<19;
vector<int> adj[N];
ll a[N], ans = 0;
ll t[2*N];

void upd(int p, ll value) {
    debug(p, value);
    for (t[p += N] = value; p > 1; p >>= 1)
        t[p>>1] = min(t[p], t[p^1]);
}

ll qry(int l, int r) {
    debug(l, r);
    ll res = inf_ll;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) cmin(res, t[l++]);
        if (r&1) cmin(res, t[--r]);
    }
    return res;
}

void dfs(int i, int p, int x) {
    debug(i, p, x);
    if (x != 0) {
        ll y = qry(x-1, x);
        for (int j = 1; (1<<(j-1)) <= x; j++)
            cmin(y, qry(max(0, x-(1<<j)), x-(1<<(j-1))+1)*(j+1));
        debug(y);
        ans += a[i]+y;
    }
    upd(x, a[i]);
    for (int j : adj[i])
        if (j != p) dfs(j, i, x+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill(t, t+2*N, inf_ll);
    ll n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    int r = min_element(a, a+n)-a;
    dfs(r, r, 0);
    cout << ans << "\n";
}