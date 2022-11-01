#include <bits/stdc++.h>
#define MN 1000100

using namespace std;

int n, q, a, b, z, t, mini[MN], miniRoot;
vector<int> adj[MN];

void dfs(int node, int parent =-1) {
    mini[node] = node;
    if(parent != -1) mini[node] = min(mini[parent], node);

    for(int i = 0; i < adj[node].size(); i++)
        if(adj[node][i] != parent)
            dfs(adj[node][i], node);
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i=1; i<n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int last = 0;
    scanf("%d %d", &t, &z);

    z = (z + last) % n + 1;
    miniRoot = z;
    dfs(z);

    for(int i=1; i < q; i++) {
        scanf("%d %d", &t, &z);
        z = (z + last) % n + 1;

        if(t == 1) {
            miniRoot = min(miniRoot, mini[z]);
        } else {
            printf("%d\n", min(miniRoot, mini[z]));
            last = min(miniRoot, mini[z]);
        }
    }

    return 0;
}