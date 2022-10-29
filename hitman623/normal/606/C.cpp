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
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    io
    long n,a[100005],i,dp[100005]={0},m=0;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=n-1;i>=0;i--)
    dp[a[i]]=dp[a[i]+1]+1;
    for(i=1;i<=n;++i)
    m=max(m,dp[i]);
    cout<<n-m;
    return 0;
}