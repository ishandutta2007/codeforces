#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<int> vi;

const int MAXN = 2e6 + 100;
int N;
vi adj[MAXN];

ll dp[MAXN][4];
ll ans = 0;

void dfs(int n, int p = -1) {
    int c = 0;
    for(int i = 0;i < 4;i++) dp[n][i] = 0;
    dp[n][1] = 1;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p) continue;
        dfs(adj[n][i], n);
        ans += dp[n][1] * (dp[adj[n][i]][0] + dp[adj[n][i]][1] + dp[adj[n][i]][2] + dp[adj[n][i]][3]);
        ans += dp[n][3] * (dp[adj[n][i]][0] + dp[adj[n][i]][1] + dp[adj[n][i]][2] + 2*dp[adj[n][i]][3]);
        ans += (dp[adj[n][i]][1] + dp[adj[n][i]][3]) * (dp[n][0] + dp[n][2]);
        
        dp[n][0] += dp[adj[n][i]][2] + dp[adj[n][i]][3];
        dp[n][1] += dp[adj[n][i]][3];
        dp[n][2] += dp[adj[n][i]][0];
        dp[n][3] += dp[adj[n][i]][1];
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N - 1;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ans = 0;
    dfs(1);
    printf("%lld\n", ans);
    
    return 0;
}