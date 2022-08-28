#include <bits/stdc++.h>
using namespace std;
long long dis[2][2010];
struct edge {
    int v, w, nxt;
} e[200010];
int n, m, a[2010];
int head[2010], tot;
inline void addedge(int u, int v, int w) {
    e[++tot] = edge{v, w, head[u]};
    head[u] = tot;
}
template <typename T>
inline int ckmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
template <typename T>
inline int ckmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
inline void dijkstra(long long *dis, int s) {
    priority_queue < pair<long long, int> > q;
    memset(dis, 0x3f, sizeof(long long[n + 1]));
    q.push(make_pair(0, s));
    dis[s] = 0;
    while(!q.empty()) {
        pair <long long, int> now = q.top();
        q.pop();
        if(now.first != -dis[now.second]) continue;
        int u = now.second;
        for(int i = head[u]; i; i = e[i].nxt) {
            if(ckmin(dis[e[i].v], dis[u] + e[i].w)) {
                q.push(make_pair(-dis[e[i].v], e[i].v));
            }
        }
    }
}
long long dp[2][2][2010][2010];
int id[2][2010];
inline int check(int a, int b, int c, int d) {
    if(dp[a][b][c][d] < -1e16) return 0;
    if(a) return dis[0][id[0][c]] != dis[0][id[0][c + 1]];
    return dis[1][id[1][d]] != dis[1][id[1][d + 1]];
}
int main() {
    ios :: sync_with_stdio(false);
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    dijkstra(dis[0], s);
    dijkstra(dis[1], t);
    for(int i = 1; i <= n; i++) id[0][i] = id[1][i] = i;
    sort(id[0] + 1, id[0] + 1 + n, [&] (int a, int b) {
        return dis[0][a] < dis[0][b];
    });
    sort(id[1] + 1, id[1] + 1 + n, [&] (int a, int b) {
        return dis[1][a] < dis[1][b];
    });
    dis[0][0] = -1;
    dis[1][0] = -1;
    memset(dp, ~1, sizeof dp);
    dp[0][0][n][n] = dp[1][1][n][n] = dp[1][0][n][n] = dp[0][1][n][n] = 0;
    for(int i = n; i >= 0; i--) {
        for(int j = n; j >= 0; j--) {
            int d1 = dis[1][id[0][i + 1]] > dis[1][id[1][j]], d2 = dis[0][id[1][j + 1]] > dis[0][id[0][i]];
            if(i != n && check(0, d1, i + 1, j)) ckmax(dp[0][0][i][j], dp[0][d1][i + 1][j] + d1 * a[id[0][i + 1]]);
            if(j != n && check(1, d2, i, j + 1)) ckmax(dp[1][0][i][j], dp[1][d2][i][j + 1] + d2 * a[id[1][j + 1]]);
            if(i != n && check(0, 1, i + 1, j)) ckmax(dp[0][1][i][j], dp[0][1][i + 1][j] + d1 * a[id[0][i + 1]]);
            if(j != n && check(1, 1, i, j + 1)) ckmax(dp[1][1][i][j], dp[1][1][i][j + 1] + d2 * a[id[1][j + 1]]);
            if(dis[0][id[0][i]] != dis[0][id[0][i + 1]] && check(1, 0, i, j)) ckmax(dp[0][1][i][j], -dp[1][0][i][j]);
            if(dis[1][id[1][j]] != dis[1][id[1][j + 1]] && check(0, 0, i, j)) ckmax(dp[1][1][i][j], -dp[0][0][i][j]);
            // cerr << i << ' ' << j << endl;
            // cerr << d1 << ' ' << d2 << endl;
            // cerr << dp[0][0][i][j] << ' ' <<  dp[0][1][i][j] << ' ' <<  dp[1][0][i][j] << ' ' <<  dp[1][1][i][j] << endl;
        }
    }
    // cerr << dp[0][0][0][0] << endl;
    if(dp[0][0][0][0] == 0) cout << "Flowers" << endl;
    else if(dp[0][0][0][0] > 0) cout << "Break a heart" << endl;
    else cout << "Cry" << endl;
}