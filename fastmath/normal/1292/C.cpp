#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 3007;
vector <int> g[N];
int n;
int par[N], cnt[N];
void dfs1(int u, int p) {
    par[u] = p;
    cnt[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs1(v, u);
            cnt[u] += cnt[v];
        }   
    }   
}   
int get(int u, int v) {
    if (u == par[v])
        return cnt[v];
    else
        return n - cnt[u];
}   
ll dp[N][N];
vector <short int> a[N];
int son[N];
void dfs2(int u, int p) {
    vector <int> sn;
    a[u].app(u);
    for (int v : g[u]) {
        if (v != p) {
            dfs2(v, u);
            sn.app(v);
            for (int e : a[v]) {
                a[u].app(e);
                son[e] = v;
            }
        }   
    }   
    for (int v : a[u]) {
        if (v != u) {
            dp[u][v] = dp[v][u] = max(dp[u][par[v]], dp[son[v]][v]) + (n - cnt[son[v]]) * cnt[v];
        }   
    }   
    for (int v1 : sn) {
        for (int v2 : sn) {
                
            if (v1 < v2) {
                for (int uu : a[v1]) {
                    for (int vv : a[v2]) {
                        /*
                        if (uu == 5 && vv == 4) {
                            cout << "LOL\n";
                            cout << dp[par[uu]][vv] << ' ' << dp[par[vv]][uu] << '\n';
                        }   
                        */
                        int x = max(dp[par[uu]][vv], dp[par[vv]][uu]) + cnt[uu] * cnt[vv];
                        dp[uu][vv] = dp[vv][uu] = x;

                    }   
                }   
            }

        }   
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }
    */
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans = max(ans, dp[i][j]);
    cout << ans << '\n';
}