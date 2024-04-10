#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
#define int long long
int n,m,w[100005],g[100005],pre[100005],suf[100005],st[100005],top,a[100005<<2],b[100005<<2],sum[100005<<2],tag[100005<<2],ans;
vector<int> v[100005];
stack<int> t;
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
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void push_down(int k)
{
    sum[ls(k)]-=tag[k];
    sum[rs(k)]-=tag[k];
    b[ls(k)]+=tag[k];
    b[rs(k)]+=tag[k];
    tag[ls(k)]+=tag[k];
    tag[rs(k)]+=tag[k];
    tag[k]=0;
}
inline int calc(int l,int r,int k,int val)
{
    if(l==r)
        return a[k]-val;
    push_down(k);
    int mid=(l+r)>>1;
    if(val>b[ls(k)])
        return min(calc(l,mid,ls(k),val),sum[k]);
    return min(a[ls(k)]-val,calc(mid+1,r,rs(k),val));
}
inline void push_up(int k,int l,int r)
{
    a[k]=min(a[ls(k)],a[rs(k)]);
    b[k]=min(b[ls(k)],b[rs(k)]);
    int mid=(l+r)>>1;
    sum[k]=calc(mid+1,r,rs(k),b[ls(k)]);
    //cout<<l<<" "<<r<<" "<<sum[k]<<'\n';
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        a[k]=b[k]=suf[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k,l,r);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        sum[k]-=p;
        b[k]+=p;
        tag[k]+=p;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k,l,r);
}
inline int query1(int l,int r,int k,int p)
{
    if(l==r)
        return a[k]<=p? l:0;
    push_down(k);
    int mid=(l+r)>>1;
    if(a[rs(k)]<=p)
        return query1(mid+1,r,rs(k),p);
    return query1(l,mid,ls(k),p);
}
inline int query2(int l,int r,int k,int val)
{
    //cout<<l<<" "<<r<<" "<<k<<" "<<val<<'\n';
    if(l==r)
        return a[k]-val<=m? l:0;
    push_down(k);
    int mid=(l+r)>>1;
    if(val>b[ls(k)])
        return sum[k]<=m? query2(mid+1,r,rs(k),b[ls(k)]):query2(l,mid,ls(k),val);
    int res=query2(mid+1,r,rs(k),val);
    if(res)
        return res;
    return query1(l,mid,ls(k),m+val);
}
inline void dfs(int k,int f)
{
    st[++top]=k;
    if(f<=n)
        update(f-1,n,1,n,1,pre[k]-pre[f]);
    if(k<=n)
    {
        int l=2,r=top-1,mid,pos=1;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(pre[st[mid]]-pre[k]>m)
            {
                pos=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        pos=st[pos]-1;
        update(1,k-1,1,n,1,1e15);
        update(pos,n,1,n,1,-1e15);
        ans=max(ans,query2(1,n,1,1e15)-k+1);
        update(1,k-1,1,n,1,-1e15);
        update(pos,n,1,n,1,1e15);
    }
    for(int i:v[k])
        dfs(i,k);
    if(f<=n)
        update(f-1,n,1,n,1,pre[f]-pre[k]);
    --top;
}
signed main()
{
    ans=1;
    n=read(),m=read();
    for(int i=2;i<=n;++i)
        w[i]=read();
    for(int i=1;i<=n;++i)
    {
        g[i]=read();
        if(i>1)
        {
            pre[i]=pre[i-1]+w[i]-g[i-1];
            suf[i]=suf[i-1]+w[i]-g[i];
        }
    }
    pre[n+1]=1e18;
    t.emplace(n+1);
    for(int i=n;i>=1;--i)
    {
        while(pre[t.top()]<=pre[i])
            t.pop();
        v[t.top()].emplace_back(i);
        //cout<<t.top()<<" "<<i<<'\n';
        t.emplace(i);
    }
    build(1,1,n);
    dfs(n+1,n+1);
    cout<<ans<<'\n';
    return 0;
}