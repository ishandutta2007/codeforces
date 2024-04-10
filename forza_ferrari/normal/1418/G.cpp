#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[500001],maxn[500001<<2],cnt[500001<<2],tag[500001<<2];
vector<int> v[500001];
long long ans;
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
inline void push_up(int k)
{
    if(maxn[ls(k)]==maxn[rs(k)])
        cnt[k]=cnt[ls(k)]+cnt[rs(k)];
    else if(maxn[ls(k)]>maxn[rs(k)])
        cnt[k]=cnt[ls(k)];
    else
        cnt[k]=cnt[rs(k)];
    maxn[k]=max(maxn[ls(k)],maxn[rs(k)]);
}
inline void push_down(int k)
{
    maxn[ls(k)]+=tag[k];
    maxn[rs(k)]+=tag[k];
    tag[ls(k)]+=tag[k];
    tag[rs(k)]+=tag[k];
    tag[k]=0;
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        cnt[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        maxn[k]+=p;
        tag[k]+=p;
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
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        v[i].emplace_back(0);
    for(int i=1;i<=n;++i)
        v[a[i]=read()].emplace_back(i);
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        update(i,i,1,n,1,n-1);
        int pos=lower_bound(v[a[i]].begin(),v[a[i]].end(),i)-v[a[i]].begin();
        update(v[a[i]][pos-1]+1,i-1,1,n,1,-1);
        if(pos>=3)
            update(v[a[i]][pos-3]+1,v[a[i]][pos-2],1,n,1,1);
        if(pos>=4)
            update(v[a[i]][pos-4]+1,v[a[i]][pos-3],1,n,1,-1);
        if(maxn[1]==n)
            ans+=cnt[1];
    }
    cout<<ans<<'\n';
    return 0;
}