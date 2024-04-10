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
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vvi adj(n + 1);
    rep(i, n) {
        int x;
        cin >> x;
        if (x != -1) adj[x].pb(i + 1);
    }

    vi h(n + 1);
    function<int(int)> dfs = [&](int x) {
        if (!h[x]) {
            if (adj[x].empty()) h[x] = 1;
            else {
                int mx = 0;
                for (int i : adj[x]) {
                    mx = max(mx, dfs(i));
                }
                h[x] = 1 + mx;
            }
        }
        return h[x];
    };

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dfs(i));
    }

    cout << mx;

    return 0;
}