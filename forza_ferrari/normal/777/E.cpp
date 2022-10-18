#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
struct element
{
    int a,b,h;
    bool operator <(const element &other) const
    {
        return b^other.b? b<other.b:a<other.a;
    }
}a[100001];
int n,node[200001],cnt,maxn[200001<<2];
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
    maxn[k]=max(maxn[ls(k)],maxn[rs(k)]);
}
inline void update(int node,int l,int r,int k,int p)
{
    if(l==r)
    {
        maxn[k]=max(maxn[k],p);
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls(k),p);
    else
        update(node,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return maxn[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res=max(res,query(nl,nr,l,mid,ls(k)));
    if(nr>mid)
        res=max(res,query(nl,nr,mid+1,r,rs(k)));
    return res;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i)
        node[++cnt]=a[i].a=read(),node[++cnt]=a[i].b=read(),a[i].h=read();
    sort(node+1,node+cnt+1);
    cnt=unique(node+1,node+cnt+1)-node-1;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        a[i].a=lower_bound(node+1,node+cnt+1,a[i].a)-node;
        a[i].b=lower_bound(node+1,node+cnt+1,a[i].b)-node;
        update(a[i].b,1,cnt,1,query(a[i].a+1,a[i].b,1,cnt,1)+a[i].h);
    }
    cout<<maxn[1]<<'\n';
    return 0;
}