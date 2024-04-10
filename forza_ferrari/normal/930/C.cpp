#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100005],dp[100005][2],ans,pos[100005],len;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        ++a[x],--a[y+1];
    }
    for(int i=1;i<=n;++i)
        a[i]+=a[i-1];
    pos[len=1]=a[1];
    dp[1][0]=1;
    for(int i=2;i<=n;++i)
    {
        int p=upper_bound(pos+1,pos+len+1,a[i])-pos;
        dp[i][0]=p;
        pos[p]=a[i];
        len=max(p,len);
    }
    pos[len=1]=a[n];
    dp[n][1]=1;
    for(int i=n-1;i>=1;--i)
    {
        int p=upper_bound(pos+1,pos+len+1,a[i])-pos;
        dp[i][1]=p;
        pos[p]=a[i];
        len=max(p,len);
    }
    for(int i=1;i<=n;++i)
        ans=max(ans,dp[i][0]+dp[i][1]-1);
    cout<<ans<<'\n';
    return 0;
}