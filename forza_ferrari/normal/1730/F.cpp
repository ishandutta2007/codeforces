#include<iostream>
#include<cstdio>
using namespace std;
int n,m,dp[5005][1<<8],sum[5005],pos[5005],cnt;
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x)
{
    ++cnt;
    for(;x<=n;x+=lowbit(x))
        ++sum[x];
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
inline int calc(int w,int s,int p)
{
    int res=cnt-query(pos[p]);
    for(int i=1;i<=m;++i)
        if(s>>(i-1)&1)
            res+=pos[w+i]>pos[p];
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        pos[x]=i;
    }
    for(int i=0;i<=n+1;++i)
        for(int s=0;s<1<<m;++s)
            dp[i][s]=1e9;
    dp[1][0]=0;
    for(int i=1;i<=n;++i)
    {
        for(int s=0;s<1<<min(m,n-i);++s)
            if(dp[i][s]<1e9)
            {
                for(int j=1;j<=min(m,n-i);++j)
                    if(!(s>>(j-1)&1))
                        dp[i][s|(1<<(j-1))]=min(dp[i][s|(1<<(j-1))],dp[i][s]+calc(i,s,i+j));
                int d=__builtin_ctz(((1<<30)-1)^s)+1;
                dp[i+d][s>>d]=min(dp[i+d][s>>d],dp[i][s]+calc(i,s,i));
            }
        update(pos[i]);
    }
    cout<<dp[n+1][0]<<'\n';
    return 0;
}