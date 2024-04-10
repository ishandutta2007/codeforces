#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int n, M, W;
int visit[1010], c[1010], w[1010], b[1010], comp;
ll ans = 0, totalB[1010], totalW[1010], dp[1010][1010];
vector<int> amigas[1010], adj[1010];

void dfs(int node, int id) {
    if(visit[node]) return;
    visit[node]++;
    c[node] = id;
    for(int i = 0; i < adj[node].size(); i++)
        dfs(adj[node][i], id);
}

ll solve(int cap, int cmp) {
    if(dp[cap][cmp] != -1) return dp[cap][cmp];
    if(cmp == -1) return 0;

    ll ret = 0;
    if(totalW[cmp] > cap) ret = solve(cap, cmp - 1);
    else ret = max(solve(cap, cmp-1), solve(cap - totalW[cmp], cmp-1) + totalB[cmp]);

    for(int i = 0; i < amigas[cmp].size(); i++) {
        int v = amigas[cmp][i];
        if(w[v] <= cap) ret = max(ret, solve(cap - w[v], cmp - 1) + b[v]);
    }

    dp[cap][cmp] = ret;
    return ret;
}

int main() {
    int x, y;
    scanf("%d %d %d",&n ,&M, &W);
    memset(dp, -1, sizeof dp);

    for(int i=1; i<=n; i++) {
        scanf("%d",&w[i]);
    }

    for(int i=1; i<=n; i++) {
        scanf("%d",&b[i]);
    }

    for(int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++) {
        if(!visit[i]) dfs(i, comp);
        comp++;
    }

    for(int i=1;i<=n;i++) {
        amigas[c[i]].push_back(i);
    }

    for(int i=1;i<=n;i++) {
        totalB[c[i]] += b[i];
        totalW[c[i]] += w[i];
    }

    ans = solve(W, comp - 1);

    printf("%lld\n",ans);
    return 0;
}