#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1000000007;

ll dp[1005][1005];
int p[1005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }
    for(int j = 1; j <= n+1; j++){
        for(int i = j-1; i > 0; i--){
            dp[i][j] = (dp[p[i]][i] + dp[i+1][j] + 2)%mod;
        }
    }
    cout<<dp[1][n+1]<<endl;
}