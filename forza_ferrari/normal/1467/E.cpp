#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int lim=1e9;
vector<int> v[200001];
int n,root[200001],a[200001],cnt,dfn[200001],s[200001],tot,val[200001*60],ls[200001*60],rs[200001*60],sum[200001],ans;
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
inline void push_up(int k)
{
    val[k]=val[ls[k]]+val[rs[k]];
}
inline void update(int node,int l,int r,int &k,int p)
{
    k=++tot;
    if(l==r)
    {
        val[k]=val[p]+1;
        return;
    }
    ls[k]=ls[p];
    rs[k]=rs[p];
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls[k],ls[p]);
    else
        update(node,mid+1,r,rs[k],rs[p]);
    push_up(k);
}
inline int query(int node,int l,int r,int x,int y)
{
    if(l==r)
        return val[y]-val[x];
    int mid=(l+r)>>1;
    if(node<=mid)
        return query(node,l,mid,ls[x],ls[y]);
    return query(node,mid+1,r,rs[x],rs[y]);
}
inline void dfs1(int k,int f)
{
    s[k]=1;
    dfn[k]=++cnt;
    update(a[k],1,lim,root[cnt],root[cnt-1]);
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs1(i,k);
        s[k]+=s[i];
    }
}
inline void dfs2(int k,int f)
{
    if(query(a[k],1,lim,root[0],root[dfn[k]-1])+query(a[k],1,lim,root[dfn[k]+s[k]-1],root[n]))
    {
        update(dfn[k],1);
        update(dfn[k]+s[k],-1);
    }
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs2(i,k);
        if(query(a[k],1,lim,root[dfn[i]-1],root[dfn[i]+s[i]-1]))
        {
            update(1,1);
            update(dfn[i],-1);
            update(dfn[i]+s[i],1);
        }
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;++i)
        ans+=!query(i);
    cout<<ans<<'\n';
    return 0;
}