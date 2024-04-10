#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;
const int K = 20;

vector <int> g[N];
int tin[N], tout[N], x[N], a[N], b[N], c[N];
vector <int> who[N];

int sz[N];
ll dp[N];
ll sm[N];

int timer = 0;

void dfs(int u, int p = 0) {
    sz[u] = 1;
    tin[u] = timer++;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    for (int i = 0; i < (int)g[u].size(); ++i) {
        if (g[u][i] == p) {
            g[u].erase(g[u].begin() + i);
            break;
        }
    }
    for (int i = 0; i < (int)g[u].size(); ++i) {
        if (sz[g[u][i]] > sz[g[u][0]]) {
            swap(g[u][i], g[u][0]);
        }
    }
    tout[u] = timer++;
}

bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int m;

const ll Inf = 1e18;

struct path {
    int a, b, id;
    ll cost;
    path(int a, int b, int id, ll cost) : a(a), b(b), id(id), cost(cost) {}
    path() {}
    bool operator <(const path &other) const {
        if (cost != other.cost) return cost < other.cost;
        return id < other.id;
    }
};

set <path> pth[N];
ll delta[N];

void jhfs(int u, int p = 0) {
    int cnt = 0;
    for (auto v : g[u]) {
        if (v != p) {
            ++cnt;
            jhfs(v, u);
            sm[u] += dp[v];
            sm[u] = min(sm[u], Inf);
        }
    }
    dp[u] = Inf;
    if (!g[u].empty()) {
        swap(pth[u], pth[g[u][0]]);
        delta[u] = delta[g[u][0]] + sm[u] - dp[g[u][0]];
        for (int i = 1; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            while (!pth[v].empty()) {
                auto cr = *pth[v].begin();
                pth[v].erase(pth[v].begin());
                cr.cost += sm[u] - dp[v];
                cr.cost += delta[v];
                cr.cost -= delta[u];
                pth[u].insert(cr);
            }
        }
    }
    for (int i : who[u]) {
        pth[u].insert(path(a[i], b[i], i, c[i] + sm[u] - delta[u]));
    }
    while (true) {
        if (pth[u].empty()) break;
        auto cr = *pth[u].begin();
        if (anc(cr.a, p)) {
            dp[u] = cr.cost + delta[u];
            break;
        }
        pth[u].erase(pth[u].begin());
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n >> m;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i] >> a[i] >> c[i];
        --b[i], --a[i];
        who[b[i]].push_back(i);
    }
    dfs(0);
    jhfs(0);
    if (sm[0] == Inf) {
        cout << "-1\n";
    } else {
        cout << sm[0] << '\n';
    }
}