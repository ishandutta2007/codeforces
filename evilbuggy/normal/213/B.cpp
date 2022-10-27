#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1000000007;

ll c[105][105], dp[10][105];
int a[10];

ll calc(int dig, int len){
    if(dig == 9)return len >= a[9];
    if(dp[dig][len] != -1)return dp[dig][len];
    ll ret = 0;
    for(int i = a[dig]; i <= len; i++){
        ret += c[len - (dig == 0)][i]*calc(dig + 1, len - i);
        ret %= mod;
    }
    return dp[dig][len] = ret;
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

    int n;
    cin>>n;
    for(int i = 0; i < 10; i++){
        cin>>a[i];
    }
    memset(dp, -1, sizeof(dp));
    memset(c, 0, sizeof(c));
    c[0][0] = 1;
    for(int i = 1; i <= n; i++){
        c[i][0] = 1;
        for(int j = 1; j <= n; j++){
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
        }
    }
    ll ans = 0;
    for(int len = 1; len <= n; len++){
        ans += calc(0, len);
        ans %= mod;
    }
    cout<<ans<<endl;
}