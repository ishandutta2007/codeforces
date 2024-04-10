#include <bits/stdc++.h>

#define MN 1001000
#define INF 100000000000000000LL;

using namespace std;
typedef long long ll;

int n, m, a, b, k, pai[MN];
ll dist[MN], c;

vector<pair<int, ll> > adj[MN];
map<pair<int, int>, int> id;
vector<int> ans;

void dijkstra(int no) {
    for(int i=0; i<MN; i++)
        dist[i] = INF;

    dist[no] = 0;
    priority_queue <pair<ll, int> > pfila;
    pfila.push(pair<ll, int>(-dist[no], no));

    while(!pfila.empty() && (int)ans.size() < k) {
        ll dis = -pfila.top().first;
        int u = pfila.top().second;

        pfila.pop();
        if(dis > dist[u]) continue;

        if(u != no) ans.push_back(id[{u, pai[u]}]);

        for(int i=0; i<(int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            if(dist[v] > dist[u] + adj[u][i].second) {
                dist[v] = dist[u] + adj[u][i].second;
                pai[v] = u;
                pfila.push(pair<ll, int>(-dist[v], v));
            }
        }
    }
}


int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<m; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
        id[{a, b}] = id[{b, a}] = i+1;
    }

    dijkstra(1);

    printf("%d\n", (int)ans.size());
    for(int x : ans) {
        printf("%d ", x);
    }
    return 0;
}