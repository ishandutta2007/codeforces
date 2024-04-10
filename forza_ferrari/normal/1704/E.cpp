#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define int long long
const int mod=998244353;
int t,n,m,node,d[1001],a[1001],dp[1001][1001];
bool tag[1001][1001];
vector<int> v[1001];
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
inline void topo()
{
    queue<int> q;
    for(int i=1;i<=n;++i)
    {
        dp[i][0]=a[i];
        if(dp[i][0]>=mod)
        {
            dp[i][0]%=mod;
            tag[i][0]=1;
        }
        if(!d[i])
            q.emplace(i);
    }
    while(!q.empty())
    {
        int k=q.front();
        node=k;
        q.pop();
        for(int i:v[k])
        {
            for(int j=1;j<=n;++j)
            {
                dp[i][j]+=dp[k][j-1];
                tag[i][j]|=tag[k][j-1];
                if(dp[i][j]>=mod)
                {
                    tag[i][j]=1;
                    dp[i][j]%=mod;
                }
            }
            if(!--d[i])
                q.emplace(i);
        }
    }
}
signed main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        node=0;
        for(int i=1;i<=n;++i)
        {
            d[i]=a[i]=0;
            v[i].clear();
            for(int j=0;j<=n;++j)
                dp[i][j]=tag[i][j]=0;
        }
        for(int i=1;i<=n;++i)
            a[i]=read();
        for(int i=1;i<=m;++i)
        {
            int x=read(),y=read();
            v[x].emplace_back(y);
            ++d[y];
        }
        topo();
        int ans=0,sum=-1;
        bool flag=0;
        for(int i=0;i<=n;++i)
        {
            if(ans+dp[node][i]>=mod||tag[node][i])
                flag=1;
            ans=(ans+dp[node][i])%mod;
            if(ans||flag)
            {
                ans=(ans+mod-1)%mod;
                sum=i;
            }
        }
        cout<<(ans+sum+1)%mod<<'\n';
    }
    return 0;
}