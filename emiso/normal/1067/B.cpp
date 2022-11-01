#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, k, a, b, deg[MN], ddeg[MN], dep[MN], rreal[MN], last, ans = 1;
vector<int> adj[MN];

int dfs(int u, int pai = -1) {
    int ret = dep[u], ok = 0;
    for(int v : adj[u]) {
        if(v == pai) continue;
        dep[v] = dep[u] + 1;
        if(!ok) ret = max(ret, dfs(v, u));
        else if(ret != dfs(v, u)) ans = 0;
        ok = 1;
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0; i + 1< n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    queue<int> lf;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) {
            lf.push(i);
            rreal[i] = 1;
        }
        ddeg[i] = deg[i];
        dep[i] = 0;
    }

    while(!lf.empty()) {
        int u = lf.front(); lf.pop();
        last = u;
        for(int v : adj[u]) {
            deg[v]--;
            if(deg[v] == 1)
                lf.push(v);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(rreal[i] && last == i) ans = 0;
        else if(!rreal[i] && last != i && ddeg[i] < 4) ans = 0;
        else if(last == i && ddeg[i] < 3) ans = 0;
    }

    if(ans && dfs(last) != k) ans = 0;

    puts(ans ? "Yes" : "No");
    return 0;
}