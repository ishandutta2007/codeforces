#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, dp[1000005][5][5], vis[1000005][5][5], f[1000005];

int dfs(int i, int x, int y){
    if(i == m - 1){
        if(f[i] < x || f[i+1] < y)return -1e8;
        return (f[i] - x)/3 + (f[i+1] - y)/3;
    }
    if(vis[i][x][y])return dp[i][x][y];
    if(f[i] < x)return -1e8;
    int ret = -1e8;
    for(int j = 0; j <= min(2, f[i] - x); j++){
        ret = max(ret, dfs(i + 1, y + j, j) + j + (f[i] - x - j)/3);
    }
    vis[i][x][y] = 1;
    return dp[i][x][y] = ret;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin>>n>>m;
    memset(f, 0, sizeof(f));
    int x;
    for(int i = 1; i <= n; i++){
        cin>>x;
        f[x]++;
    }
    memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    cout<<dfs(1, 0, 0)<<endl;
}