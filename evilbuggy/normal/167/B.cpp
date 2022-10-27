#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, l, k, a[205];
ld p[205], dp[205][205][205];
bool vis[205][205][205];

ld calc(int x, int y, int z){
    if(x == n + 1){
        if((y >= z) && (z >= l))return 1.0;
        return 0.0;
    }
    if(vis[x][y][z])return dp[x][y][z];
    vis[x][y][z] = true;
    ld ret = p[x]*calc(x + 1, min(y + a[x], 200), z + 1);
    ret += (1.0 - p[x])*calc(x + 1, y, z);
    return dp[x][y][z] = ret;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    cin>>n>>l>>k;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
        p[i] /= 100.0;
    }
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] += 1;
    }
    memset(vis, false, sizeof(vis));
    cout<<calc(1, k, 0)<<endl;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= 2; j++){
    //         for(int k = 0; k <= 3; k++){
    //             if(!vis[i][j][k])continue;
    //             cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
    //         }
    //     }
    // }
}