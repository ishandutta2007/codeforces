#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to;
}e[200001<<1];
int n,m,tot,h[200001],sum[2][200001],dep[200001],v[2][200001],cnt[2],id,dfn[200001],s[200001],a[200001];
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
inline void update(int x,int tag,int val)
{
    for(;x<=cnt[tag];x+=lowbit(x))
        sum[tag][x]+=val;
}
inline int query(int x,int tag)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[tag][x];
    return res;
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs(int k,int f,int deep)
{
    dep[k]=deep;
    dfn[k]=v[deep&1][++cnt[deep&1]]=++id;
    s[k]=1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,deep+1);
        s[k]+=s[e[i].to];
    }
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
    dfs(1,0,1);
    for(int i=1;i<=n;++i)
    {
        int pos=lower_bound(v[dep[i]&1]+1,v[dep[i]&1]+cnt[dep[i]&1]+1,dfn[i])-v[dep[i]&1];
        update(pos,dep[i]&1,a[i]);
        update(pos+1,dep[i]&1,-a[i]);
    }
    while(m--)
    {
        int opt=read(),x=read();
        if(opt==1)
        {
            int val=read();
            int l=lower_bound(v[dep[x]&1]+1,v[dep[x]&1]+cnt[dep[x]&1]+1,dfn[x])-v[dep[x]&1],r=upper_bound(v[dep[x]&1]+1,v[dep[x]&1]+cnt[dep[x]&1]+1,dfn[x]+s[x]-1)-v[dep[x]&1];
            update(l,dep[x]&1,val);
            update(r,dep[x]&1,-val);
            l=lower_bound(v[dep[x]&1^1]+1,v[dep[x]&1^1]+cnt[dep[x]&1^1]+1,dfn[x])-v[dep[x]&1^1],r=upper_bound(v[dep[x]&1^1]+1,v[dep[x]&1^1]+cnt[dep[x]&1^1]+1,dfn[x]+s[x]-1)-v[dep[x]&1^1];
            update(l,dep[x]&1^1,-val);
            update(r,dep[x]&1^1,val);
        }
        if(opt==2)
        {
            int pos=lower_bound(v[dep[x]&1]+1,v[dep[x]&1]+cnt[dep[x]&1]+1,dfn[x])-v[dep[x]&1];
            cout<<query(pos,dep[x]&1)<<'\n';
        }
    }
    return 0;
}