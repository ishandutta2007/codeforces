#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int dp[2][505][505];
int a[505];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, b, mod;
    cin>>n>>m>>b>>mod;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int flag = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= m; k++){
                dp[flag][j][k] = dp[flag^1][j][k];
                if(j >= a[i]){
                    (dp[flag][j][k] += dp[flag][j - a[i]][k - 1]) %= mod;
                }
            }
        }
        flag ^= 1;
    }
    flag ^= 1;
    int sum = 0;
    for(int i = 0; i <= b; i++){
        (sum += dp[flag][i][m]) %= mod;
    }
    cout<<sum<<endl;
}