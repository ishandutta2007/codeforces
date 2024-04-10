#include <bits/stdc++.h>
#define MN 200020

using namespace std;

int n, a, b, cor[MN], ok[MN];
vector<int> adj[MN];

int dfs(int no, int parent) {
    int ret = 0;
    for(int v : adj[no]) {
        if(v == parent) continue;
        ret += dfs(v, no);
    }

    if(cor[no]) {
        ret++;
        ok[parent] = 1;
    }
    else if(!ok[no]) cor[parent] = 1;
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for(int v : adj[1])
        for(int u : adj[v])
            if(u != 1) ans += dfs(u, v);

    printf("%d\n", ans);
    return 0;
}