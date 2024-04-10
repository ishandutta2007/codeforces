#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,q,a[300001],b[300001],ans[1000001<<2],tag[1000001<<2];
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
inline void push_down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    if(tag[k])
    {
        ans[ls(k)]+=tag[k];
        ans[rs(k)]+=tag[k];
        tag[ls(k)]+=tag[k];
        tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
}
void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        ans[k]+=p;
        tag[k]+=p;
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
int query(int l,int r,int k)
{
    if(ans[k]>=0)
        return -1;
    if(l==r)
        return l;
    push_down(k,l,r);
    int mid=(l+r)>>1;
    int res=query(mid+1,r,rs(k));
    return res==-1? query(l,mid,ls(k)):res;
}
int main()
{
    n=read(),m=read();
    for(register int i=1;i<=n;++i)
        update(1,a[i]=read(),1,1e6,1,-1);
    for(register int i=1;i<=m;++i)
        update(1,b[i]=read(),1,1e6,1,1);
    q=read();
    while(q--)
    {
        int opt=read(),x=read(),val=read();
        if(opt==1)
        {
            update(1,a[x],1,1e6,1,1);
            update(1,a[x]=val,1,1e6,1,-1);
        }
        if(opt==2)
        {
            update(1,b[x],1,1e6,1,-1);
            update(1,b[x]=val,1,1e6,1,1);
        }
        printf("%d\n",query(1,1e6,1));
    }
    return 0;
}