#include <bits/stdc++.h>

using namespace std;

int n, m, q, pai[300030], rnk[300030], paths[300030];

vector<int> adj[300030];
int vis[300030], dist[300030];

int read(int x) {
    if(pai[x] == x) return x;
    return pai[x] = read(pai[x]);
}

int merge(int a, int b) {
    a = read(a);
    b = read(b);
    if(a == b) return false;

    if(rnk[b] > rnk[a]) swap(a, b);
    pai[b] = a;
    if(rnk[a] == rnk[b]) rnk[a]++;

    int tmp = (paths[a] + 1) / 2 + 1 + (paths[b] + 1) / 2;
    paths[a] = max(paths[a], max(paths[b], tmp));
}

int bfs(int no, int clean = 0) {
    vector<int> nodes;
    dist[no] = 0;
    vis[no] = 1;
    int far = no;

    queue<int> fila;
    fila.push(no);

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        nodes.push_back(u);
        for(int v : adj[u]) {
            if(vis[v] == 0) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                if(dist[v] > dist[far]) far = v;
                fila.push(v);
            }
        }
    }

    if(clean)
        for(int x : nodes) vis[x] = 0;
    return far;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);

    for(int i = 1; i <= n; i++) {
        pai[i] = i;
        rnk[i] = 1;
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        merge(a, b);
    }

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        int far = bfs(i, 1);
        far = bfs(far);
        int diameter = dist[far];
        paths[read(i)] = diameter;
    }

    for(int i = 0; i < q; i++) {
        int t, x, y;
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d", &x);
            printf("%d\n", paths[read(x)]);
        } else if(t == 2) {
            scanf("%d %d", &x, &y);
            merge(x, y);
        } else assert(false);
    }

    return 0;
}