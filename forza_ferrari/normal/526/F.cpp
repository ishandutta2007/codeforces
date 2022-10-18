#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int n,x[300001],y[300001],cnt[300001<<2];
stack<int> t1,t2,t3,t4;
pair<int,int> minn[300001<<2],tag[300001<<2];
long long ans;
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
    cnt[k]=cnt[ls(k)]*(minn[k]==minn[ls(k)])+cnt[rs(k)]*(minn[k]==minn[rs(k)]);
}
inline void push_down(int k)
{
    minn[ls(k)].first+=tag[k].first;
    minn[ls(k)].second+=tag[k].second;
    minn[rs(k)].first+=tag[k].first;
    minn[rs(k)].second+=tag[k].second;
    tag[ls(k)].first+=tag[k].first;
    tag[ls(k)].second+=tag[k].second;
    tag[rs(k)].first+=tag[k].first;
    tag[rs(k)].second+=tag[k].second;
    tag[k]={0,0};
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        cnt[k]=1;
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
        minn[k].first+=p;
        tag[k].first+=p;
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
        minn[k].second+=p;
        tag[k].second+=p;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update2(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update2(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return cnt[k]*(minn[k]==make_pair(0,0));
    push_down(k);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs(k));
    return res;
}
int main()
{
    n=read();
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        x[i]=read(),y[i]=read();
        while(!t1.empty()&&x[t1.top()]<x[i])
        {
            int k=t1.top();
            t1.pop();
            if(t1.empty())
                update1(1,k,1,n,1,-x[k]);
            else
                update1(t1.top()+1,k,1,n,1,-x[k]);
        }
        if(t1.empty())
            update1(1,i,1,n,1,x[i]);
        else
            update1(t1.top()+1,i,1,n,1,x[i]);
        t1.emplace(i);
        while(!t2.empty()&&x[t2.top()]>x[i])
        {
            int k=t2.top();
            t2.pop();
            if(t2.empty())
                update1(1,k,1,n,1,x[k]);
            else
                update1(t2.top()+1,k,1,n,1,x[k]);
        }
        if(t2.empty())
            update1(1,i,1,n,1,-x[i]);
        else
            update1(t2.top()+1,i,1,n,1,-x[i]);
        t2.emplace(i);
        while(!t3.empty()&&y[t3.top()]<y[i])
        {
            int k=t3.top();
            t3.pop();
            if(t3.empty())
                update2(1,k,1,n,1,-y[k]);
            else
                update2(t3.top()+1,k,1,n,1,-y[k]);
        }
        if(t3.empty())
            update2(1,i,1,n,1,y[i]);
        else
            update2(t3.top()+1,i,1,n,1,y[i]);
        t3.emplace(i);
        while(!t4.empty()&&y[t4.top()]>y[i])
        {
            int k=t4.top();
            t4.pop();
            if(t4.empty())
                update2(1,k,1,n,1,y[k]);
            else
                update2(t4.top()+1,k,1,n,1,y[k]);
        }
        if(t4.empty())
            update2(1,i,1,n,1,-y[i]);
        else
            update2(t4.top()+1,i,1,n,1,-y[i]);
        t4.emplace(i);
        ans+=query(1,i,1,n,1);
        update1(1,i,1,n,1,-1);
        update2(1,i,1,n,1,-1);
    }
    cout<<ans<<'\n';
    return 0;
}