#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

#define pb push_back

typedef vector<int> vi;

const int MAXN = 101000;

int N;

vi adj[MAXN];
int dp[MAXN][3];
int o[MAXN], t, p[MAXN];

void dfs(int n, int q = -1) {
    p[n] = q;
    for(int i = 0;i < adj[n].size();i++) if(adj[n][i] != q) dfs(adj[n][i], n);
    o[t++] = n;
}

int solve(int k) {
    for(int i = 0;i <= N;i++) for(int j = 0;j < 3;j++) dp[i][j] = 0;
    for(int i = 0;i < N - 1;i++) {
        dp[o[i]][1]++;
        if(dp[o[i]][1] + dp[o[i]][2] >= k) dp[o[i]][0]++, dp[o[i]][1] = 0;
        dp[p[o[i]]][0] += dp[o[i]][0];
        for(int j = 1, l = dp[o[i]][1];j <= 2;j++) if(l > dp[p[o[i]]][j]) swap(l, dp[p[o[i]]][j]);
    }
    return dp[1][0] + (dp[1][1] + dp[1][2] >= k - 1);
}

int ans[MAXN];

int main() {
    scanf("%d", &N);
    
    for(int i = 0;i < N - 1;i++) {
        int a[2];
        scanf("%d%d", a, a + 1);
        adj[a[0]].pb(a[1]);
        adj[a[1]].pb(a[0]);
    }
    
    t = 0;
    dfs(1);
    
    for(int i = 1;i * i <= N;i++) ans[i] = solve(i);
    
    t = N + 1;
    for(int i = 0;i * i <= N;i++)
    {
        int l = 0, h = t;
        while(l < h - 1) {
            int m = l + (h - l)/2;
            if(solve(m) > i) l = m;
            else h = m;
        }
        while(t > h) ans[--t] = i;
    }
    
    for(int i = 1;i <= N;i++) printf("%d\n", ans[i]);
    
    return 0;
}