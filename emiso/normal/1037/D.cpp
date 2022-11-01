#include <bits/stdc++.h>

#define MN 201000

using namespace std;

int n, ans, a, b, dist[MN], pai[MN];
vector<int> adj[MN];
queue<int> ordem[MN];

void dfs(int node, int parent = -1) {
    pai[node] = parent;
    for(int v : adj[node]) {
        if(v != parent) {
            dist[v] = dist[node] + 1;
            dfs(v, node);
        }
    }
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist[1] = 0;
    dfs(1);
    ordem[0].push(-1);

    int last = 0, flag = 1;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);

        while(!ordem[dist[a]].empty() && ordem[dist[a]].front() != pai[a])
            ordem[dist[a]].pop();

        if(ordem[dist[a]].empty()) {
            flag = 0;
            break;
        }
        ordem[dist[a]+1].push(a);

        if(dist[a] < last) {
            flag = 0;
            break;
        }
        last = dist[a];
    }

    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}