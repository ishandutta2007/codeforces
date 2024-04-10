#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[200001],dp[200001],node[200001],cnt,pre[200001],fst[200001],lst[200001],w[200001],ans;
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
int main()
{
    t=read();
    while(t--)
    {
        ans=0;
        n=read();
        for(int i=1;i<=n;++i)
        {
            node[i]=a[i]=read();
            pre[i]=fst[i]=lst[i]=w[i]=0;
        }
        sort(node+1,node+n+1);
        cnt=unique(node+1,node+n+1)-node-1;
        for(int i=1;i<=n;++i)
        {
            a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
            if(!fst[a[i]])
                fst[a[i]]=i;
            lst[a[i]]=i;
        }
        for(int i=1;i<=n;++i)
        {
            dp[i]=1;
            if(i!=fst[a[i]])
                dp[i]=max(dp[i],dp[pre[a[i]]]+1);
            pre[a[i]]=i;
            dp[i]=max(dp[i],w[a[i]-1]+1);
            if(i>=lst[a[i]-1])
                dp[i]=max(dp[i],dp[fst[a[i]-1]]+w[a[i]-1]);
            ++w[a[i]];
            ans=max(ans,dp[i]);
        }
        cout<<n-ans<<'\n';
    }
    return 0;
}