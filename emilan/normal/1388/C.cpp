#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, m;
        cin >> n >> m;
        vi p(n), h(n);
        rep(i, n) cin >> p[i];
        rep(i, n) cin >> h[i];

        vvi adj(n);
        rep(i, n - 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        vi cnt(n, -1);
        cnt[0] = p[0];
        function<int(int)> dfs = [&](int x){
            for (int i : adj[x]) {
                if (cnt[i] == -1) {
                    cnt[i] = p[i];
                    cnt[x] += dfs(i);
                }
            }
            return cnt[x];
        };
        dfs(0);

        vector<bool> vis(n);
        vis[0] = true;
        function<int(int)> dfs2 = [&](int x){
            bool ok = true;
            int hap = (h[x] + cnt[x]) / 2;
            if (h[x] < -cnt[x] || h[x] > cnt[x] ||
                (h[x] + cnt[x]) & 1) ok = false;

            for (int i : adj[x]) {
                if (!vis[i]) {
                    vis[i] = true;
                    hap -= (h[i] + cnt[i]) / 2;
                    if (!dfs2(i)) ok = false;
                }
            }

            if (hap < 0) ok = false;

            return ok;
        };

        cout << (dfs2(0) ? "YES" : "NO") << '\n';
    }

    return 0;
}