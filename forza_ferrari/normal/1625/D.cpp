#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,ans,pos,a[300001],p[300001],dp[300001],tot,ch[300001*30][2],pre[300001];
pair<int,int> maxn[300001*30];
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
inline void update(int x,int id)
{
    dp[id]=1;
    vector<int> tmp;
    int node=0;
    for(int i=29;~i;--i)
    {
        if(m>>i&1^1)
        {
            if(maxn[ch[node][x>>i&1^1]].first+1>dp[id])
            {
                dp[id]=maxn[ch[node][x>>i&1^1]].first+1;
                pre[id]=maxn[ch[node][x>>i&1^1]].second;
            }
            node=ch[node][x>>i&1];
        }
        else
            node=ch[node][x>>i&1^1];
        if(!node)
            break;
    }
    if(node)
        if(maxn[node].first+1>dp[id])
        {
            dp[id]=maxn[node].first+1;
            pre[id]=maxn[node].second;
        }
    if(dp[id]>ans)
    {
        ans=dp[id];
        pos=id;
    }
    node=0;
    for(int i=29;~i;--i)
    {
        if(!ch[node][x>>i&1])
            ch[node][x>>i&1]=++tot;
        node=ch[node][x>>i&1];
        maxn[node]=max(maxn[node],{dp[id],id});
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[p[i]=i]=read();
    sort(p+1,p+n+1,[&](int x,int y){return a[x]<a[y];});
    for(int i=1;i<=n;++i)
        update(a[p[i]],p[i]);
    if(ans<=1)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<ans<<'\n';
    for(int i=pos;i;i=pre[i])
        cout<<i<<" ";
    cout<<'\n';
    return 0;
}