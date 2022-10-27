#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1000000007;
ll dp[2005][2];
vector<int> fac[2005];
int n, k;

void pre(){
    for(int i = 1; i < 2005; i++){
        for(int j = 1; j <= i; j++){
            if(i%j == 0)fac[i].push_back(j);
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

    pre();
    cin>>n>>k;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
    }
    int flag = 1;
    for(int kkk = 2; kkk <= k; kkk++){
        for(int i = 1; i <= n; i++){
            dp[i][flag] = 0;
            for(auto x : fac[i]){
                dp[i][flag] += dp[x][flag^1];
            }
            dp[i][flag] %= mod;
        }
        flag ^= 1;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[i][flag^1];
    }
    cout<<ans%mod<<endl;
}