#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

vector <pair <int, int>> g[N];
bool used[N];

void dfs(int u, int b) {
    used[u] = 1;
    for (auto &[v, w] : g[u]) {
        if (w <= b && !used[v]) {
            dfs(v, b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> kek(k);
    for (int i = 0; i < k; ++i) {
        cin >> kek[i];
        --kek[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int l = 0, r = 1e9 + 2;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        for (int i = 0; i < n; ++i) {
            used[i] = 0;
        }
        dfs(kek[0], m);
        bool bad = false;
        for (auto x : kek) {
            if (!used[x]) {
                bad = true;
                break;
            }
        }
        if (!bad) {
            r = m;
        }
        else {
            l = m;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << r << ' ';
    }
}