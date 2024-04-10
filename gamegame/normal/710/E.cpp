#include<iostream>
using namespace std;
long long dp[10000001];
int n,x,y;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    dp[1]=x;
    for(int i=2; i<=n ;i++){
        if(i&1) dp[i]=min(dp[(i+1)/2]+x+y,dp[i-1]+x);
        else dp[i]=min(dp[i/2]+y,dp[i-1]+x);
    }
    cout << dp[n] << '\n';
}