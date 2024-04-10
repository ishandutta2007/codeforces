#include <bits/stdc++.h>

#define MN 100100

using namespace std;

vector<int> adj[MN];
int parent[MN],subt[MN],visit[MN];
double ans[MN];

void dfs(int node) {
    visit[node] = 1;
    subt[node] = 1;

    for(int i=0;i<adj[node].size();i++) {
        int v = adj[node][i];
        if(!visit[v])
            dfs(v);
        subt[node] += subt[v];
    }
}

int main() {
    int n;
    scanf("%d",&n);
    parent[1] = 1;
    for(int i=2;i<=n;i++) {
        scanf("%d",&parent[i]);
        adj[parent[i]].push_back(i);
    }
    dfs(1);

    ans[1] = 1;
    printf("%.6f",ans[1]);
    for(int i=2;i<=n;i++) {
        ans[i] = ans[parent[i]] + 1 + (subt[parent[i]] - subt[i] - 1.0) / 2;
        printf(" %.6f",ans[i]);
    }

    return 0;
}