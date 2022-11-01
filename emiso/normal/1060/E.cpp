#include <bits/stdc++.h>

#define MN 200100

using namespace std;
typedef long long ll;

ll n, ans, a, b, sz[MN], parity[2];
vector<ll> adj[MN];

void dfs(int node, int par = 0, int pai = -1) {
    sz[node]++;
    parity[par]++;
    for(int v : adj[node]) {
        if(v == pai) continue;
        dfs(v, 1 - par, node);
        sz[node] += sz[v];
        ans += sz[v] * (n - sz[v]);
    }
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i < n; i++) {
        scanf("%lld %lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    ans += (parity[0] * parity[1]);
    printf("%lld\n", ans / 2);
    return 0;
}