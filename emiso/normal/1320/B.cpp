#include <bits/stdc++.h>

#define MN 1001000
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, visit[MN], dist[MN], k;
vector<int> adj[MN], adjr[MN], path;

void bfs(int ini) {
    visit[ini] = 1;
    dist[ini] = 0;
    queue<int> fila;
    fila.push(ini);

    while(!fila.empty()) {
        int u = fila.front(); fila.pop();
        for(int v : adj[u]) {
            if(visit[v] == 0) {
                visit[v] = 1;
                dist[v] = dist[u] + 1;
                fila.push(v);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[b].push_back(a);
        adjr[a].push_back(b);
    }

    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        path.push_back(x);
    }

    bfs(path.back());

    int ans1 = 0, ans2 = 0;
    for(int i = 0; i + 1 < k; i++) {
        int st = 0, howmany = 0;
        for(int v : adjr[path[i]]) {
            if(!visit[v]) continue;
            if(dist[v] == dist[path[i]] - 1) {
                howmany++;
                if(v == path[i+1]) st = 1;
            }
        }

        if(st == 0) {
            ans1++;
            ans2++;
        } else if(howmany > 1){
            ans2++;
        }
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}