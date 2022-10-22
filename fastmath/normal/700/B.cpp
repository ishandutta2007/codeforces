#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n, k;
bool ch[MAXN];
vector <int> g[MAXN];

void read() {
    cin >> n >> k;
    for (int i = 0; i < 2 * k; ++i) {
        int u; cin >> u; --u; ch[u] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int ans = 0;
int cnt[MAXN];

void dfs(int u, int parent) {
    cnt[u] = ch[u];
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        ans += min(cnt[v], 2 * k - cnt[v]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    dfs(0, 0);
    cout << ans << '\n';

    return 0;
}