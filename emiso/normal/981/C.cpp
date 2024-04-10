#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, m, a, b, pivot, maxi = -1, count_, deg[MN];
vector<int> adj[MN];
vector<pair<int, int> > paths;

void dfs(int node, int parent = -1) {
    count_++;

    for(int i = 0; i < adj[node].size(); i++) {
        if(adj[node][i] != parent) {
            dfs(adj[node][i], node);
            return;
        }
    }

    paths.push_back({node, pivot});
    return;
}

int main() {
    scanf("%d", &n);

    for(int i=1; i<n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    for(int i = 1; i <= n; i++) {
        if(maxi < deg[i]) {
            maxi = deg[i];
            pivot = i;
        }
    }

    count_++;
    for(int i = 0; i < adj[pivot].size(); i++) {
        dfs(adj[pivot][i], pivot);
    }

    if(count_ < n) printf("No\n");
    else {
        printf("Yes\n%d\n", paths.size());
        for(auto p : paths)
            printf("%d %d\n", p.first, p.second);
    }
    return 0;
}