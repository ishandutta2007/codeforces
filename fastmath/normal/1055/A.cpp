#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

vector <int> g[MAXN];

int b[MAXN];

bool used[MAXN];

bool dfs(int u, int w) {
    if (u == w) return 1;
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v] && dfs(v, w)) return 1;
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    --s;

    int pr = -1;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t) {
            //cout << pr << "->" << i << '\n';
            if (pr != -1) g[pr].push_back(i);
            pr = i;
        }
    }

    for (int i = 0; i < n; ++i) cin >> b[i];
    pr = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (b[i]) {
            //cout << pr << "->" << i << '\n';
            if (pr != -1) g[pr].push_back(i);
            pr = i;
        }   
    }

    if (dfs(0, s)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}