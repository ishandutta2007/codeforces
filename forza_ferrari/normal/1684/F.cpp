#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,m,a[200001],cnt,node[200001],maxn[200001<<2],tag[200001<<2],pos[200001][2];
vector<int> v[200001];
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
    maxn[k]=max(maxn[ls(k)],maxn[rs(k)]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        maxn[ls(k)]=max(maxn[ls(k)],tag[k]);
        maxn[rs(k)]=max(maxn[rs(k)],tag[k]);
        tag[ls(k)]=max(tag[ls(k)],tag[k]);
        tag[rs(k)]=max(tag[rs(k)],tag[k]);
        tag[k]=0;
    }
}
inline void build(int k,int l,int r)
{
    maxn[k]=tag[k]=0;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        maxn[k]=max(maxn[k],p);
        tag[k]=max(tag[k],p);
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int node,int l,int r,int k)
{
    if(l==r)
        return maxn[k];
    push_down(k);
    int mid=(l+r)>>1;
    if(node<=mid)
        return query(node,l,mid,ls(k));
    return query(node,mid+1,r,rs(k));
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        build(1,1,n);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            node[i]=a[i];
        }
        sort(node+1,node+n+1);
        cnt=unique(node+1,node+n+1)-node-1;
        for(int i=1;i<=cnt;++i)
            v[i].clear();
        for(int i=1;i<=n;++i)
        {
            a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
            v[a[i]].emplace_back(i);
        }
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            update(x,y,1,n,1,y);
        }
        pos[0][0]=n+1;
        pos[0][1]=0;
        for(int i=1;i<=n;++i)
        {
            auto it=upper_bound(v[a[i]].begin(),v[a[i]].end(),i);
            int val=query(i,1,n,1);
            if(it!=v[a[i]].end()&&*it<=val)
            {
                pos[i][0]=*it;
                pos[i][1]=*prev(upper_bound(v[a[i]].begin(),v[a[i]].end(),val));
            }
            else
            {
                pos[i][0]=n+1;
                pos[i][1]=0;
            }
        }
        int ans=n,l=n+1,r=0,ed=n;
        while(pos[ed][0]>n)
            --ed;
        for(int i=1;i<=n;++i)
        {
            l=min(l,pos[i-1][0]);
            r=max(r,pos[i-1][1]);
            if(i>l)
                break;
            ans=min(ans,max(r,ed)-i+1);
        }
        cout<<max(0,ans)<<'\n';
    }
    return 0;
}