#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a, b;
ll sz[MN][2], cor[MN];
vector<int> adj[MN];

void dfs(int node, int c, int parent = -1) {
    cor[node] = c;
    sz[node][c]++;
    for(int i = 0; i < adj[node].size(); i++) {
        int v = adj[node][i];
        if(v == parent) continue;

        dfs(v, 1 - c, node);
        sz[node][0] += sz[v][0];
        sz[node][1] += sz[v][1];
    }
}

int main() {
    scanf("%d", &n);

    for(int i=1; i<n; i++) {
        scanf("%d %d",&a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);
    ll ans = (sz[1][0] * sz[1][1]) -n + 1;

    printf("%lld\n", ans);
    return 0;
}