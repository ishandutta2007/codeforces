#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll inf = (1LL<<58);

ll a[1005][1005];
ll dp[1005][1005][4];
int n, m;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            for(int k = 0; k < 4; k++){
                dp[i][j][k] = -inf;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ll ret = 0;
            if(i != 1)ret = max(ret, dp[i-1][j][0]);
            if(j != 1)ret = max(ret, dp[i][j-1][0]);
            dp[i][j][0] = a[i][j] + ret;
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            ll ret = 0;
            if(i != n)ret = max(ret, dp[i+1][j][1]);
            if(j != m)ret = max(ret, dp[i][j+1][1]);
            dp[i][j][1] = a[i][j] + ret;
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= m; j++){
            ll ret = 0;
            if(i != n)ret = max(ret, dp[i+1][j][2]);
            if(j != 1)ret = max(ret, dp[i][j-1][2]);
            dp[i][j][2] = a[i][j] + ret;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){
            ll ret = 0;
            if(i != 1)ret = max(ret, dp[i-1][j][3]);
            if(j != m)ret = max(ret, dp[i][j+1][3]);
            dp[i][j][3] = a[i][j] + ret;
        }
    }

    ll tmp, ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            tmp = dp[i-1][j][0] + dp[i+1][j][1] + dp[i][j-1][2] + dp[i][j+1][3];
            ans = max(ans, tmp);
            tmp = dp[i][j-1][0] + dp[i][j+1][1] + dp[i+1][j][2] + dp[i-1][j][3];
            ans = max(ans, tmp);
        }
    }
    cout<<ans<<endl;
}