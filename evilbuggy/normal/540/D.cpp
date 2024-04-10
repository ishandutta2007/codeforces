#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

ld dp[105][105][105];
int vis[105][105][105];

ld dfs(int r, int s, int p){
    if(r < 0)return 0.0;
    if(s < 0)return 0.0;
    if(p < 0)return 0.0;
    if(r == 0)return dp[r][s][p] = 0.0;
    if(p == 0 && s == 0)return dp[r][s][p] = 1.0;
    if(vis[r][s][p])return dp[r][s][p];
    ld m = r*p + s*r + p*s;
    if(m == 0)cout<<r<<" "<<s<<" "<<p<<endl;
    ld ret = (r*p/m)*dfs(r-1,s,p) + (r*s/m)*dfs(r,s-1,p) + (p*s/m)*dfs(r,s,p-1);
    vis[r][s][p] = 1;
    return dp[r][s][p] = ret;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            for(int k = 0; k < 105; k++){
                dp[i][j][k] = 0;
                vis[i][j][k] = 0;
            }
        }
    }

    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            for(int k = 0; k < 105; k++){
                if(vis[i][j][k] == 0){
                    dfs(i, j, k);
                }
            }
        }
    }
    int r, p, s;
    cin>>r>>s>>p;
    cout<<setprecision(30)<<dfs(r,s,p)<<" "<<dfs(s,p,r)<<" "<<dfs(p,r,s)<<endl;
}