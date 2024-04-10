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
    long n,m,i,a[100005],dp[100005],l,r,f,s[100005];
    cin>>n>>m;
    for(i=1;i<=n;++i)
    cin>>a[i];
    dp[1]=1;
    f=1;
    s[1]=1;
    for(i=2;i<=n;++i)
    if(a[i]==a[i-1])
    s[i]=s[i-1];
    else  s[i]=i;
    for(i=2;i<=n;++i)
    if(f)
    {
        dp[i]=dp[i-1];
        if(a[i]<a[i-1]) f=0;
    }
    else
    {
        if(a[i]>a[i-1])
        {
            dp[i]=s[i-1];
            f=1;
        }
        else dp[i]=dp[i-1];
    }
    for(i=0;i<m;++i)
    {
        cin>>l>>r;
        if(dp[r]<=l) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}