#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,m,a[300001],p[1000001],minn[1000001],cnt,sum[1000001],ans[2];
bool prime[1000001],vis[1000001];
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
inline void sieve()
{
    prime[1]=minn[1]=1;
    for(int i=2;i<=1000000;++i)
    {
        if(!prime[i])
        {
            p[++cnt]=i;
            minn[i]=i;
        }
        for(int j=1;j<=cnt&&i*p[j]<=1000000;++j)
        {
            prime[i*p[j]]=1;
            minn[i*p[j]]=min(minn[i],p[j]);
            if(i%p[j]==0)
                break;
        }
    }
}
signed main()
{
    sieve();
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
        {
            int w=read();
            a[i]=1;
            while(w^1)
            {
                int val=minn[w],tot=0;
                while(w%val==0)
                {
                    tot^=1;
                    w/=val;
                }
                if(tot)
                    a[i]*=val;
            }
            ++sum[a[i]];
        }
        ans[0]=ans[1]=0;
        for(int i=1;i<=n;++i)
            ans[0]=max(ans[0],sum[a[i]]);
        for(int i=1;i<=n;++i)
            if(a[i]!=1&&!vis[a[i]])
            {
                vis[a[i]]=1;
                if(sum[a[i]]&1^1)
                {
                    sum[1]+=sum[a[i]];
                    sum[a[i]]=0;
                }
            }
        ans[1]=sum[1];
        for(int i=1;i<=n;++i)
            ans[1]=max(ans[1],sum[a[i]]);
        m=read();
        while(m--)
        {
            int w=read();
            cout<<ans[min(w,1ll)]<<'\n';
        }
        sum[1]=vis[1]=0;
        for(int i=1;i<=n;++i)
            sum[a[i]]=vis[a[i]]=0;
    }
    return 0;
}