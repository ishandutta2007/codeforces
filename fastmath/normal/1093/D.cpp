#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;
const int MOD = 998244353;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int n, m;
vector <int> g[MAXN];
bool used[MAXN];

bool col[MAXN];
void dfs(int u, vector <int> &c) {
    used[u] = 1;
    c.push_back(u);
    for (int v : g[u]) {
        if (!used[v]) {
            col[v] = col[u] ^ 1;
            dfs(v, c);
        }   
    }   
}   

int pw[MAXN];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        used[i] = 0;
    }   
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            vector <int> c;
            vector <int> cnt(2);
            dfs(i, c);
            for (int v : c) {
                ++cnt[col[v]];
            }   
            int f = mod(pw[cnt[0]] + pw[cnt[1]]);
            ans = mod(ans * f);
        }
    }
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (col[u] == col[v]) {
                cout << "0\n";
                return;
            }   
        }   
    }   
    cout << ans << '\n';
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pw[i] = mod(pw[i - 1] << 1);
    }   

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }   

    return 0;
}