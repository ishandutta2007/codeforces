#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int mod = 1e9 + 7;

void solve(int tc) {
    int n;
    cin >> n;
    vt<vt<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vt<ll> edgeFreq;
    function<int(int, int)> dfs = [&](int x, int p) {
        int cnt = 1;
        for (int i : adj[x]) {
            if (i == p) continue;
            int childCnt = dfs(i, x);
            cnt += childCnt;
            edgeFreq.push_back(childCnt * ll(n - childCnt));
        }
        return cnt;
    };
    dfs(0, -1);
    sort(rall(edgeFreq));

    int m;
    cin >> m;
    vt<int> p(m);
    for (int &i : p) cin >> i;
    sort(rall(p));
    if (m < n - 1) p.insert(p.end(), n - m - 1, 1);
    else if (m >= n) {
        ll pro = 1;
        for (int i = 0; i < m - n + 2; i++) {
            pro = pro * p[i] % mod;
        }
        p.erase(p.begin(), p.begin() + m - n + 2);
        p.insert(p.begin(), pro);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = (ans + edgeFreq[i] % mod * p[i]) % mod;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}