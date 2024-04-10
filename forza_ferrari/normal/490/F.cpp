#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to;
}e[6001<<1];
int nd[6001],tot,h[6001],n,a[6001],lis[6001<<6],lds[6001<<6],ls[6001<<6],rs[6001<<6],ans,cnt_nd,cnt;
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
    lis[k]=max(lis[ls[k]],lis[rs[k]]);
    lds[k]=max(lds[ls[k]],lds[rs[k]]);
}
void merge(int x,int y,int l,int r)
{
    if(l==r)
    {
        lis[x]=max(lis[x],lis[y]);
        lds[x]=max(lds[x],lds[y]);
        return;
    }
    ans=max(ans,max(lis[ls[x]]+lds[rs[y]],lis[ls[y]]+lds[rs[x]]));
    int mid=(l+r)>>1;
    if(ls[y])
    {
        if(ls[x])
            merge(ls[x],ls[y],l,mid);
        else
            ls[x]=ls[y];
    }
    if(rs[y])
    {
        if(rs[x])
            merge(rs[x],rs[y],mid+1,r);
        else
            rs[x]=rs[y];
    }
    push_up(x);
}
void update1(int node,int l,int r,int &k,int p)
{
    if(!k)
        k=++cnt;
    if(l==r)
    {
        lis[k]=max(lis[k],p);
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update1(node,l,mid,ls[k],p);
    else
        update1(node,mid+1,r,rs[k],p);
    push_up(k);
}
void update2(int node,int l,int r,int &k,int p)
{
    if(!k)
        k=++cnt;
    if(l==r)
    {
        lds[k]=max(lds[k],p);
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update2(node,l,mid,ls[k],p);
    else
        update2(node,mid+1,r,rs[k],p);
    push_up(k);
}
int query1(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return 0;
    if(!k)
        return 0;
    if(l>=nl&&r<=nr)
        return lis[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res=max(res,query1(nl,nr,l,mid,ls[k]));
    if(nr>mid)
        res=max(res,query1(nl,nr,mid+1,r,rs[k]));
    return res;
}
int query2(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return 0;
    if(!k)
        return 0;
    if(l>=nl&&r<=nr)
        return lds[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res=max(res,query2(nl,nr,l,mid,ls[k]));
    if(nr>mid)
        res=max(res,query2(nl,nr,mid+1,r,rs[k]));
    return res;
}
void dfs(int k,int f)
{
    update1(a[k],1,cnt_nd,k,query1(1,a[k]-1,1,cnt_nd,k)+1);
    update2(a[k],1,cnt_nd,k,query2(a[k]+1,cnt_nd,1,cnt_nd,k)+1);
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
        merge(k,e[i].to,1,cnt_nd);
        update1(a[k],1,cnt_nd,k,query1(1,a[k]-1,1,cnt_nd,k)+1);
        update2(a[k],1,cnt_nd,k,query2(a[k]+1,cnt_nd,1,cnt_nd,k)+1);
    }
    ans=max(ans,max(lis[k],lds[k]));
}
int main()
{
    n=read();
    for(register int i=1;i<=n;++i)
        nd[i]=a[i]=read();
    sort(nd+1,nd+n+1);
    cnt_nd=unique(nd+1,nd+n+1)-nd-1;
    for(register int i=1;i<=n;++i)
        a[i]=lower_bound(nd+1,nd+cnt_nd+1,a[i])-nd;
    for(register int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    cnt=n;
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}