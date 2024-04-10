#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,dp[1000001],ans,a[1000001];
vector<int> pre[1000001],suf[1000001],g[1000001];
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
void dfs1(int k,int f)
{
    dp[k]=0;
    pre[k].push_back(0);
    suf[k].push_back(0);
    for(int i:g[k])
    {
        if(i==f)
            continue;
        dfs1(i,k);
        dp[k]=max(dp[k],dp[i]+(a[k]!=a[i]));
        pre[k].push_back(max(pre[k].back(),dp[i]+(a[k]!=a[i])));
    }
    for(int i=(int)g[k].size()-1;~i;--i)
    {
        if(g[k][i]==f)
            continue;
        suf[k].push_back(max(suf[k].back(),dp[g[k][i]]+(a[k]!=a[g[k][i]])));
    }
    reverse(suf[k].begin(),suf[k].end());
}
void dfs2(int k,int f,int tmp)
{
    if(k^1)
    {
        int sum=tmp+(a[k]!=a[f]);
        ans=min(ans,max(sum,dp[k]));
        tmp+=a[k]!=a[f];
    }
    int pos=0;
    for(int i=0;i<(int)g[k].size();++i)
    {
        if(g[k][i]==f)
            continue;
        dfs2(g[k][i],k,max(max(pre[k][pos],suf[k][pos+1]),tmp));
        ++pos;
    }
}
int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
    }
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1,0);
    ans=dp[1];
    dfs2(1,0,0);
    printf("%d\n",ans);
    return 0;
}