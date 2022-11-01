#include <bits/stdc++.h>
#define MN 100010
#define INF 100000000000000000LL

using namespace std;
typedef long long ll;

ll n, q, s, dist[8*MN], id[2][MN], a, b, w, t, l, r;
vector<pair<ll, ll> > adj[8*MN];

void dijkstra(int no) {
    for(int i=0; i<8*MN; i++)
        dist[i] = INF;

    dist[no] = 0;
    priority_queue <pair<ll, ll> > pfila;
    pfila.push(pair<ll, ll>(-dist[no], no));

    while(!pfila.empty()) {
        ll dis = -pfila.top().first;
        int u = pfila.top().second;

        pfila.pop();
        if(dis > dist[u]) continue;

        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i].first;
            if(dist[v] > dist[u] + adj[u][i].second) {
                dist[v] = dist[u] + adj[u][i].second;
                pfila.push(pair<ll, ll>(-dist[v], v));
            }
        }
    }
}

void build(int i, int l, int r, int t) {
    if(l == r) {
        if(t) id[t][l] = 4*MN + i;
        else   id[t][l] = i;
        adj[i].emplace_back(4*MN + i, 0);
        adj[4*MN + i].emplace_back(i, 0);
        return;
    }
    int m = (l + r) / 2;
    build(i*2,   l,   m, t);
    build(i*2+1, m+1, r, t);

    if(t) {
        adj[4*MN + i].emplace_back(4*MN + i*2, 0);
        adj[4*MN + i].emplace_back(4*MN + i*2+1, 0);
    } else {
        adj[i*2].emplace_back(i, 0);
        adj[i*2+1].emplace_back(i, 0);
    }
}

void add_edge2(int i, int l, int r, int a, int lq, int rq, ll w) {
    if(l > rq || r < lq) return;
    if(lq <= l && r <= rq) {
        adj[a].emplace_back(4*MN + i, w);
        return;
    }
    int m = (l + r) / 2;
    add_edge2(i*2,   l,   m, a, lq, rq, w);
    add_edge2(i*2+1, m+1, r, a, lq, rq, w);
}

void add_edge3(int i, int l, int r, int lq, int rq, int a, ll w) {
    if(l > rq || r < lq) return;
    if(lq <= l && r <= rq) {
        adj[i].emplace_back(a, w);
        return;
    }
    int m = (l + r) / 2;
    add_edge3(i*2,   l,   m, lq, rq, a, w);
    add_edge3(i*2+1, m+1, r, lq, rq, a, w);
}

int main() {
    scanf("%lld %lld %lld", &n, &q, &s);

    build(1, 1, n, 0);
    build(1, 1, n, 1);
    for(int i = 0; i < q; i++) {
        scanf("%d", &t);
        if(t == 1) {
            scanf("%lld %lld %lld", &a, &b, &w);
            adj[id[0][a]].emplace_back(id[1][b], w);
        }
        else if(t == 2) {
            scanf("%lld %lld %lld %lld", &a, &l, &r, &w);
            add_edge2(1, 1, n, id[0][a], l, r, w);
        }
        else if(t == 3) {
            scanf("%lld %lld %lld %lld", &a, &l, &r, &w);
            add_edge3(1, 1, n, l, r, id[1][a], w);
        }
        else assert(false);
    }

    dijkstra(id[0][s]);

    for(int i = 1; i <= n; i++) {
        printf("%lld ", (dist[id[1][i]] < INF) ? dist[id[1][i]] : -1);
    }
    return 0;
}