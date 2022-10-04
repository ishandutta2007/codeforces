#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 4e5 + 7;

vector <int> g[N];
int sz[N];
int best[N];
int ans[N];

int n;

void jhfs(int u, int p) {
    sz[u] = 1;
    for (auto v : g[u]) {
        if (v != p) {
            jhfs(v, u);
            sz[u] += sz[v];
            best[u] = max(best[u], best[v]);
        }
    }
    if (sz[u] <= n / 2) best[u] = sz[u];
}

void dfs(int u, int p, int bestUp) {
    int mx1 = 0, mx2 = 0;
    for (auto v : g[u]) {
        if (v != p) {
            if (best[v] > mx1) {
                mx2 = mx1;
                mx1 = best[v];
            } else {
                mx2 = max(mx2, best[v]);
            }
        }
    }

    if (n - sz[u] <= n / 2) {
        bestUp = max(bestUp, n - sz[u]);
    }

    bool ok = true;
    int cntbad = 0;
    int who = -1;
    for (auto v : g[u]) {
        if (v != p) {
            if (best[v] == mx1) {
                dfs(v, u, max(bestUp, mx2));
            } else {
                dfs(v, u, max(bestUp, mx1));
            }
            ok &= (sz[v] <= n / 2);
            if (sz[v] > n / 2) {
                ++cntbad;
                who = v;
            }
        }
    }
    if (sz[u] <= n / 2) best[u] = sz[u];
    ok &= (n - sz[u] <= n / 2);
    if (n - sz[u] > n / 2) {
        ++cntbad;
    }
    if (ok) ans[u] = 1;
    if (cntbad > 1) return;
    if (who != -1) {
        if (sz[who] - best[who] <= n / 2) ans[u] = 1;
    } else {
        if (n - sz[u] - bestUp <= n / 2) ans[u] = 1;
    } 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    jhfs(0, -1);
    dfs(0, -1, 0);
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}