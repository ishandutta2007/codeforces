#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,m,dp[200001],cnt;
vector<int> v[200001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void dfs(int k,int f,int lim)
{
    dp[k]=0;
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs(i,k,lim);
        if(k!=1&&dp[i]==lim-1)
            ++cnt;
        else
            dp[k]=max(dp[k],dp[i]+1);
    }
}
inline bool check(int lim)
{
    cnt=0;
    dfs(1,0,lim);
    return dp[1]<=lim&&cnt<=m;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;++i)
            v[i].clear();
        for(int i=2;i<=n;++i)
            v[read()].emplace_back(i);
        int l=0,r=n-1,mid,ans=n-1;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}