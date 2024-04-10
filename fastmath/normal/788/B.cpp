#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;

int n, m;
int pw[MAXN];
vector <int> g[MAXN];
int cnt = 0;

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        if (u == v) {
            ++cnt;
        }
        else {
            ++pw[u];
            ++pw[v];
        }
    }
}

bool used[MAXN];
void dfs(int u) {
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) dfs(v);
    }
}

bool check() {
    for (int i = 0; i < n; ++i) {
        if (g[i].size()) {
            dfs(i);
            break;
        }
    }
    for (int i = 0; i < n; ++i) if (!used[i] && g[i].size()) return 0;
    return 1;
}   

int ans = 0;
void solve() {
    if (!check()) {
        cout << "0\n";
        exit(0);
    }

    for (int i = 0; i < n; ++i) {
        ans += pw[i] * (pw[i] - 1) / 2;
    }

    ans += cnt * (m - cnt);
    ans += cnt * (cnt - 1) / 2;
}

void print() {
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();    

    return 0;
}