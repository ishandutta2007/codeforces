#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1007;

vector <int> g[N];
int used[N];
int sz[N];
int cmp[N];
int have[N];

int cnt = 0;

void dfs(int u) {
    ++sz[cnt];
    cmp[u] = cnt;
    used[u] = 1;
    for (auto v : g[u]) {
        if (!used[v]) {
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
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
            ++cnt;
        }
    }
    for (int i = 0; i < k; ++i) {
        have[cmp[a[i]]] = 1;
    }
    int mx = -1;
    for (int i = 0; i < cnt; ++i) {
        if (have[i]) {
            if (mx == -1 || sz[i] > sz[mx]) {
                mx = i;
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        if (!have[i]) {
            sz[mx] += sz[i];
        }
    }
    ll ans = 0;
    for (int i = 0; i < cnt; ++i) {
        if (have[i]) ans += (ll)sz[i] * (sz[i] - 1) / 2;
    }
    ans -= m;
    cout << ans << '\n';
}