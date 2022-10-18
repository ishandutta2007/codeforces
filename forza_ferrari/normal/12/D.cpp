#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct element
{
    int x,y,z;
    bool operator <(const element &other) const
    {
        return x^other.x? x>other.x:y<other.y;
    }
}a[500001];
int n,root,tot,ls[500001*30],rs[500001*30],maxn[500001*30],ans;
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
inline void push_up(int k)
{
    maxn[k]=max(maxn[ls[k]],maxn[rs[k]]);
}
inline void update(int node,int l,int r,int &k,int p)
{
    if(!k)
        k=++tot;
    if(l==r)
    {
        maxn[k]=max(maxn[k],p);
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls[k],p);
    else
        update(node,mid+1,r,rs[k],p);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return -1e9;
    if(!k)
        return -1e9;
    if(l>=nl&&r<=nr)
        return maxn[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res=max(res,query(nl,nr,l,mid,ls[k]));
    if(nr>mid)
        res=max(res,query(nl,nr,mid+1,r,rs[k]));
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        a[i].x=read();
    for(int i=1;i<=n;++i)
        a[i].y=read();
    for(int i=1;i<=n;++i)
        a[i].z=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        ans+=query(a[i].y+1,1e9,0,1e9,root)>a[i].z;
        update(a[i].y,0,1e9,root,a[i].z);
    }
    cout<<ans<<'\n';
    return 0;
}