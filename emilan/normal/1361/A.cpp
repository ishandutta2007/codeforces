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

    int n, m;
    cin >> n >> m;
    vvi adj(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi t(n);
    rep(i, n) cin >> t[i];

    rep(i, n) {
        set<int> has;
        for (int j : adj[i]) has.insert(t[j]);
        if (has.count(t[i])) return cout << -1, 0;
        for (int j = 1; j < t[i]; j++) {
            if (!has.count(j)) return cout << -1, 0;
        }
    }

    vii ans(n);
    rep(i, n) ans[i] = {t[i], i};
    sort(all(ans));
    for (auto& i : ans) cout << i.se + 1 << ' ';

    return 0;
}