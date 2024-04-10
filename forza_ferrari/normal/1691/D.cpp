#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
#define int long long
int t,n,a[200001],pos[200001][2],maxn[200001<<2][2],sum[200001<<2];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
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
    sum[k]=sum[ls(k)]+sum[rs(k)];
    maxn[k][0]=max(maxn[ls(k)][0],sum[ls(k)]+maxn[rs(k)][0]);
    maxn[k][1]=max(maxn[rs(k)][1],sum[rs(k)]+maxn[ls(k)][1]);
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=a[l];
        maxn[k][0]=maxn[k][1]=max(a[l],0ll);
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline pair<int,int> query1(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return {maxn[k][0],sum[k]};
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query1(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query1(nl,nr,mid+1,r,rs(k));
    pair<int,int> ql=query1(nl,nr,l,mid,ls(k)),qr=query1(nl,nr,mid+1,r,rs(k));
    return {max(ql.first,ql.second+qr.first),ql.second+qr.second};
}
inline pair<int,int> query2(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return {maxn[k][1],sum[k]};
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query2(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query2(nl,nr,mid+1,r,rs(k));
    pair<int,int> ql=query2(nl,nr,l,mid,ls(k)),qr=query2(nl,nr,mid+1,r,rs(k));
    return {max(qr.first,qr.second+ql.first),ql.second+qr.second};
}
signed main()
{
    t=read();
    while(t--)
    {
        n=read();
        stack<int> t;
        for(int i=1;i<=n;++i)
        {
            a[i]=read();
            while(!t.empty()&&a[t.top()]<a[i])
            {
                pos[t.top()][1]=i;
                t.pop();
            }
            t.emplace(i);
        }
        while(!t.empty())
        {
            pos[t.top()][1]=n+1;
            t.pop();
        }
        for(int i=n;i>=1;--i)
        {
            while(!t.empty()&&a[t.top()]<=a[i])
            {
                pos[t.top()][0]=i;
                t.pop();
            }
            t.emplace(i);
        }
        while(!t.empty())
        {
            pos[t.top()][0]=0;
            t.pop();
        }
        build(1,1,n);
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            int sum=a[i];
            if(i!=1&&pos[i][0]<i-1)
                sum+=query2(pos[i][0]+1,i-1,1,n,1).first;
            if(i!=n&&pos[i][1]>i+1)
                sum+=query1(i+1,pos[i][1]-1,1,n,1).first;
            if(a[i]<sum)
            {
                flag=0;
                break;
            }
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}