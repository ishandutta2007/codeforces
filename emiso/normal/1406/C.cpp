#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, sz[MN], pai[MN];
vector<int> adj[MN];
pair<int, int> any;

void dfs(int no) {
    sz[no] = 1;
    for(int v : adj[no]) {
        if(v == pai[no]) continue;
        pai[v] = no;
        dfs(v);
        sz[no] += sz[v];
    }
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        any = {a, b};
    }

    if(n % 2 == 0) {
        dfs(1);
        int it = 0;
        for(int i = 1; !it && i <= n; i++)
            if(sz[i] == n / 2) it = i;
        if(it == 0) {
            printf("%d %d\n", any.first, any.second);
            printf("%d %d\n", any.first, any.second);
        } else {
            for(int v : adj[it]) {
                if(v != pai[it]) {
                    printf("%d %d\n", it, v);
                    printf("%lld %d\n", pai[it], v);
                    break;
                }
            }
        }
    } else {
        printf("%d %d\n", any.first, any.second);
        printf("%d %d\n", any.first, any.second);
    }
    if(--t) goto st;
    return 0;
}