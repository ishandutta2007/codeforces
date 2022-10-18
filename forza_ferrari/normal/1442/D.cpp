#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
int n,m,v[3001],w[3001],ans,dp[3001];
vector<int> sum[3001];
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
void solve(int l,int r)
{
    if(l==r)
    {
        for(register int i=0;i<(int)sum[l].size();++i)
        {
            if(i>m)
                break;
            ans=max(ans,dp[m-i]+sum[l][i]);
        }
        return;
    }
    int mid=(l+r)>>1;
    int tmp[3001];
    for(register int i=0;i<=m;++i)
        tmp[i]=dp[i];
    for(register int i=mid+1;i<=r;++i)
        for(register int j=m;j>=v[i];--j)
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
    solve(l,mid);
    for(register int i=0;i<=m;++i)
        dp[i]=tmp[i];
    for(register int i=l;i<=mid;++i)
        for(register int j=m;j>=v[i];--j)
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
    solve(mid+1,r);
}
signed main()
{
    n=read(),m=read();
    for(register int i=1;i<=n;++i)
    {
        int p=read();
        sum[i].push_back(0);
        for(register int j=1;j<=p;++j)
            sum[i].push_back(sum[i].back()+read());
        v[i]=p;
        w[i]=sum[i].back();
    }
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}