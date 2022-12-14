#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <class T> using p = pair<T, T>;
template <class T> using vt = vector<T>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<vt<int>> adj(n);
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vt<bool> vis(n);
    function<int(int)> dfs1 = [&](int x) {
        int cur = sz(adj[x]) == 1;
        for (int i : adj[x]) {
            if (vis[i]) continue;
            vis[i] = true;
            cur |= dfs1(i);
        }
        if (__builtin_popcount(cur) == 1) cur ^= 3;
        return cur;
    };
    vis[0] = true;
    cout << (dfs1(0) == 3 ? 3 : 1) << ' ';

    int ret = n - 1;
    vis.assign(n, false);
    function<bool(int)> dfs2 = [&](int x) {
        if (sz(adj[x]) == 1) return true;
        int cnt = 0;
        for (int i : adj[x]) {
            if (vis[i]) continue;
            vis[i] = true;
            cnt += dfs2(i);
        }
        if (cnt > 1) ret -= cnt - 1;
        return false;
    };

    rep(i, n) {
        if (sz(adj[i]) != 1) {
            vis[i] = true;
            dfs2(i);
            cout << ret;
            return 0;
        }
    }
}