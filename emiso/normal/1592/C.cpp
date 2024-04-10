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

ll t = 1, n, k, ans, a[MN], x[MN];
//char s[MN]; string str;
vector<int> adj[MN];

int dfs3(int u, int pai = 0) {
    int cnt = 0;
    for(int v : adj[u])
        if(v != pai)
            cnt += dfs3(v, u);
    return max(cnt, 0 + (x[u] == x[1]));
}

int dfs2(int u, int ja, int pai = 0) {
    if(x[u] == x[1] && ja) return 1;
    if(x[u] == 0) ja = 1;
    for(int v : adj[u])
        if(v != pai)
            if(dfs2(v, ja, u))
                return 1;
    return 0;
}

int dfs(int u, int pai = 0) {
    x[u] = a[u];
    for(int v : adj[u])
        if(v != pai)
            x[u] ^= dfs(v, u);
    return x[u];
}

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        adj[i].clear();
    }
    for(int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    if(x[1] == 0) ans = 1;

    if(k > 2) {
        ans |= dfs2(1, 0);
        ans |= (dfs3(1) > 1);
    }

    puts(ans ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}