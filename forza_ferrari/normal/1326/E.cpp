#include<iostream>
#include<cstdio>
using namespace std;
int n,p[300001],minn[300001<<2],tag[300001<<2],ans;
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
    minn[k]=min(minn[ls(k)],minn[rs(k)]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        minn[ls(k)]+=tag[k];
        minn[rs(k)]+=tag[k];
        tag[ls(k)]+=tag[k];
        tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        minn[k]+=p;
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
        p[read()]=i;
    ans=n+1;
    for(int i=1;i<=n;++i)
    {
        while(minn[1]>=0)
            update(1,p[--ans],1,n,1,-1);
        update(1,read(),1,n,1,1);
        cout<<ans<<' ';
    }
    cout<<'\n';
    return 0;
}