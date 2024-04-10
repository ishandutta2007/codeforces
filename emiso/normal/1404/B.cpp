#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int dist[MN];
vector<int> adj[MN];

int bfs(int no, int n) {
    vector<int> nodes;
    for(int i = 0; i <= n; i++) dist[i] = -1;
    dist[no] = 0;
    int far = no;

    queue<int> fila;
    fila.push(no);

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        nodes.push_back(u);
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                if(dist[v] > dist[far]) far = v;
                fila.push(v);
            }
        }
    }
    return far;
}

ll t, n, a, b, da, db;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &da, &db);

    for(int i = 0; i <= n; i++) {
        adj[i].clear();
    }

    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs(a, n);
    int id = dist[b];

    int far = bfs(1, n);
    far = bfs(far, n);
    int diameter = dist[far];

    if(db > 2 * da && id > da && diameter > 2 * da) puts("Bob");
    else puts("Alice");

    if(--t) goto st;
    return 0;
}