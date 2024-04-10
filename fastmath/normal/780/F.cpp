#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int LG = 61, INF = 1000 * 1000 * 1000, LEN = INF * INF, N = 501;
bool g[LG][2][N][N];
int n, m;
bool can[N], can1[N];
int solve() {
    for (int i = 1; i <= n; ++i)
        can[i] = 1;
    bool w = 0;
    int ans = 0;
    for (int p = LG - 1; p >= 0; --p) {
        bool f = 0;
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= n; ++j) 
                f |= can[i] && g[p][w][i][j]; 
        if (f) {
            ans += 1ll << p;
            memset(can1, 0, sizeof can1);
            for (int i = 1; i <= n; ++i) 
                for (int j = 1; j <= n; ++j) 
                    if (can[i] && g[p][w][i][j]) 
                        can1[j] = 1;
            for (int i = 1; i <= n; ++i) 
                can[i] = can1[i];
            w ^= 1;
        }   
    }               
    return ans;
}
bitset <N> l[2][N], r[2][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, t; 
        cin >> u >> v >> t;
        g[0][t][u][v] = 1;
    }   
    for (int p = 1; p < LG; ++p) {
        for (int t = 0; t < 2; ++t) 
            for (int i = 1; i <= n; ++i) 
                for (int j = 1; j <= n; ++j) 
                    l[t][i][j] = g[p - 1][t][i][j];
        for (int t = 0; t < 2; ++t) 
            for (int i = 1; i <= n; ++i) 
                for (int j = 1; j <= n; ++j) 
                    r[t][i][j] = g[p - 1][t][j][i];        
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= n; ++j) {
                g[p][0][i][j] = (l[0][i] & r[1][j]).any();
                g[p][1][i][j] = (l[1][i] & r[0][j]).any();
            }
    }
    int ans = solve();
    if (ans > LEN) cout << "-1\n";
    else cout << ans << '\n';
}