#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    long n,a[3003],b[3003],c[3003],i,dp[3003][4]={0},term=0,j;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    cin>>b[i];
    for(i=0;i<n;++i)
    cin>>c[i];
    dp[0][0]=a[0];
    dp[0][1]=a[0];
    dp[0][2]=b[0];
    dp[0][3]=b[0];
    for(i=1;i<=n;++i)
    {
        dp[i][0]=a[i]+max(dp[i-1][2],dp[i-1][3]);
        dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][1]);
        dp[i][2]=b[i]+max(dp[i-1][3],dp[i-1][2]);
        dp[i][3]=c[i]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[n-1][0],dp[n-1][1]);
    return 0;
}