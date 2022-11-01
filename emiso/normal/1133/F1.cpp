#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, m, deg[MN], maxi;
vector<int> adj[MN];
vector<pair<int, int>> ans, edges;

int pai[MN], rnk[MN];
int find(int x) {
    if(x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(rnk[a] < rnk[b]) swap(a, b);
    pai[b] = a;
    if(rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

void add(int u, int v) {
    if(merge(u, v)) ans.emplace_back(u, v);
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges.emplace_back(a, b);

        adj[a].push_back(b);
        adj[b].push_back(a);

        deg[a]++;
        deg[b]++;

        if(deg[a] > deg[maxi]) maxi = a;
        if(deg[b] > deg[maxi]) maxi = b;
    }

    for(int i = 0; i < MN; i++)
        pai[i] = i, rnk[i] = 0;

    for(int v : adj[maxi]) add(maxi, v);
    for(auto e : edges) add(e.first, e.second);

    for(auto e : ans) {
        printf("%d %d\n", e.first, e.second);
    }
    return 0;
}