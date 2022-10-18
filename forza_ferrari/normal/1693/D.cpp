#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,a[200001],dp[200001][2],pos[200001],ans;
inline void calc(int x)
{
    dp[x][0]=n+1,dp[x][1]=0;
    for(int i=x+1;i<=n;++i)
    {
        dp[i][0]=-1,dp[i][1]=n+1;
        if(a[i]>a[i-1])
            dp[i][0]=dp[i-1][0];
        else
            dp[i][1]=dp[i-1][1];
        if(a[i]>dp[i-1][1])
            dp[i][0]=max(dp[i][0],a[i-1]);
        if(a[i]<dp[i-1][0])
            dp[i][1]=min(dp[i][1],a[i-1]);
        if(dp[i][0]==-1&&dp[i][1]==n+1)
        {
            pos[x]=i-1;
            return;
        }
    }
    pos[x]=n;
}
inline void solve(int l,int r)
{
    if(pos[l]==pos[r])
    {
        for(int i=l;i<=r;++i)
            pos[i]=pos[l];
        return;
    }
    if(r-l<=1)
        return;
    int mid=(l+r)>>1;
    calc(mid);
    solve(l,mid);
    solve(mid,r);
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    calc(1);
    calc(n);
    solve(1,n);
    for(int i=1;i<=n;++i)
        ans+=pos[i]-i+1;
    cout<<ans<<'\n';
    return 0;
}