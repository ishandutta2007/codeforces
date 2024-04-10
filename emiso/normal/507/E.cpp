#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1000100

const ll INF = LLONG_MAX/2;
ll n, m, dist[MN], dist2[MN], pai[MN];
vector<pair<ll, pair<ll, ll>>> adj[MN];

void bfs(int ini) {
    fill(dist, dist + n + 1, INF); dist[ini] = 0;
    queue<pair<ll, ll>> q({{-dist[ini], ini}});
    while(!q.empty()) {
        ll u = q.front().second, d = -q.front().first; q.pop();
        if(dist[u] != d) continue;
        for(auto &edge : adj[u]) {
            ll v = edge.first, c = edge.second.first;
            if(dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                q.push({-dist[v], v});
            }
        }
    }
}

void bfs2(int ini) {
    memset(pai, -1, sizeof pai);
    fill(dist2, dist2 + n + 1, INF); dist2[ini] = 0;
    queue<pair<ll, ll>> q({{-dist2[ini], ini}});
    while(!q.empty()) {
        ll u = q.front().second, d = -q.front().first; q.pop();
        if(dist2[u] != d) continue;
        for(auto &edge : adj[u]) {
            ll v = edge.first, c = edge.second.second;
            if(dist2[v] > dist2[u] + c && dist[v] == dist[u] + 1) {
                dist2[v] = dist2[u] + c;
                q.push({-dist2[v], v});
                pai[v] = u;
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0, u, v, z; i < m; i++) {
        scanf("%lld %lld %lld", &u, &v, &z);
        adj[u].push_back({v, {1, 1-z}});
        adj[v].push_back({u, {1, 1-z}});
    }
    
    bfs(1);
    bfs2(1);
    vector<vector<int>> vv;
    set<pair<int, int>> ss, vp;

    int tmp = n;
    while (tmp != 1) {
        vp.insert({tmp, pai[tmp]});
        vp.insert({pai[tmp], tmp});
        tmp = pai[tmp];
    }

    for (int i = 1; i <= n; i++) {
        for (auto &edge : adj[i]) {
            int v = edge.first, z = vp.count({i, v});
            if (i >= v) continue;
            if (z == edge.second.second && !ss.count({i, v})) {
                vv.push_back({i, v, z});
                ss.insert({i, v});
                ss.insert({v, i});
            }
        }
    }

    printf("%d\n", vv.size());
    for (auto tt : vv) printf("%d %d %d\n", tt[0], tt[1], tt[2]);
}