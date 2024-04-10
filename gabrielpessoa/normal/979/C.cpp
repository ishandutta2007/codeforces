#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 6e5 + 5;

int adj[ms], to[ms], ant[ms], z = 0, x, y, d[ms], hasY[ms];
ll n;

void clear() {
    memset(adj, -1, sizeof adj);
    z = 0;
}

void add(int x, int y) {
    to[z] = y;
    ant[z] = adj[x];
    adj[x] = z++;
    swap(x, y);
    to[z] = y;
    ant[z] = adj[x];
    adj[x] = z++;
}

int dfs(int v, int par = -1) {
    d[v] = 1;
    hasY[v] = v == y;
    for(int e = adj[v]; e != -1; e = ant[e]) {
        int u = to[e];
        if(u == par) continue;
        d[v] += dfs(u, v);
        hasY[v] = hasY[v] || hasY[u];
    }
    return d[v];
}

int main() {
    cin >> n >> x >> y;
    clear();
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    dfs(x);
    ll ans2 = 1, ans1 = d[y];
    for(int e = adj[x]; e != -1; e = ant[e]) {
        int u = to[e];
        if(!hasY[u]) ans2 += d[u];
    }
    //cout << ans1 << ' ' << ans2 << '\n';
    cout << n * (n - 1) - ans1 * ans2 << endl;
}