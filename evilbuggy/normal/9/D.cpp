#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<ll> dp[40];

void compute(int n){
    dp[n] = vector<ll>(n+1, 0);
    for(int l = 0; l < n; l++){
        int r = n - 1 - l;
        for(int i = 0; i < dp[l].size(); i++){
            for(int j = 0; j < dp[r].size(); j++){
                dp[n][max(i, j) + 1] += dp[l][i]*dp[r][j];
            }
        }
    }
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

    int n, h;
    cin>>n>>h;
    dp[0] = {1};
    dp[1] = {0, 1};
    for(int i = 2; i <= n; i++){
        compute(i);
    }
    ll ans = 0;
    for(int i = n; i >= h; i--){
        ans += dp[n][i];
    }
    cout<<ans<<endl;
}