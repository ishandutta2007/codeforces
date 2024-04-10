#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int n, m;
vector <int> a[MAXN], eg[MAXN], g[MAXN];

int num(int i, int j) {
    return m * i + j;
}

int num(pair <int, int> p) {
    return m * p.first + p.second;
}

int curr = 0;
bool used[MAXN];
int comp[MAXN];
void dfs(int u) {
    comp[u] = curr;
    used[u] = 1;
    for (int v : eg[u]) {
        if (!used[v]) dfs(v);
    }
}   

bool cmp(pair <int, int> p1, pair <int, int> p2) {
    return a[p1.first][p1.second] < a[p2.first][p2.second];
}

vector <int> tp;
void dfs1(int u) {
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) dfs1(v);
    }
    tp.push_back(u);
}   

int dp[MAXN];

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }

    for (int i = 0; i < n; ++i) {
        map <int, vector <int> > d;
        for (int j = 0; j < m; ++j) {
            d[a[i][j]].push_back(j);
        }
        for (auto e : d) {
            auto v = e.second;
            for (int t = 0; t < (int)v.size() - 1; ++t) {
                eg[num(i, v[t])].push_back(num(i, v[t + 1]));
                eg[num(i, v[t + 1])].push_back(num(i, v[t]));
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        map <int, vector <int> > d;
        for (int i = 0; i < n; ++i) {
            d[a[i][j]].push_back(i);
        }
        for (auto e : d) {
            auto v = e.second;
            for (int t = 0; t < (int)v.size() - 1; ++t) {
                eg[num(v[t], j)].push_back(num(v[t + 1], j));
                eg[num(v[t + 1], j)].push_back(num(v[t], j));
            }
        }
    }

    for (int i = 0; i < n * m; ++i) {
        if (!used[i]) {
            dfs(i); ++curr;
        }
    }
                                       
    for (int i = 0; i < n; ++i) {
        vector <pair <int, int> > v;
        for (int j = 0; j < m; ++j) {
            v.push_back({i, j});
        }
        sort(v.begin(), v.end(), cmp);
        for (int t = 0; t < m - 1; ++t) {
            if (cmp(v[t], v[t + 1])) {
                g[comp[num(v[t])]].push_back(comp[num(v[t + 1])]);
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        vector <pair <int, int> > v;
        for (int i = 0; i < n; ++i) {
            v.push_back({i, j});
        }
        sort(v.begin(), v.end(), cmp);
        for (int t = 0; t < n - 1; ++t) {
            if (cmp(v[t], v[t + 1])) {
                g[comp[num(v[t])]].push_back(comp[num(v[t + 1])]);
            }
        }
    }

    memset(used, 0, sizeof used);
    for (int i = 0; i < curr; ++i) {
        if (!used[i]) dfs1(i);
    }
    reverse(tp.begin(), tp.end());

    for (int i = 0; i < curr; ++i) dp[i] = 1;
    for (auto u : tp) {
        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }   

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[comp[num(i, j)]] << ' ';
        }   
        cout << '\n';
    }   

    return 0;
}