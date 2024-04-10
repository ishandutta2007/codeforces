#include <bits/stdc++.h>

#define MN 300030

using namespace std;

int low[MN], num[MN], c, ans, N, M, a, b;
vector<int> adj[MN];
int parent[MN];
int dist[MN], visit[MN];

vector<pair<int, int> > adj2[MN];
set<pair<int, int> > br;

void dfs(int u) {
    low[u] = num[u] = c++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            parent[v] = u;
            dfs(v);
            if (low[v] > num[u]) {
                br.insert(make_pair(u, v));
                br.insert(make_pair(v, u));
            }
            low[u] = min(low[u], low[v]);
        } else if (v != parent[u])
            low[u] = min(low[u], num[v]);
    }
}

int bfs(int no) {
    memset(visit, 0, sizeof visit);
    dist[no] = 0; visit[no] = 1;

    deque<int> fila; fila.push_back(no);

    int m = -1, md = -1;
    while(!fila.empty()) {
        int v = fila.front(); fila.pop_front();
        if(dist[v] > md) {
            md = dist[v];
            m = v;
        }
        for(pair<int, int> u : adj2[v]) {
            if(!visit[u.first]) {
                if(u.second == 1) {
                    dist[u.first] = dist[v] + 1;
                    fila.push_back(u.first);
                    visit[u.first] = 1;
                } else {
                    dist[u.first] = dist[v];
                    fila.push_front(u.first);
                    visit[u.first] = 1;
                }
            }
        }
    }
    return m;
}

int main() {
    scanf("%d %d",&N, &M);

    for(int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(parent, -1, sizeof parent);
    memset(num, -1, sizeof num);
    memset(low, -1, sizeof low);
    c = 0;
    dfs(1);

    for(int u = 1; u <= N; u++) {
        for(int v : adj[u]) {
            if(br.count(make_pair(u, v))) {
                adj2[u].emplace_back(v, 1);
            } else {
                adj2[u].emplace_back(v, 0);
            }
        }
    }

    int y = bfs(1);
    int x = bfs(y);

    printf("%d\n", dist[x]);
    return 0;
}