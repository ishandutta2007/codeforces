#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;
const int INF = 1e9 + 7;

int n, m;
int a[MAXN], b[MAXN];
vector <int> mg[MAXN];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        mg[u].push_back(v);
        mg[v].push_back(u);
    }   
}   

struct Edge {
    int u, v, f, c;
};  

vector <Edge> ed;
vector <int> g[MAXN];

void add(int u, int v, int c) {
    g[u].push_back(ed.size());
    ed.push_back({u, v, 0, c});
    g[v].push_back(ed.size());
    ed.push_back({v, u, 0, 0});
}   

void build() {
    for (int u = 0; u < n; ++u) {
        add(0, u + 1, a[u]);
    }   
    for (int u = 0; u < n; ++u) {
        add(u + 1, n + u + 1, INF);
        for (int v : mg[u]) {
            add(u + 1, n + v + 1, INF);
        }   
    }   
    for (int u = 0; u < n; ++u) {
        add(n + u + 1, 2 * n + 1, b[u]);
    }   
}

void solve() {
    build();
}

bool used[MAXN];
int dfs(int u, int curr) {
    if (u == 2 * n + 1) return curr;
    used[u] = 1;
    for (int num : g[u]) {
        auto &e = ed[num];
        if (used[e.v]) continue;
        if (e.f < e.c) {
            int t = dfs(e.v, min(curr, e.c - e.f));
            if (t) {
                e.f += t;
                ed[num^1].f -= t;
                return t;
            }
        }   
    }   
    return 0;
}   

int ff() {
    int ans = 0;
    while (1) {
        memset(used, 0, sizeof used);
        int add = dfs(0, INF);
        if (!add) break;
        ans += add;
    }   
    return ans;
}   

int ans[MAXN][MAXN];
void print() {
    int sum1 = 0;
    for (int i = 0; i < n; ++i) sum1 += a[i];
    int sum2 = 0;
    for (int i = 0; i < n; ++i) sum2 += b[i];

    if (sum1 != sum2) {
        cout << "NO\n";
        exit(0);
    }   

    int mf = ff();    
    if (mf == sum1) {
        for (int u = 1; u <= n; ++u) {
            for (int num : g[u]) {
                auto e = ed[num];
                if (e.f > 0) {
                    ans[e.u - 1][e.v - n - 1] = e.f;
                }
            }
        }   
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << ans[i][j] << ' ';
            cout << '\n';
        }   
    }
    else {
        cout << "NO\n";
    }   
}

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}