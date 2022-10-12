#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 605;
ll n, m;
ll adj[N][N];
ll cost[N], vis[N];

void dij(int r) {
    fill(cost, cost+n, inf_ll);
    fill(vis, vis+n, 0);
    cost[r] = 0;
    for (int t = 0; t < n; t++) {
        int i = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && (i == -1 || cost[j] < cost[i]))
                i = j;
        vis[i] = 1;
        for (int j = 0; j < n; j++)
            cmin(cost[j], cost[i]+adj[i][(j-(cost[i]%n)+n)%n]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ll min_e = inf_ll;
    for (int i = 0; i < n; i++)
        fill(adj[i], adj[i]+n, inf_ll);
    while (m--) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a][b] = c;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cmin(adj[i][j], adj[i][(j+n-1)%n]+1);
        for (int j = 0; j < n; j++)
            cmin(adj[i][j], adj[i][(j+n-1)%n]+1);
    }
    for (int i = 0; i < n; i++) {
        dij(i);
        for (int j = 0; j < n; j++)
            cout << cost[j] << " \n"[j == n-1];
    }
}