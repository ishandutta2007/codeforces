#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const int mod = 1000000007;
int dp[2][400005];
int r, g, h;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>r>>g;
    h = 1;
    while(h*(h+1)/2 <= r+g)h++;
    h--;
    memset(dp, 0, sizeof(dp));
    if(r >= 1)dp[0][1] = 1;
    if(g >= 1)dp[0][0] = 1;
    int flag = 1;
    for(int i = 2; i <= h; i++){
        int mx = i*(i+1)/2;
        for(int ir = 0; ir <= r; ir++){
            dp[flag][ir] = 0;
            if(g + ir < mx)continue;
            dp[flag][ir] = dp[flag^1][ir];
            if(ir >= i)dp[flag][ir] += dp[flag^1][ir-i];
            dp[flag][ir] %= mod;
        }
        flag ^= 1;
    }
    int ans = 0;
    for(int i = 0; i <= r; i++){
        (ans += dp[flag^1][i]) %= mod;
    }
    cout<<ans<<endl;
}