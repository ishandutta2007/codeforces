#include <bits/stdc++.h>

using namespace std;

long long int mod = 998244353;
int dp[1005][2005][4];

int calcDp(int n, int k, int state){
    if(dp[n][k][state] != -1)return dp[n][k][state];
    if(n == 1){
        if(state == 0 || state == 3){
            if(k == 1)return 1;
            else return 0;
        }else{
            if(k == 2)return 1;
            else return 0;
        }
    }
    long long int ret = 0;
    if(state == 0){
        ret += calcDp(n-1, k, 0);
        ret += calcDp(n-1, k, 1);
        ret += calcDp(n-1, k, 2);
        ret += calcDp(n-1, k-1, 3);
    }else if(state == 1){
        ret += calcDp(n-1, k-1, 0);
        ret += calcDp(n-1, k, 1);
        ret += calcDp(n-1, k-2, 2);
        ret += calcDp(n-1, k-1, 3);
    }else if(state == 2){
        ret += calcDp(n-1, k-1, 0);
        ret += calcDp(n-1, k-2, 1);
        ret += calcDp(n-1, k, 2);
        ret += calcDp(n-1, k-1, 3);
    }else{
        ret += calcDp(n-1, k-1, 0);
        ret += calcDp(n-1, k, 1);
        ret += calcDp(n-1, k, 2);
        ret += calcDp(n-1, k, 3);
    }
    ret %= mod;
    return dp[n][k][state] = ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    memset(dp, -1 , sizeof(dp));
    long long int ans = 0;
    for(int state = 0; state < 4; state++){
        ans += calcDp(n,k,state);
    }
    cout<<ans%mod;
}