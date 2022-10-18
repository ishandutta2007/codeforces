#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,a[300001],pw[300001];
pair<int,int> bit[300001<<2][2];
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
inline pair<int,int> merge(pair<int,int> x,pair<int,int> y)
{
    return make_pair((x.first*pw[y.second]%mod+y.first)%mod,x.second+y.second);
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
    bit[k][0]=merge(bit[ls(k)][0],bit[rs(k)][0]);
    bit[k][1]=merge(bit[ls(k)][1],bit[rs(k)][1]);
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        bit[k][0]=bit[k][1]=make_pair(0,1);
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
void update(int node,int l,int r,int k)
{
    if(l==r)
    {
        bit[k][0].first=bit[k][1].first=1;
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls(k));
    else
        update(node,mid+1,r,rs(k));
    push_up(k);
}
pair<int,int> query1(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return bit[k][0];
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query1(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query1(nl,nr,mid+1,r,rs(k));
    return merge(query1(nl,nr,l,mid,ls(k)),query1(nl,nr,mid+1,r,rs(k)));
}
pair<int,int> query2(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return bit[k][1];
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query2(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query2(nl,nr,mid+1,r,rs(k));
    return merge(query2(nl,nr,mid+1,r,rs(k)),query2(nl,nr,l,mid,ls(k)));
}
int main()
{
    n=read();
    pw[0]=1;
    for(register int i=1;i<=n;++i)
    {
        a[i]=read();
        pw[i]=pw[i-1]*23%mod;
    }
    for(register int i=1;i<=n;++i)
    {
        update(a[i],1,n,1);
        int p=min(a[i]-1,n-a[i]);
        if(p>0&&(query1(a[i]-p,a[i]-1,1,n,1).first^query2(a[i]+1,a[i]+p,1,n,1).first))
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}