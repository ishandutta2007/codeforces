#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

vector <int> g[N];

int col[N];

void dfs(int u) {
    for (auto v : g[u]) {
        if (col[v] == -1) {
            col[v] = col[u] ^ 1;
            dfs(v);
        }
        else if (col[v] != (col[u] ^ 1)) {
            cout << "NO\n";
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector <pair <int, int>> e;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) col[i] = -1;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        e.emplace_back(u, v);
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            col[i] = 0;
            dfs(i);
        }
    }
    cout << "YES\n";
    for (auto p : e) {
        cout << col[p.first];
    }
}