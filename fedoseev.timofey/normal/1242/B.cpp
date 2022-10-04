#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

set <int> unused;

int cnt = 0;

set <int> g[N];

void dfs(int u) {
    unused.erase(u);
    int lst = -1;
    while (true) {
        auto it = unused.upper_bound(lst);
        if (it == unused.end()) break;
        int v = *it;
        if (g[u].count(v)) {
            lst = v;
        } else {
            unused.erase(v);
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].insert(v);
        g[v].insert(u);
    }
    for (int i = 0; i < n; ++i) {
        unused.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (unused.count(i)) {
            ++cnt;
            dfs(i);
        }
    }
    cout << cnt - 1 << '\n';
}