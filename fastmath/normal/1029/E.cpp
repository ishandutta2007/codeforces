#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

vector <int> g[MAXN];

//dp1 - colored; dp2 - not colored, not bad; dp3 - not colored, bad;

int dp1[MAXN], dp2[MAXN], dp3[MAXN];
int n, ans = 0;

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

void dfs(int u, int parent, int h) {
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u, h + 1);
    }

    dp1[u] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        dp1[u] += min(dp1[v], dp2[v], dp3[v]);
    }

    dp2[u] = INF;
    int sum = 0;
    for (int v : g[u]) {
        if (v == parent) continue;
        sum += min(dp1[v], dp2[v]);
    }
    for (int v : g[u]) {
        if (v == parent) continue;
        dp2[u] = min(dp2[u], sum - min(dp1[v], dp2[v]) + dp1[v]);
    }

    dp3[u] = 0;
    for (int v : g[u]) {
        if (v == parent) continue;
        dp3[u] += dp2[v];
    }

    /*
    if (u + 1 == 5) {
        cout << u + 1 << " : " << dp1[u] << ' ' << dp2[u] << ' ' << dp3[u] << '\n';
    }
    */

    if (h == 2) ans += min(dp1[u], dp2[u], dp3[u]);
}

signed main() {     
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(0, 0, 0);
    cout << ans << '\n';

    return 0;
}