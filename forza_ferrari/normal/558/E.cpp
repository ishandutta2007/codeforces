#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
struct element
{
    int opt,l,r;
}q[50001];
int n,m,cnt[100001<<2][3],ans[100001],a[100001];
bool tag[100001<<2][3];
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
    for(int i=0;i<3;++i)
        cnt[k][i]=cnt[ls(k)][i]+cnt[rs(k)][i];
}
inline void push_down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    for(int i=0;i<3;++i)
        if(tag[k][i])
        {
            for(int j=0;j<3;++j)
                if(i==j)
                {
                    cnt[ls(k)][j]=mid-l+1;
                    cnt[rs(k)][j]=r-mid;
                    tag[ls(k)][j]=1;
                    tag[rs(k)][j]=1;
                }
                else
                    cnt[ls(k)][j]=cnt[rs(k)][j]=tag[ls(k)][j]=tag[rs(k)][j]=0;
            tag[k][i]=0;
        }
}
inline void build(int k,int l,int r,int p)
{
    tag[k][0]=tag[k][1]=tag[k][2]=0;
    cnt[k][0]=cnt[k][1]=cnt[k][2]=0;
    if(l==r)
    {
        int val=a[l]<p? 0:a[l]==p? 1:2;
        for(int i=0;i<3;++i)
            cnt[k][i]=i==val;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid,p);
    build(rs(k),mid+1,r,p);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        for(int i=0;i<3;++i)
            if(i==p)
            {
                cnt[k][i]=r-l+1;
                tag[k][i]=1;
            }
            else
                cnt[k][i]=tag[k][i]=0;
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
inline int query(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
        return cnt[k][p];
    push_down(k,l,r);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs(k),p);
    return res;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        char c=getchar();
        while(c<'a'||c>'z')
            c=getchar();
        a[i]=c-'a';
    }
    for(int i=1;i<=m;++i)
        q[i].l=read(),q[i].r=read(),q[i].opt=read();
    for(int i=0;i<26;++i)
    {
        build(1,1,n,i);
        for(int j=1;j<=m;++j)
        {
            int tmp[3]={0};
            for(int k=0;k<3;++k)
                tmp[k]=query(q[j].l,q[j].r,1,n,1,k);
            if(q[j].opt==1)
            {
                int pos=q[j].l;
                for(int k=0;k<3;++k)
                {
                    update(pos,pos+tmp[k]-1,1,n,1,k);
                    pos+=tmp[k];
                }
            }
            else
            {
                int pos=q[j].l;
                for(int k=2;~k;--k)
                {
                    update(pos,pos+tmp[k]-1,1,n,1,k);
                    pos+=tmp[k];
                }
            }
        }
        for(int j=1;j<=n;++j)
            if(query(j,j,1,n,1,1))
                ans[j]=i;
    }
    for(int i=1;i<=n;++i)
        putchar(ans[i]+'a');
    puts("");
    return 0;
}