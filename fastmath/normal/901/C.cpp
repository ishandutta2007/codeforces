#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;

struct Edge {
    int v, num;
    Edge(int v_, int num_) {
        v = v_; num = num_;
    }
    Edge(){}
};

int n, m;
vector <Edge> g[MAXN];
pair <int, int> ed[MAXN];
void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> ed[i].first >> ed[i].second;
        --ed[i].first; --ed[i].second;
        g[ed[i].first].push_back(Edge(ed[i].second, i));
        g[ed[i].second].push_back(Edge(ed[i].first, i));
    }
}

bool br[MAXN];
bool used[MAXN];
int tin[MAXN], tout[MAXN], timer = 0;
int dp[MAXN];

void dfs(int u, int parent) {
    used[u] = 1;
    tin[u] = dp[u] = timer++;
    for (auto e : g[u]) {
        if (e.v == parent) continue;
        if (used[e.v]) {
            dp[u] = min(dp[u], tin[e.v]);  
        }
        else {
            dfs(e.v, u);
            dp[u] = min(dp[u], dp[e.v]);
            if (tin[u] < dp[e.v]) {
                br[e.num] = 1;
            }
        }   
    }
}

void bridges() {
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) dfs(i, -1);
    }
}

set <int> ms[MAXN];

void dfs1(int u, int c) {
    used[u] = 1;
    ms[c].insert(u);
    for (auto e : g[u]) {
        if (br[e.num]) continue;
        if (!used[e.v]) dfs1(e.v, c);
    }
}

int cnt = 0;
void comps() {
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) dfs1(i, cnt++);
    }
}

int r[MAXN];
int post[MAXN];
int pref[MAXN];

void solve() {
    bridges(); 
    comps();
    for (int i = 0; i < n; ++i) r[i] = MAXN;
    for (int i = 0; i < cnt; ++i) {
        if (ms[i].size() > 1) {
            int nl = *ms[i].begin();
            int nr = *ms[i].rbegin();
            r[nl] = nr;
        }
    }
    post[n] = MAXN;
    for (int i = n - 1; i >= 0; --i) {
        post[i] = min(post[i + 1], r[i]);
    }
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + post[i];
    }
}

int getsum(int n) {
    return n * (n + 1) / 2;
}

int getsum(int l, int r) {
    return getsum(r) - getsum(l - 1);
}

void print() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        
        int t = upper_bound(post + l, post + r + 1, r) - post;

        cout << (r + 1) * (r - t + 1) + (pref[t] - pref[l]) - getsum(l, r) << '\n';
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