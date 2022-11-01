#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, x, y, sz[MN], a, b, flo[MN], ans;
vector<int> adj[MN];

ll dfs(int node, int parent = -1) {
    sz[node] = 1;
    if(node == x) flo[node] = 1;

    for(int v : adj[node]) {
        if(v != parent) {
            sz[node] += dfs(v, node);
            if(flo[v]) flo[node] = 1;
        }
    }

    return sz[node];
}

int main() {
    scanf("%lld %lld %lld", &n, &x, &y);

    for(int i = 1; i < n; i++) {
        scanf("%lld %lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(y);
    ans = n * (n - 1);
    ll ft = sz[x];
    ll bt = 1;
    for(int v : adj[y]) {
        if(!flo[v]) bt += sz[v];
    }

    ans -= ft * bt;

    printf("%lld\n", ans);
    return 0;
}