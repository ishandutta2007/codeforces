#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

struct Edge {
    int u, v, t;
    Edge(int u_, int v_, int t_) {
        u = u_; v = v_; t = t_;
    }
    Edge(){}
};

int n, m, k;
bool live[MAXN];
vector <Edge> g[MAXN];
int cp[MAXN];
int curr = -1;

Edge ed[MAXN];

void read() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> ed[i].u >> ed[i].v;
        --ed[i].u; --ed[i].v;
        g[ed[i].u].push_back(Edge(ed[i].u, ed[i].v, i));
        g[ed[i].v].push_back(Edge(ed[i].v, ed[i].u, i));
    }
}

void del(int u, int nt) {
    //cout << "del " << u << " : ";
    queue <int> q;
    q.push(u);
    while (!q.empty()) {
        int u = q.front();
        //cout << u << ' ';
        q.pop();
        live[u] = 0;
        --curr;
        for (auto e : g[u]) {
            if (e.t < nt) {
                --cp[e.v];
                if (cp[e.v] == k - 1) q.push(e.v);
            }
        }
    }
    //cout << '\n';
}

int ans[MAXN];

void solve() {
    for (int i = 0; i < m; ++i) {
        ++cp[ed[i].u];
        ++cp[ed[i].v];
    }
    for (int i = 0; i < n; ++i) live[i] = 1;
    curr = n;
    for (int i = 0; i < n; ++i) {
        if (live[i] && cp[i] < k) del(i, m);
    }
    ans[m - 1] = curr;
    for (int i = m - 1; i >= 0; --i) {
        if (live[ed[i].v]) --cp[ed[i].u];
        if (live[ed[i].u]) --cp[ed[i].v];

        //cout << "it " << i << '\n';
        //cout << ed[i].first << " : " << live[ed[i].first] << ' ' << cp[ed[i].first] << ' ' << k << '\n';
        //cout << ed[i].second << " : " << live[ed[i].second] << ' ' << cp[ed[i].second] << ' ' << k << '\n';
        //cout << '\n';

        if (live[ed[i].u] && cp[ed[i].u] < k) del(ed[i].u, i);
        if (live[ed[i].v] && cp[ed[i].v] < k) del(ed[i].v, i);
        if (i) ans[i - 1] = curr;
    }
}

void print() {
    for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
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