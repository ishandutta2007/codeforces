#include <bits/stdc++.h>

#define MN 200020

using namespace std;
typedef long long ll;

ll n, p0[MN], p1[MN], p01[MN], p10[MN];
vector<int> adj[MN][2];

ll solve(int u, int pai = -1) {
    ll ans = 0;

    for(int v : adj[u][0]) {
        if(v == pai) continue;
        ans += solve(v, u);
        p0[u] += p0[v] + 1;
        p01[u] += p01[v] + p1[v];
    }

    for(int v : adj[u][1]) {
        if(v == pai) continue;
        ans += solve(v, u);
        p1[u] += p1[v] + 1;
        p10[u] += p10[v] + p0[v];
    }

    for(int i = 0; i < adj[u][0].size(); i++) {
        int v = adj[u][0][i];
        if(v == pai) continue;
        ans += (p0[v] + 1) * (p0[u] - p0[v] - 1);
        ans += (p0[v] + 1) * (p01[u] - p01[v] - p1[v]);
        ans += (p0[v] + 1) * (p1[u]);
    }

    for(int i = 0; i < adj[u][1].size(); i++) {
        int v = adj[u][1][i];
        if(v == pai) continue;
        ans += (p10[v] + p0[v]) * (p1[u] - p1[v] - 1);
        ans += (p1[v] + 1) * (p1[u] - p1[v] - 1);
    }

    ans += 2*p0[u] + 2*p1[u] + p10[u] + p01[u];
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a][c].push_back(b);
        adj[b][c].push_back(a);
    }
    printf("%lld\n", solve(1));
    return 0;
}