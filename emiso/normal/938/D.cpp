#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, a, b, visit[MN];
ll c, cost[MN], dist[MN];

vector<pair<ll, ll> > adj[MN];

void dijkstra() {
    priority_queue <pair<ll, ll> > pfila;

    for(int i = 1; i <= n; i++) {
        dist[i] = cost[i];
        pfila.push(pair<ll, ll>(-dist[i], i));
    }


    while(!pfila.empty()) {
        ll d = -pfila.top().first;
        int u = pfila.top().second;

        pfila.pop();
        if(d > dist[u]) continue;

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;

            if(dist[v] > dist[u] + 2*adj[u][i].second) {
                dist[v] = dist[u] + 2*adj[u][i].second;
                pfila.push(pair<ll, ll>(-dist[v], v));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &cost[i]);
    }

    dijkstra();

    for(int i = 1; i <= n; i++) {
        printf("%lld ", dist[i]);
    }
    return 0;
}