#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

vector <int> g[N];
int col[N];

void dfs(int u, int p) {
    int cur = 0;
    for (auto v : g[u]) {
        if (v == p) continue;
        while (cur == col[u] || cur == col[p]) ++cur;
        col[v] = cur++;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> deg(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) mx = max(mx, deg[i] + 1);
    dfs(0, 0);
    cout << mx << '\n';
    for (int i = 0; i < n; ++i) {
        cout << col[i] + 1 << ' ';
    }
}