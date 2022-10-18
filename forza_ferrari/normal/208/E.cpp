#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to;
}e[100001];
int n,m,tot,fa[100001][21],h[100001],dep[100001],dfn[100001],cnt,s[100001],ls[100001*20],rs[100001*20],sum[100001*20],root[100001],num;
vector<int> v;
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
inline void push_up(int k)
{
    sum[k]=sum[ls[k]]+sum[rs[k]];
}
inline void update(int node,int l,int r,int &k,int p)
{
    k=++num;
    if(l==r)
    {
        sum[k]=sum[p]+1;
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
        return sum[y]-sum[x];
    int mid=(l+r)>>1;
    if(node<=mid)
        return query(node,l,mid,ls[x],ls[y]);
    return query(node,mid+1,r,rs[x],rs[y]);
}
inline void dfs(int k,int f,int deep)
{
    dep[k]=deep;
    dfn[k]=++cnt;
    s[k]=1;
    update(dep[k],1,n,root[cnt],root[cnt-1]);
    fa[k][0]=f;
    for(int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(int i=h[k];i;i=e[i].nxt)
    {
        dfs(e[i].to,k,deep+1);
        s[k]+=s[e[i].to];
    }
}
inline int find(int x,int p)
{
    for(int i=20;~i;--i)
        if(p>>i&1)
            x=fa[x][i];
    return x;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        int f=read();
        if(f)
            add(f,i);
        else
            v.emplace_back(i);
    }
    for(auto i:v)
        dfs(i,0,1);
    m=read();
    while(m--)
    {
        int x=read(),y=find(x,read());
        if(!y)
            cout<<"0 ";
        else
            cout<<query(dep[x],1,n,root[dfn[y]-1],root[dfn[y]+s[y]-1])-1<<' ';
    }
    cout<<'\n';
    return 0;
}