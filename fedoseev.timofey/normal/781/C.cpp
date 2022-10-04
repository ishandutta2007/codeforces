#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

vector <int> g[N];

vector <int> e;

bool used[N];

void dfs(int u) {
    used[u] = 1;
    e.push_back(u);
    for (auto v : g[u]) {
        if (used[v]) continue;
        dfs(v);
        e.push_back(u);
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
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    assert(e.size() <= 2 * n);
    int can = (2 * n + k - 1) / k;
    for (int x = 0, i = 0; x < k; ++x) {
        vector <int> cur;
        for (int j = i; j < min((int)e.size(), i + can); ++j) {
            cur.push_back(e[j] + 1);
        }
        if (cur.empty()) cur.push_back(1);
        cout << cur.size() << ' ';
        for (auto x : cur) {
            cout << x << ' ';
        }
        cout << '\n';
        i += can;
        i = min((int)e.size(), i);
    }
}