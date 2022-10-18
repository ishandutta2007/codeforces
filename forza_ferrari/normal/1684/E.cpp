#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,a[100001],sum[100001<<2],cnt[100001<<2],tot,node[100001],val[100001],vis[100001];
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void push_up(int k)
{
    sum[k]=sum[ls(k)]+sum[rs(k)];
    cnt[k]=cnt[ls(k)]+cnt[rs(k)];
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        cnt[k]=sum[k]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int node,int l,int r,int k)
{
    if(l==r)
    {
        ++cnt[k];
        sum[k]+=l;
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls(k));
    else
        update(node,mid+1,r,rs(k));
    push_up(k);
}
inline int query1(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return 0;
    if(l>=nl&&r<=nr)
        return cnt[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query1(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res+=query1(nl,nr,mid+1,r,rs(k));
    return res;
}
inline int query2(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return 0;
    if(l>=nl&&r<=nr)
        return sum[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query2(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res+=query2(nl,nr,mid+1,r,rs(k));
    return res;
}
inline int find(int l,int r,int k,int p)
{
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    if(p<=sum[ls(k)])
        return find(l,mid,ls(k),p);
    return find(mid+1,r,rs(k),p-sum[ls(k)]);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        build(1,1,n);
        for(int i=0;i<=n;++i)
            vis[i]=0;
        tot=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(a[i]<=n)
                vis[a[i]]=1;
            node[++tot]=a[i];
        }
        vis[0]^=1;
        for(int i=1;i<=n;++i)
        {
            vis[i]^=1;
            vis[i]+=vis[i-1];
        }
        sort(node+1,node+tot+1);
        tot=unique(node+1,node+tot+1)-node-1;
        for(int i=1;i<=tot;++i)
            val[i]=0;
        for(int i=1;i<=n;++i)
        {
            a[i]=lower_bound(node+1,node+tot+1,a[i])-node;
            ++val[a[i]];
        }
        int pos=tot,minn=1e9,ans=1e9;
        for(int i=n;i>=0;--i)
        {
            while(pos>=1&&node[pos]>=i)
            {
                update(val[pos],1,n,1);
                minn=min(minn,val[pos]);
                --pos;
            }
            if(vis[i-1]>m)
                continue;
            int tmp=find(1,n,1,m);
            int rest=m-query2(1,tmp-1,1,n,1),res=query1(1,tmp-1,1,n,1)+min(query1(tmp,tmp,1,n,1),rest/tmp);
            ans=min(ans,tot-res-i+vis[i-1]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}