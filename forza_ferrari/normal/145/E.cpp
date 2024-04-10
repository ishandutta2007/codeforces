#include<iostream>
#include<cstdio>
using namespace std;
int n,m,cnt[1000001<<2][2],ans[1000001<<2][2],a[1000001];
bool tag[1000001<<2];
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
    cnt[k][0]=cnt[ls(k)][0]+cnt[rs(k)][0];
    cnt[k][1]=cnt[ls(k)][1]+cnt[rs(k)][1];
    ans[k][0]=ans[k][1]=max(cnt[k][0],cnt[k][1]);
    ans[k][0]=max(ans[ls(k)][0]+cnt[rs(k)][1],cnt[ls(k)][0]+ans[rs(k)][0]);
    ans[k][1]=max(ans[ls(k)][1]+cnt[rs(k)][0],cnt[ls(k)][1]+ans[rs(k)][1]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        swap(cnt[ls(k)][0],cnt[ls(k)][1]);
        swap(cnt[rs(k)][0],cnt[rs(k)][1]);
        swap(ans[ls(k)][0],ans[ls(k)][1]);
        swap(ans[rs(k)][0],ans[rs(k)][1]);
        tag[ls(k)]^=1;
        tag[rs(k)]^=1;
        tag[k]=0;
    }
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        ans[k][0]=ans[k][1]=cnt[k][a[l]==7]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
    {
        swap(cnt[k][0],cnt[k][1]);
        swap(ans[k][0],ans[k][1]);
        tag[k]^=1;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k));
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k));
    push_up(k);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=getchar()^48;
        while(a[i]!=4&&a[i]!=7)
            a[i]=getchar()^48;
    }
    build(1,1,n);
    while(m--)
    {
        char opt=getchar();
        while(opt!='s'&&opt!='c')
            opt=getchar();
        if(opt=='s')
        {
            int l=read(),r=read();
            update(l,r,1,n,1);
        }
        else
            cout<<ans[1][0]<<'\n';
    }
    return 0;
}