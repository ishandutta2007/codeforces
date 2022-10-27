#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 100000000;
ll dp[105][105][2];
int n1, n2, k1, k2;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n1>>n2>>k1>>k2;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= k1; i++){
        dp[i][0][0] = 1;
    }
    for(int i = 0; i <= k2; i++){
        dp[0][i][1] = 1;
    }
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            for(int l = 1; l <= k1; l++){
                if(l > i)break;
                dp[i][j][0] += dp[i-l][j][1];
            }
            dp[i][j][0] %= mod;
            for(int l = 1; l <= k2; l++){
                if(l > j)break;
                dp[i][j][1] += dp[i][j-l][0];
            }
            dp[i][j][1] %= mod;
        }
    }
    cout<<(dp[n1][n2][0] + dp[n1][n2][1])%mod<<endl;
}