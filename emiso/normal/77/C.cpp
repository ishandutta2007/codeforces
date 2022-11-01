#include <bits/stdc++.h>

#define MN 100100

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll dp[MN];
vector<pll> children[MN];
vector<int> adj[MN];
int n, k[MN], u, v, st;

bool cmp(pll a, pll b) {
    return a.first > b.first;
}

void dfs(int node, int parent = -1) {
    dp[node] = {0, k[node]};
    if(node == st) dp[node].second++;

    for(int i=0; i<adj[node].size(); i++) {
        int u = adj[node][i];
        if(u != parent)
            dfs(u, node);
    }
}

void solve(int node, int parent = -1) {

    for(int i=0; i<adj[node].size(); i++) {
        int u = adj[node][i];
        if(u != parent) {
            solve(u, node);
            children[node].push_back(dp[u]);
        }
    }

    if(dp[node].second) {
        dp[node].second--;
        dp[node].first++;
    }

    sort(children[node].begin(), children[node].end(), cmp);
    for(int i=0; i<children[node].size() && dp[node].second; i++) {
        dp[node].first += children[node][i].first + 1;
        dp[node].second--;
    }

    for(int i=0; i<children[node].size() && dp[node].second; i++) {
        int eaten = min(dp[node].second, children[node][i].second);
        dp[node].second -= eaten;
        dp[node].first += 2 * eaten;
    }
}

int main() {
    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        scanf("%d", &k[i]);
    }

    for(int i=1;i<n;i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    scanf("%d", &st);

    dfs(st);
    solve(st);
    dp[st].first--;
    printf("%lld\n", dp[st].first);


    /* for(int i=1; i<=n;i++) {
        printf("node %d k %d x %lld y %lld\n", i, k[i], dp[i].first, dp[i].second);
    } */

    return 0;
}