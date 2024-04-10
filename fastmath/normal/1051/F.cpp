#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

struct Edge {
    int u, v, c;
    Edge(int u_, int v_, int c_) {
        u = u_; v = v_; c = c_;
    }
    Edge(){}
};

int n, m;
Edge ed[MAXN];
vector <Edge> g[MAXN];
void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> ed[i].u >> ed[i].v >> ed[i].c;
        --ed[i].u; --ed[i].v;
        g[ed[i].u].push_back(Edge(ed[i].u, ed[i].v, ed[i].c));
        g[ed[i].v].push_back(Edge(ed[i].v, ed[i].u, ed[i].c));
    }
}

vector <Edge> ev;
vector <Edge> tg[MAXN];
bool used[MAXN];
void dfs2(int u, int parent) {
    used[u] = 1;
    for (auto e : g[u]) {
        if (!used[e.v]) {
            tg[u].push_back(e);
            dfs2(e.v, u);
        }
        else if (e.v != parent) {
            ev.push_back(e);
        }
    }
}

void build_tree() {
    memset(used, 0, sizeof used);
    dfs2(0, 0);
}

const int LG = 20;

int go[MAXN][LG];
int timer = 0;
int tin[MAXN], tout[MAXN];
int pref[MAXN];
void dfs1(int u, int parent, int curr) {
    pref[u] = curr;
    tin[u] = timer++;
    go[u][0] = parent;
    for (int i = 1; i < LG; ++i) {
        go[u][i] = go[go[u][i - 1]][i - 1];
    }
    for (auto e : tg[u]) {
        dfs1(e.v, u, curr + e.c);
    }
    tout[u] = timer++;
}

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lcp(int u, int v) {
    if (anc(u, v)) return u;
    for (int i = LG - 1; i >= 0; --i) {
        if (!anc(go[u][i], v)) u = go[u][i];
    }
    return go[u][0];
}

int getr(int u, int v) {
    int l = lcp(u, v);
    return pref[u] + pref[v] - pref[l] * 2;
}

void precalc() {
    dfs1(0, 0, 0);
}

const int MAXM = 101;
const int INF = 1e16 + 7;

int dp[MAXM][MAXM];
vector <int> a;

void pink_floyd() {
    set <int> ms;
    for (auto e : ev) {
        ms.insert(e.u);
        ms.insert(e.v);
    }
    for (int e : ms) a.push_back(e);
    int t = a.size();
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            dp[i][j] = INF;
        }
    }   
    for (int i = 0; i < t; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            dp[i][j] = min(dp[i][j], getr(a[i], a[j]));
        }
    }
    map <int, int> num;
    for (int i = 0; i < t; ++i) {
        num[a[i]] = i;
    }       
    for (auto e : ev) {
        int i = num[e.u];
        int j = num[e.v];
        dp[i][j] = min(dp[i][j], e.c);
        dp[j][i] = min(dp[j][i], e.c);
    }
    for (int k = 0; k < t; ++k) {
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < t; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }   
}

void solve() {
    build_tree();
    precalc();
    pink_floyd();
}

int r[MAXN][MAXM];

int ghetts(int u, int v) {
    int t = a.size();
    int ans = getr(u, v);
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            ans = min(ans, r[u][i] + dp[i][j] + r[v][j]);
        }   
    }
    return ans;
}

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)a.size(); ++j) {
            r[i][j] = getr(i, a[j]);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int ans = ghetts(u, v);
        if (INF <= ans) cout << "-1\n";
        else cout << ans << '\n';
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}