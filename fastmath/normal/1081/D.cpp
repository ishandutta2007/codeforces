#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

int n, m, k;

bool ch[MAXN];
vector <pair <int, int> > g[MAXN];

int st = -1;

bool used[MAXN];

int dfs(int u, int x) {
    used[u] = 1;
    int ans = ch[u];
    for (auto e : g[u]) {
        if (!used[e.first] && e.second <= x) {
            ans += dfs(e.first, x);
        }
    }
    return ans;
}

bool check(int x) {
    memset(used, 0, sizeof used);
    return dfs(st, x) == k;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        --v;
        st = v;
        ch[v] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int l = 0;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << r << ' ';
    }
    cout << '\n';

    return 0;
}