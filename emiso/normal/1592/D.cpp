#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

ll n;
vector<int> adj[MN];
int ok[MN], par[MN];
vector<int> cur;

void dfs(int u, int pai = 0) {
    par[u] = pai;
    cur.push_back(u);
    for(int v : adj[u])
        if(v != pai)
            dfs(v, u);
}

int query(int x) {
    printf("? %d", x);
    for(int i = 0; i < x; i++) printf(" %d", cur[i]);
    printf("\n");
    fflush(stdout);

    int val;
    scanf("%d", &val);
    return val;
}

int main() {
    scanf("%lld", &n);

    fill(ok, ok + n + 1, 1);
    for(int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printf("? %lld", n);
    for(int i = 1; i <= n; i++) printf(" %d", i);
    printf("\n");
    fflush(stdout);

    int maxi;
    scanf("%d", &maxi);

    dfs(1);
    int l = 2, r = n, m;
    while(l < r) {
        m = (l + r) / 2;
        if(query(m) == maxi) r = m;
        else l = m + 1;
    }

    printf("! %d %d\n", par[cur[l-1]], cur[l-1]);
    fflush(stdout);
    return 0;
}