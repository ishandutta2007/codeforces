#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,a[1000001],b[1000001],node[1000001<<1],cnt,ans[1000001<<3],tag[1000001<<3],t[1000001],T;
long long sum;
vector<int> v[1000001<<1];
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
    ans[k]=min(ans[ls(k)],ans[rs(k)]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        ans[ls(k)]+=tag[k];
        ans[rs(k)]+=tag[k];
        tag[ls(k)]+=tag[k];
        tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
}
void build(int k,int l,int r)
{
    ans[k]=tag[k]=0;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
}
void update(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        ans[k]+=p;
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
void qsort(int l,int r)
{
    if(l==r)
        return;
    int mid=(l+r)>>1;
    qsort(l,mid);
    qsort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
            t[k]=a[i],++k,++i;
        else
        {
            t[k]=a[j],++k,++j;
            sum+=mid-i+1;
        }
    }
    while(i<=mid)
        t[k]=a[i],++k,++i;
    while(j<=r)
        t[k]=a[j],++k,++j;
    for(int i=l;i<=r;i++)
        a[i]=t[i];
}
signed main()
{
    T=read();
    while(T--)
    {
        sum=0;
        cnt=0;
        n=read(),m=read();
        build(1,1,n+1);
        for(int i=1;i<=n;++i)
            node[++cnt]=a[i]=read();
        for(int i=1;i<=m;++i)
            node[++cnt]=b[i]=read();
        sort(b+1,b+m+1);
        sort(node+1,node+cnt+1);
        cnt=unique(node+1,node+cnt+1)-node-1;
        for(int i=1;i<=n;++i)
        {
            a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
            v[a[i]].push_back(i);
            update(i+1,n+1,1,n+1,1,1);
        }
        int pos1=1,pos2=1;
        for(int i=1;i<=m;++i)
        {
            b[i]=lower_bound(node+1,node+cnt+1,b[i])-node;
            while(pos1<=b[i])
            {
                for(int j:v[pos1])
                    update(j+1,n+1,1,n+1,1,-1);
                ++pos1;
            }
            while(pos2<b[i])
            {
                for(int j:v[pos2])
                    update(1,j,1,n+1,1,1);
                ++pos2;
            }
            sum+=ans[1];
        }
        qsort(1,n);
        printf("%lld\n",sum);
        for(int i=1;i<=cnt;++i)
            v[i].clear();
    }
    return 0;
}