#include <bits/stdc++.h>

#define MN 100100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, m, x, d, a[MN], counter, flag = 1, visit[2 * MN], comp[2 * MN];
vector<int> adj[2 * MN], adj2[2 * MN], rooms[2 * MN];
stack<int> pilha;

void dfs1(int v) {
    visit[v] = true;
    for(int i=0;i<adj[v].size();i++) {
        int u = adj[v][i];
        if(!visit[u])
            dfs1(u);
    }
    pilha.push(v);
}

void dfs2(int v) {
    visit[v] = true;
    for(int i=0;i<adj[v].size();i++) {
        int u = adj[v][i];
        if(!visit[u])
            dfs2(u);
    }
    comp[v] = counter;
}

int main() {
    int N = MN;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        for(int j = 0; j < x; j++) {
            scanf("%d", &d);
            rooms[d].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            int x = rooms[i][0], y = rooms[i][1];
            adj[x + N].push_back(y);
            adj[y + N].push_back(x);
            adj[y].push_back(x + N);
            adj[x].push_back(y + N);
        }

        else {
            int x = rooms[i][0], y = rooms[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);

            adj[x + N].push_back(y + N);
            adj[y + N].push_back(x + N);
        }
    }

    for(int i = 1; i <= n; i++) {
        int x = rooms[i][0], y = rooms[i][1];
        if(!visit[x])
            dfs1(x);
        if(!visit[y])
            dfs1(y);
        if(!visit[x + N])
            dfs1(x + N);
        if(!visit[y + N])
            dfs1(y + N);
    }

    memset(visit, 0 , sizeof visit);
    counter = 0;

    while(!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();

        if(!visit[v]) {
            counter++;
            dfs2(v);
        }
    }

    for(int i = 1; i <= n; i++) {
        int x = rooms[i][0], y = rooms[i][1];
        if(comp[x] == comp[x + N]) flag = 0;
        if(comp[y] == comp[y + N]) flag = 0;
    }

    printf("%s\n", flag ? "YES" : "NO");

    return 0;
}