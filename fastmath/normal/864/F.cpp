#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3007;
const int LG = 13;

int n, m, q;
short int dp[MAXN][MAXN][LG];
bool ch[MAXN][MAXN];
vector <int> g[MAXN];

void read() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }   
}

void dfs(int u, int s) {
    ch[s][u] = 1;
    for (int v : g[u]) {
        if (!ch[s][v]) {
            dfs(v, s);
        }
    }   
}   

bool used[MAXN];
void solve() {
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }   
    for (int i = 0; i < n; ++i) {
        dfs(i, i);
    }   
    for (int i = 0; i < n; ++i) {
        memset(used, 0, sizeof used);
        used[i] = 1;
        dp[i][i][0] = -1;
        for (int v : g[i]) {
            for (int t = 0; t < n; ++t) {
                if (ch[v][t] && !used[t]) {
                    dp[i][t][0] = v;
                    used[t] = 1;
                }
            }   
        }   
        for (int v = 0; v < n; ++v) {
            if (!used[v]) {
                dp[i][v][0] = -1;
            }   
        }   
    }   
    for (int p = 1; p < LG; ++p) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j][p - 1] == -1) {
                    dp[i][j][p] = -1;
                }                    
                else {
                    dp[i][j][p] = dp[dp[i][j][p - 1]][j][p - 1];
                }   
            }   
        }   
    }   
}

int get(int u, int v, int k) {
    --k;
    if (!ch[u][v]) {
        return -1;
    }   
    if (dp[u][v][LG - 1] != -1) {
        return -1;
    }
    for (int i = LG - 1; i >= 0; --i) {
        if ((1 << i) <= k) {
            k -= 1 << i;
            if (dp[u][v][i] == -1) {
                return -1;
            }   
            u = dp[u][v][i];
        }   
    }   
    return u + 1;
}   

void print() {
    for (int i = 0; i < q; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        cout << get(u - 1, v - 1, k) << '\n';
    }   
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    read();
    solve();
    print();

    return 0;
}