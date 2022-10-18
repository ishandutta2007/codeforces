#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,m,lim,block,maxn,minn,ans,a[1000005],dp[5000005],sum[5000005];
bool tag[5000005];
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
inline int Max(int x,int y)
{
    return x>y? x:y;
}
inline int Min(int x,int y)
{
    return x<y? x:y;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        block=sqrt(m);
        for(int i=1;i<=m;++i)
        {
            tag[i]=sum[i]=0;
            dp[i]=(i>=min(3000,m)? i:m+1);
        }
        tag[m+1]=sum[m+1]=dp[m+1]=0;
        maxn=-1e9;
        minn=1e9;
        lim=m+1;
        for(int i=1;i<=n;++i)
        {
            tag[a[i]=read()]=1;
            maxn=Max(maxn,a[i]);
            minn=Min(minn,a[i]);
        }
        ans=maxn-minn;
        for(int i=1;i<=m;++i)
            sum[dp[i]]+=tag[i];
        for(int i=min(3000,m);i>=1;--i)
        {
            sum[dp[i]]-=tag[i];
            sum[dp[i]=i]+=tag[i];
            for(int j=i<<1;j<=m;j+=i)
            {
                sum[dp[j]]-=tag[j];
                dp[j]=Min(dp[j],Max(dp[j/i],i));
                sum[dp[j]]+=tag[j];
            }
            while(!sum[lim])
                --lim;
            if(lim<=m)
                ans=Min(ans,lim-i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}