#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

#define pb push_back

const int MAXN = 1e6 + 1000;
const int MAXK = 1e6 + 1000;
const int INF = 1e9 + 1e6;

typedef vector<int> vi;

int N, K;
vi adj[MAXN];
int deg[MAXN], dp[MAXN], ans;

void dfs(int n, int p) {
    if(deg[n] == 1) dp[n] = 0; else dp[n] = -INF;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p) continue;
        dfs(adj[n][i], n);
        if(dp[adj[n][i]] + dp[n] + 1 > K) {
            ans++;
            if(dp[adj[n][i]] + 1 < dp[n]) dp[n] = dp[adj[n][i]] + 1;
        } else {
            if(dp[adj[n][i]] + 1 > dp[n]) dp[n] = dp[adj[n][i]] + 1;
        }
    }
}

int main() {
    scanf("%d%d", &N, &K);
    
    for(int i = 0;i <= N;i++) deg[i] = 0, dp[i] = -INF;
    
    for(int i = 0;i < N - 1;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    
    ans = 1;
    for(int i = 1;i <= N;i++) if(deg[i] != 1) {
        dfs(i, -1);
        break;
    }
    printf("%d\n", ans);
    
    return 0;
}