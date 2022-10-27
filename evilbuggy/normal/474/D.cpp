#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1000000007;

ll dp[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, k;
    cin>>t>>k;
    dp[0] = 1;
    for(int i = 1; i < 100005; i++){
        if(i < k)dp[i] = 1;
        else dp[i] = (dp[i-1] + dp[i-k])%mod;
    }
    for(int i = 1; i < 100005; i++){
        (dp[i] += dp[i-1]) %= mod;
    }
    int a, b;
    while(t--){
        cin>>a>>b;
        cout<<(dp[b] - dp[a-1] + mod)%mod<<endl;
    }
}