#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const int N = 2e5 + 7;

int w[N];
vector <int> g[N];
bool used[N];
int timer = 0, tin[N], fup[N];
int p[N];
int sm[N];
int sz[N];

int get(int a) {
    return (a == p[a] ? a : p[a] = get(p[a]));
}

void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        p[a] = b;
        sm[b] += sm[a];
        sz[b] += sz[a];
    }
}
 
void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v]) {
            } else {
                join(v, to);
            }
        }
    }
}

set <int> ng[N];

ll ans = 0;

int dp[N][2];
bool ok[N];
bool can[N];

const ll Inf = 1e18;

void jhfs(int u, int p = -1) {
    ok[u] = (sz[u] != 1);
    if (ok[u]) can[u] = 1;
    for (auto v : ng[u]) {
        if (v != p) {
            jhfs(v, u);
            can[u] |= can[v];
        }
    }
    dp[u][0] = sm[u];
    if (can[u]) {
        dp[u][1] = sm[u];
    }
    for (auto v : ng[u]) {
        if (v != p) {
            dp[u][0] += dp[v][1];
            if (can[u]) dp[u][1] += dp[v][1];
        }
    }
    int mx = 0;
    for (auto v : ng[u]) {
        if (v != p) {
            mx = max(mx, dp[v][0] - dp[v][1]);
        }
    }
    dp[u][0] += mx;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        sm[i] = w[i];
        p[i] = i;
        sz[i] = 1;
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
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) {
            if (get(i) != get(j)) {
                ng[get(i)].insert(get(j));
                ng[get(j)].insert(get(i));
            }
        }
    }
    int s;
    cin >> s;
    --s;
    jhfs(get(s));
    cout << max(dp[get(s)][0], dp[get(s)][1]) << '\n';
}