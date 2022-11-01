#include <bits/stdc++.h>

#define MN 100100
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, a, b, visit[MN], dist[MN], t[MN], k, s;
vector<int> adj[MN];
priority_queue<int> best[MN];

void bfs(int T) {
    queue<int> fila;

    memset(visit, 0, sizeof visit);
    for(int i = 1; i <= n; i++) {
        if(t[i] == T) {
            fila.push(i);
            visit[i] = 1;
            dist[i] = 0;
        }
    }

    while(!fila.empty()) {
        int u = fila.front(); fila.pop();

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!visit[v]) {
                visit[v] = 1;
                dist[v] = dist[u] + 1;
                fila.push(v);
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &s);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= k; i++) {
        bfs(i);
        for(int j = 1; j <= n; j++) {
            best[j].push(-dist[j]);
        }
    }

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 0; j < s; j++) {
            sum -= best[i].top();
            best[i].pop();
        }
        printf("%d ", sum);
    }

    return 0;
}