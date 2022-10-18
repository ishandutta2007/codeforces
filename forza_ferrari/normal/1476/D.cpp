#include<iostream>
#include<cstdio>
using namespace std;
int t,n,ql[300005<<2][2],qr[300005<<2][2],len[300005<<2],ans;
char c[300005];
struct element
{
    int q[2],len;
    element()
    {
        q[0]=q[1]=len=0;
    }
};
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
    len[k]=len[ls(k)]+len[rs(k)];
    ql[k][0]=ql[ls(k)][0];
    ql[k][1]=ql[ls(k)][1];
    qr[k][0]=qr[rs(k)][0];
    qr[k][1]=qr[rs(k)][1];
    if(ql[ls(k)][0]==len[ls(k)])
        ql[k][0]+=ql[rs(k)][len[ls(k)]&1];
    if(ql[ls(k)][1]==len[ls(k)])
        ql[k][1]+=ql[rs(k)][(len[ls(k)]&1)^1];
    if(qr[rs(k)][0]==len[rs(k)])
        qr[k][0]+=qr[ls(k)][len[rs(k)]&1];
    if(qr[rs(k)][1]==len[rs(k)])
        qr[k][1]+=qr[ls(k)][(len[rs(k)]&1)^1];
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        len[k]=1;
        ql[k][c[l]=='R']=qr[k][c[l]=='R']=1;
        ql[k][c[l]=='L']=qr[k][c[l]=='L']=0;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
element query1(int node,int l,int r,int k)
{
    if(r<=node)
    {
        element res;
        res.len=len[k];
        res.q[0]=qr[k][0];
        res.q[1]=qr[k][1];
        return res;
    }
    int mid=(l+r)>>1;
    element res,tmp;
    tmp=query1(node,l,mid,ls(k));
    if(mid<node)
        res=query1(node,mid+1,r,rs(k));
    if(!res.len&&!res.q[0]&&!res.q[1])
        return tmp;
    if(res.q[0]==res.len)
    {
        res.q[0]+=tmp.q[res.len&1];
        res.len+=tmp.len;
    }
    if(res.q[1]==res.len)
    {
        res.q[1]+=tmp.q[(res.len&1)^1];
        res.len+=tmp.len;
    }
    return res;
}
element query2(int node,int l,int r,int k)
{
    if(l>=node)
    {
        element res;
        res.len=len[k];
        res.q[0]=ql[k][0];
        res.q[1]=ql[k][1];
        return res;
    }
    int mid=(l+r)>>1;
    element res,tmp;
    tmp=query2(node,mid+1,r,rs(k));
    if(mid>=node)
        res=query2(node,l,mid,ls(k));
    if(!res.len&&!res.q[0]&&!res.q[1])
        return tmp;
    if(res.q[0]==res.len)
    {
        res.q[0]+=tmp.q[res.len&1];
        res.len+=tmp.len;
    }
    if(res.q[1]==res.len)
    {
        res.q[1]+=tmp.q[(res.len&1)^1];
        res.len+=tmp.len;
    }
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(register int i=1;i<=n;++i)
        {
            c[i]=getchar();
            if(c[i]!='L'&&c[i]!='R')
                c[i]=getchar();
        }
        build(1,1,n);
        for(register int i=1;i<=n+1;++i)
        {
            ans=1;
            if(i^1)
                ans+=query1(i-1,1,n,1).q[0];
            if(i^(n+1))
                ans+=query2(i,1,n,1).q[1];
            printf("%d ",ans);
        }
        puts("");
    }
    return 0;
}