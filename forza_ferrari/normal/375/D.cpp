#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to;
}e[100001<<1];
int n,m,tot,a[100001],h[100001],s[100001],son[100001],sum[100001],ans[100001],cnt[100001];
vector<pair<int,int> > v[100001];
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
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val)
{
    for(;x<=n;x+=lowbit(x))
        sum[x]+=val;
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
inline void dfs1(int k,int f)
{
    s[k]=1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k);
        s[k]+=s[e[i].to];
        if(s[e[i].to]>s[son[k]])
            son[k]=e[i].to;
    }
}
inline void dfs2(int k,int f)
{
    if(cnt[a[k]])
        update(cnt[a[k]],-1);
    update(++cnt[a[k]],1);
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs2(e[i].to,k);
    }
}
inline void dfs3(int k,int f)
{
    update(cnt[a[k]],-1);
    if(--cnt[a[k]])
        update(cnt[a[k]],1);
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs3(e[i].to,k);
    }
}
inline void dfs4(int k,int f)
{
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f||e[i].to==son[k])
            continue;
        dfs4(e[i].to,k);
        dfs3(e[i].to,k);
    }
    if(son[k])
        dfs4(son[k],k);
    if(cnt[a[k]])
        update(cnt[a[k]],-1);
    update(++cnt[a[k]],1);
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f||e[i].to==son[k])
            continue;
        dfs2(e[i].to,k);
    }
    for(auto i:v[k])
        ans[i.second]=query(n)-query(i.first-1);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=m;++i)
    {
        int x=read(),val=read();
        if(val<=n)
            v[x].emplace_back(val,i);
    }
    dfs1(1,0);
    dfs4(1,0);
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
    return 0;
}