#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,m,a[100001],cnt,w[21],val[100001<<2],id[100001<<2],tag[100001<<2];
bool vis[100001<<2];
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
    if(vis[k])
        exit(-1);
    val[k]=min(val[ls(k)],val[rs(k)]);
}
inline void push_down(int k)
{
    if(vis[k])
    {
        vis[ls(k)]=vis[rs(k)]=1;
        tag[ls(k)]=tag[rs(k)]=0;
        val[ls(k)]=val[rs(k)]=val[k];
        id[ls(k)]=id[rs(k)]=id[k];
        vis[k]=0;
    }
    else if(tag[k])
    {
        val[ls(k)]+=tag[k];
        val[rs(k)]+=tag[k];
        if(!vis[ls(k)])
            tag[ls(k)]+=tag[k];
        if(!vis[rs(k)])
            tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        id[k]=lower_bound(w,w+cnt+1,a[l])-w;
        if(id[k]>cnt)
            exit(-1);
        val[k]=w[id[k]]-a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update1(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        tag[k]=0;
        vis[k]=1;
        id[k]=lower_bound(w,w+cnt+1,p)-w;
        if(id[k]>cnt)
            exit(-1);
        val[k]=w[id[k]]-p;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update1(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update1(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline void update2(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        if(vis[k])
        {
            val[k]-=p;
            //tag[k][0]-=p;
            while(val[k]<0)
            {
                ++id[k];
                if(id[k]>cnt)
                    exit(-1);
                //++tag[k][1];
                val[k]+=w[id[k]]-w[id[k]-1];
                //tag[k][0]+=w[id[k]]-w[id[k]-1];
            }
            return;
        }
        if(val[k]-p>=0)
        {
            val[k]-=p;
            tag[k]-=p;
            return;
        }
        if(l==r)
        {
            val[k]-=p;
            while(val[k]<0)
            {
                ++id[k];
                if(id[k]>cnt)
                    exit(-1);
                val[k]+=w[id[k]]-w[id[k]-1];
            }
            return;
        }
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update2(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update2(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int node,int l,int r,int k)
{
    if(vis[k]||l==r)
        return w[id[k]]-val[k];
    push_down(k);
    int mid=(l+r)>>1;
    if(node<=mid)
        return query(node,l,mid,ls(k));
    return query(node,mid+1,r,rs(k));
}
signed main()
{
    cnt=11;
    w[0]=1;
    for(int i=1;i<=cnt;++i)
        w[i]=42ll*w[i-1];
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(1,1,n);
    //int tot=0;
    while(m--)
    {
        //if(n>100&&++tot>=70)
            //return 0;
        int opt=read();
        if(opt==1)
            cout<<query(read(),1,n,1)<<'\n';
        if(opt==2)
        {
            int l=read(),r=read(),x=read();
            //if(tot>40&&n>100)
                //cout<<"2 "<<l<<" "<<r<<" "<<x<<'\n';
            update1(l,r,1,n,1,x);
        }
        if(opt==3)
        {
            int l=read(),r=read(),x=read();
            //if(tot>40&&n>100)
                //cout<<"3 "<<l<<" "<<r<<" "<<x<<'\n';
            update2(l,r,1,n,1,x);
            while(!val[1])
            {
                update2(l,r,1,n,1,x);
            }
        }
        /*for(int i=1;i<=n;++i)
            cout<<query(i,1,n,1)<<" ";
        cout<<'\n';*/
    }
    return 0;
}