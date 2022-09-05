#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll dp[2111][2111],t[2111],v[2111];
ll min(ll x,ll y){return x<y?x:y;}
ll f(ll x){return x<0?0:x;}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i]>>v[i];
    }
    for(int i=1;i<=n;i++)dp[0][i]=(1ll<<62);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=min(dp[i-1][f(j-t[i]-1)]+v[i],dp[i-1][j]);
        }
    }
    cout<<dp[n][n];
}