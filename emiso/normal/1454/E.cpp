#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, mark[MN], pai[MN], visit[MN];
vector<int> adj[MN];

int find_cycle(int u) {
    if(visit[u]) return u;
    visit[u] = 1;
    for(int v : adj[u]) {
        if(v != pai[u]) {
            pai[v] = u;
            int c = find_cycle(v);
            if(c) return c;
        }
    }
    return 0;
}

int dfs(int u) {
    visit[u] = 1;
    int ret = 1;
    for(int v : adj[u])
        if(!visit[v] && !mark[v])
            ret += dfs(v);
    return ret;
}

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int r = find_cycle(1), tmp = r;
    do {
        mark[tmp] = 1;
        tmp = pai[tmp];
    } while(tmp != r);

    for(int i = 0; i <= n; i++) visit[i] = 0;
    for(int i = 1; i <= n; i++) {
        if(mark[i]) {
            ll sz = dfs(i);
            ans += sz * (sz-1);
            ans += 2LL * sz * (n - sz);
        }
    }

    printf("%lld\n", ans / 2);
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        visit[i] = mark[i] = pai[i] = 0;
    }
    if(--t) goto st;
    return 0;
}