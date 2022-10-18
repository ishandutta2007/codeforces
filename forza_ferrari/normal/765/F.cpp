#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct element
{
    int l,r,id;
    bool operator <(const element &other) const
    {
        return r<other.r;
    }
}q[300001];
int n,m,a[100001],ans[300001],val[300001<<2],minn;
vector<int> v[300001<<2];
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
    val[k]=min(val[k],min(val[ls(k)],val[rs(k)]));
}
void build(int k,int l,int r)
{
    val[k]=0x3f3f3f3f;
    for(int i=l;i<=r;++i)
        v[k].push_back(a[i]);
    sort(v[k].begin(),v[k].end());
    if(l==r)
        return;
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
}
void update(int node,int l,int r,int k,int p)
{
    if(r<=node)
    {
        int pos=lower_bound(v[k].begin(),v[k].end(),p)-v[k].begin();
        if(pos!=(int)v[k].size())
            val[k]=min(val[k],v[k][pos]-p);
        if(pos)
            val[k]=min(val[k],p-v[k][--pos]);
        if(minn<=val[k])
            return;
        if(l==r)
        {
            minn=min(minn,val[k]);
            return;
        }
    }
    int mid=(l+r)>>1;
    if(node>mid)
        update(node,mid+1,r,rs(k),p);
    update(node,l,mid,ls(k),p);
    push_up(k);
    minn=min(minn,val[k]);
}
int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return val[k];
    int mid=(l+r)>>1,res=0x3f3f3f3f;
    if(nl<=mid)
        res=min(res,query(nl,nr,l,mid,ls(k)));
    if(nr>mid)
        res=min(res,query(nl,nr,mid+1,r,rs(k)));
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(1,1,n);
    m=read();
    for(int i=1;i<=m;++i)
    {
        q[i].l=read(),q[i].r=read();
        q[i].id=i;
    }
    sort(q+1,q+m+1);
    int p=1;
    for(int i=2;i<=n;++i)
    {
        minn=0x3f3f3f3f;
        update(i-1,1,n,1,a[i]);
        while(p<=m&&q[p].r<=i)
        {
            ans[q[p].id]=query(q[p].l,q[p].r,1,n,1);
            ++p;
        }
    }
    for(int i=1;i<=m;++i)
        printf("%d\n",ans[i]);
    return 0;
}