#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
ll n, s, sz[100010], p[100010], val[100010], cost[100010];

struct edge {
    ll to, val, cost;
};
vector<edge> adj[100010];

ll dfs(int no, int pai = -1) {
    sz[no] = 0;
    for(edge& ed : adj[no]) {
        int v = ed.to;
        if(v != pai) {
            sz[no] += dfs(v, no);
            p[v] = no;
            val[v] = ed.val;
            cost[v] = ed.cost;
        }
    }

    if(sz[no] == 0) sz[no] = 1;
    return sz[no];
}

ll gain(int idx) {
    return (val[idx] * sz[idx]) - (val[idx] / 2 * sz[idx]);
}

int main() {
    scanf("%d", &t);
    start:
    scanf("%lld %lld", &n, &s);
    for(int i = 1; i < n; i++) {
        ll u, v, w, c = 1;
        scanf("%lld %lld %lld", &u, &v, &w);
        adj[u].push_back({v, w, c});
        adj[v].push_back({u, w, c});
    }

    dfs(1);
    priority_queue<pair<ll, int>> pq[2];
    ll tot = 0, goal;

    for(int i = 2; i <= n; i++) {
        tot += sz[i] * val[i];
        if(cost[i] == 1) pq[0].push({gain(i), i});
        else pq[1].push({gain(i), i});
    }
    goal = tot - s;

    vector<ll> g[2];
    g[0] = g[1] = vector<ll>({0});

    for(int z = 0; z < 2; z++) {
        while(!pq[z].empty()) {
            auto tp = pq[z].top();
            pq[z].pop();

            ll newg = g[z].back() + tp.first;
            g[z].push_back(newg);

            int i = tp.second;
            val[i] /= 2;
            if(gain(i)) pq[z].push({gain(i), i});
        }
    }

    int ans = INT_MAX;
    for(int i = 0, j = g[1].size() - 1; i < g[0].size(); i++) {
        while(j > 0 && g[0][i] + g[1][j-1] >= goal)
            j--;
        if(g[0][i] + g[1][j] >= goal) ans = min(ans, i + 2*j);
    }
    printf("%d\n", ans);

    for(int i = 0; i <= n; i++) adj[i].clear();
    if(--t) goto start;
    return 0;
}