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

ll t = 1, n, m, q, a[MN], deg[MN], par[MN], dep[MN], qu[MN], qv[MN], vis[MN];
//char s[MN]; string str;
vector<int> adj[MN];

void dfs(int u, int pai = 0) {
    par[u] = pai;
    dep[u] = dep[pai] + 1;
    vis[u] = 1;

    for(int v : adj[u])
        if(!vis[v])
            dfs(v, u);
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(int i = 0, u, v; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &qu[i], &qv[i]);
        deg[qu[i]]++;
        deg[qv[i]]++;
    }
    
    ll odd = 0;
    for(int i = 1; i <= n; i++)
        odd += (deg[i] % 2);

    if(odd) {
        assert(odd % 2 == 0);
        printf("NO\n%lld\n", odd / 2);
    } else {
        puts("YES");
        dfs(1);
        
        for(int i = 0; i < q; i++) {
            int u = qu[i], v = qv[i], swp = 0;
            vector<int> l({u}), r({v});
            while(u != v) {
                if(dep[u] < dep[v]) {
                    swap(u, v);
                    swap(l, r);
                    swp = 1 - swp;
                }
                u = par[u];
                if(u != v) l.push_back(u);
            }
            if(swp == 1) {
                swap(u, v);
                swap(l, r);
            }
            l.insert(l.end(), r.rbegin(), r.rend());
            printf("%d\n", (int)l.size());
            for(int x : l) printf("%d ", x);
            puts("");
        }
    }
    return 0;
}