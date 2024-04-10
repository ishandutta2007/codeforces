#include <bits/stdc++.h>
#define N 105
using namespace std;
int n,dp[N];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s;
    for(int i=2;i<=n;i++){
        if(s[i-1]!=s[i-2])
            dp[i]=max(dp[i-1],dp[i-2]+1);
        else
            dp[i]=dp[i-1];
    }
    cout<<n-dp[n];
    return 0;
}