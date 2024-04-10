#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 600 + 1;
constexpr LL inf = 1E15;
LL d[maxn][maxn];
LL e[maxn][maxn];
LL g[maxn][maxn];
int vis[maxn][maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1){
            d[i][j] = (i == j ? 0 : inf);
            e[i][j] = -1;
        }
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1)
            g[i][j] = -1;
    for(int i = 1; i <= m; i += 1){
        int u, v, w;
        cin >> u >> v >> w;
        e[u][v] = d[u][v] = w;
        e[v][u] = d[v][u] = w;
    }
    for(int k = 1; k <= n; k += 1)
        for(int i = 1; i <= n; i += 1)
            for(int j = 1; j <= n; j += 1)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int q;
    cin >> q;
    vector<vector<int>> ch;
    for(int i = 1; i <= q; i += 1){
        int u, v, l;
        cin >> u >> v >> l;
        ch.push_back({u, v, l});
        g[u][v] = l;
        g[v][u] = l;
    }
    for(int u = 1; u <= n; u += 1)
        for(int y = 1; y <= n; y += 1){
            LL f = -inf;
            for(int v = 1; v <= n; v += 1) if(g[u][v] != -1){
                f = max(f, g[u][v] - d[y][v]);
            }
            for(int x = 1; x <= n; x += 1){
                if(e[x][y] != -1){
                    if(d[u][x] + e[x][y] <= f)
                    vis[x][y] = 1;
                }
            }
        }
    int ans = 0;
    for(int i = 1; i <= n; i += 1)
        for(int j = i + 1; j <= n; j += 1){
            ans += vis[i][j];
        }
    cout << ans;
    return 0;
}