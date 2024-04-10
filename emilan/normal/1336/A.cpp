#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << 0;
        return 0;
    }

    vector<set<int>> adj(n + 1);
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    map<int, set<int>> m;
    map<int, int> d, p;
    queue<int> q;

    d[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        int step = d[cur];
        q.pop();

        for (int i : adj[cur]) {
            if (d.count(i)) continue;
            d[i] = step + 1;
            q.push(i);
        }
    }

    for (int i = 2; i <= n; i++) {
        if (sz(adj[i]) == 1) m[d[i]].insert(i);
    }

    ll ans = 0;
    while (k--) {
        int cur = *m.rbegin()->se.begin();
        ans += m.rbegin()->fi;

        for (int i : adj[cur]) {
            p[i] += p[cur] + 1;
            d[i] -= p[cur] + 1;

            adj[i].erase(cur);
            if (sz(adj[i]) == 1 && i != 1) m[d[i]].insert(i);
        }

        m[d[cur]].erase(cur);
        if (m[d[cur]].empty()) m.erase(d[cur]);
    }

    cout << ans;

    return 0;
}